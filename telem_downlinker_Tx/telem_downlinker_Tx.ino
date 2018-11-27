#include <SoftwareSerial.h>
#include "mavlink\mavlink.h"

SoftwareSerial SoftSerial(3, 2);

const int numReadings = 33;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total

int LATI = 0;
int LONI = 0;
int LATF1 = 0;
int LONF1 = 0;
int LATF2 = 0;
int LONF2 = 0;

int Fix = 0;
float Lat = 0;
float Lon = 0;
int Alt = 0;
int Speed = 0;
int Course = 0;
int Volt = 0;
int Current = 0;
int Rssi = 0;
int BatP = 0;
int Sat = 0;
int State = 0;
int Mode = 0;
int Msg = 0;
int Spare = 0;
int CheckSum = 0;
float MsgOld = 0;
float MsgNew = 0;
float Time = 0;

int dataPacketH = 2;
int dataPacketL = 0;

bool newData = false;

unsigned long previousMillis = 0;
const long interval = 120;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  SoftSerial.begin(2400);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {

  comm_receive();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    MsgAge();
    Constrain();
    flotToInt();
    //debug();
    SendData();
  }
}





