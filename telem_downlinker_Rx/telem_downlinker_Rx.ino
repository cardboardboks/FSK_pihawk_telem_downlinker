#include <SPI.h>
#include <Wire.h>
#include "SdFat.h"
#include <Servo.h>
#include "RTClib.h"
#include <EEPROM.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

Servo panServo;
Servo tiltServo;

RTC_DS1307 rtc;

#define I2C_ADDRESS1 0x3C
#define I2C_ADDRESS2 0x3D

SSD1306AsciiWire oled1;
SSD1306AsciiWire oled2;

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

<<<<<<< HEAD
const char telemHeader[] PROGMEM  = {"Time,lat,lon,Alt,Crs,Vlt,Cur,RSSI,Pckt,Sat,Spd,Spr0,Spr1\n"};
=======
const char telemHeader[] PROGMEM  = {"lat,lon,Alt,Crs,Vlt,Cur,RSSI,BatP,Sat,Spd,State,Mode,Msg,Spare\n"};
>>>>>>> master
const char trackHeaderA[] PROGMEM  = {"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>\n<name>Flight Path</name>\n<Style id=\"line\">\n<LineStyle>\n<color>7f00ffff</color>\n<width>1</width>\n</LineStyle>\n<PolyStyle>\n<color>7f00ff00</color>\n</PolyStyle>\n</Style>\n<Placemark>\n<LookAt>\n<longitude>"};
const char trackHeaderB[] PROGMEM  = {"</latitude>\n<tilt>45</tilt>\n<range>2000</range>\n</LookAt>\n<styleUrl>#line</styleUrl>\n<LineString>\n<extrude>1</extrude>\n<tessellate>1</tessellate>\n<altitudeMode>absolute</altitudeMode>\n<coordinates>\n"};

int k;
char myChar;

int servD = 10;
int clear = 0;

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
float Alt = 0;
float Range = 0;
float Volt = 0;
float Current = 0;

float Angle = 0;
float offSet = 0;
float offSetM = -1;
float panAngle = 0;
float tiltAngle = 0;

int AltI = 0;
int Course = 0;
int VoltI = 0;
int CurrentI = 0;
int Rssi = 0;
int BatP = 0;
byte Sat = 0;
int Speed = 0;
int State = 0;
int Mode = 0;
int Msg = 0;
int Spare = 0;
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
  Wire.begin();
  Wire.setClock(400000L);

  oled1.begin(&Adafruit128x64, I2C_ADDRESS1);
  oled2.begin(&Adafruit128x64, I2C_ADDRESS2);

  oled1.setFont(X11fixed7x14);
  oled2.setFont(X11fixed7x14);

  pinMode(3, INPUT);
  pinMode(4, INPUT);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);

  //ServoSetup();
  //LoadSettings();
  panServo.attach(8);
  tiltServo.attach(9);
  panServo.writeMicroseconds(panServoMid);
  tiltServo.writeMicroseconds(tiltServoMid);
  SetHome();
}

void loop() {

  SdInt();
  oled1.clear();
  oled2.clear();

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
