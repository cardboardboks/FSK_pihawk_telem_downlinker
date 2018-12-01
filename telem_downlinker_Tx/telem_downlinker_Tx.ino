#include <SoftwareSerial.h>
#include "mavlink\mavlink.h"

SoftwareSerial SoftSerial(3, 2);

const int messageFreq = 7;

float hFreqIntervalRatio = 60;
float mFreqIntervalRatio = 25;
float lFreqIntervalRatio = 15;

byte hFreqIntervalRatioCount = 0;
byte mFreqIntervalRatioCount = 0;
byte lFreqIntervalRatioCount = 0;

byte LatP = 2;
byte LonP = 2;

byte AltP = 1;
byte SpeedP = 1;
byte CourseP = 1;
byte VoltP = 1;
byte CurrentP = 1;

byte FixP = 0;
byte RssiP = 0;
byte BatPP = 0;
byte SatP = 0;
byte StateP = 0;
byte ModeP = 0;
byte SpareP = 0;

byte Fix = 0;
long Lat = 0;
long Lon = 0;
int Alt = 0;
int Speed = 0;
int Course = 0;
int Volt = 0;
int Current = 0;
int Rssi = 0;
int BatP = 0;
byte Sat = 0;
int State = 0;
int Mode = 0;
int Spare = 0;

int CheckSum = 0;

int Msg = 0;
float MsgOld = 0;
float MsgNew = 0;
float Time = 0;

int dataPacketH = 0;
int dataPacketM = 0;
int dataPacketL = 0;

bool newData = false;

int bits = 0;

unsigned long milold1 = 0;
unsigned long milold2 = 0;
unsigned long milold3 = 0;
unsigned long milold4 = 0;
unsigned long milold5 = 0;

unsigned long sendIntervalMillis = 0;
long sendInterval;

unsigned long hFreqMillis = 0;
long hFreqInterval;

unsigned long mFreqMillis = 0;
long mFreqInterval;

unsigned long lFreqMillis = 0;
long lFreqInterval;

const int buffReadings = 10;    // the readings from the analog input
long buff[buffReadings];        // the readings from the analog input
byte buffIndex = 0;              // the index of the current reading

const int numReadings = 33;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total

void setup() {
  Serial.begin(115200);
  Serial1.begin(500000);
  SoftSerial.begin(2400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  for (int thisReading = 0; thisReading < buffReadings; thisReading++) {
    buff[thisReading] = 0;
  }

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

  MFC();

}

void loop() {

  CommReceive();
  RingBuffer();

  MsgAge();
  Constrain();
  //debug();

  RingBuffer();

  if ( millis() - sendIntervalMillis >= sendInterval) {
    sendIntervalMillis =  millis();
    // SendData();
  }
}





