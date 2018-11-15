#include <SPI.h>
#include <Wire.h>
#include <SdFat.h>
#include <Servo.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>

Servo panServo;
Servo tiltServo;

// SD chip select pin.
const uint8_t SD_CHIP_SELECT = 10;

// File system object.
SdFat sd;

// Log file.
SdFile trackFile;
SdFile telemFile;

// Log file base name.  Must be six characters or less.
#define KML_BASE_NAME "Track"
#define CSV_BASE_NAME "Telem"

String trackName;
String telemName;

// Define I2C Address for LCD
#define I2C_ADDR    0x27
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

const char telemHeader[] PROGMEM  = {"lat,lon,Alt,Crs,Vlt,Cur,RSSI,Pckt,Sat,Spd,Spr0,Spr1\n"};
const char trackHeaderA[] PROGMEM  = {"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>\n<name>Flight Path</name>\n<Style id=\"line\">\n<LineStyle>\n<color>7f00ffff</color>\n<width>1</width>\n</LineStyle>\n<PolyStyle>\n<color>7f00ff00</color>\n</PolyStyle>\n</Style>\n<Placemark>\n<LookAt>\n<longitude>"};
const char trackHeaderB[] PROGMEM  = {"</latitude>\n<tilt>45</tilt>\n<range>2000</range>\n</LookAt>\n<styleUrl>#line</styleUrl>\n<LineString>\n<extrude>1</extrude>\n<tessellate>1</tessellate>\n<altitudeMode>absolute</altitudeMode>\n<coordinates>\n"};

int k;
char myChar;

int servD = 10;

int LATI = 0;
int LONI = 0;
int LATF1 = 0;
int LONF1 = 0;
int LATF2 = 0;
int LONF2 = 0;

int HAlt = 0;
float HLat = 0;
float HLon = 0;
float Lat = 0;
float Lon = 0;
float Range = 0;
float Volt = 0;
float Current = 0;
float Speed = 0;

float Angle = 0;
float offSet = 0;
float offSetM = -1;
float panAngle = 0;
float tiltAngle = 0;

int Alt = 0;
int Course = 0;
int VoltI = 0;
int CurrentI = 0;
int Rssi = 0;
int Packet = 0;
byte Sat = 0;
int SpeedI = 0;
int Spare0 = 0;
int Spare1 = 0;
int CheckSum = 0;
int CheckSumT = 0;

int panServoMin = 1000;
int panServoMid = 1500;
int panServoMax = 2000;
int panServoRange = 90;
int tiltServoMin = 1000;
int tiltServoMid = 1500;
int tiltServoMax = 2000;
int tiltServoRange = 90;
int panServoRate = 5;
int tiltServoRate = 5;

int panMsC = 1500;
int tiltMsC = 1500;

int panMs = panServoMid;
int tiltMs = tiltServoMid;

char LogSD = 0;
char tracking = 0;
char latch = 0;
char trigger = 0;
char pass = 0;
unsigned long messFreq = 0;
unsigned long count = 0;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(1200);

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);

  lcd.begin (20, 4);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE); // init the backlight
  lcd.setBacklight(HIGH);

  ServoSetup();
  //LoadSettings();
  panServo.attach(8);
  tiltServo.attach(9);
  panServo.writeMicroseconds(panServoMid);
  tiltServo.writeMicroseconds(tiltServoMid);
  SetHome();
}

void loop() {

  SdInt();
  lcd.clear();


  while (true) {
    //    if (Serial.available()) {
    //      Serial.write(Serial.read());
    //    }
    ReciveData(1);
    Lcd(5);
    if (tracking == 0) {
      Servos();
    }
    if (digitalRead(4) == LOW && latch == 0) {
      latch = 1;
      break;
    }
    if (digitalRead(4) == HIGH) {
      latch = 0;
    }
  }
  if (LogSD == 0) {
    SdClose();
  }
}
