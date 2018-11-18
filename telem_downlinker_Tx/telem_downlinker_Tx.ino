#include <SoftwareSerial.h>
#include "mavlink\mavlink.h"

SoftwareSerial SoftSerial(3, 2);

int LATI = 0;
int LONI = 0;
int LATF1 = 0;
int LONF1 = 0;
int LATF2 = 0;
int LONF2 = 0;

float Lat = 0;
float Lon = 0;
int Alt = 0;
int Speed = 0;
int Course = 0;
int Volt = 5;
int Current = 7;
int Rssi = 20;
int BatP = 23;
int Sat = 0;
int State = 33;
int Mode = 66;
int CheckSum = 0;

int dataPacket = 0;

bool newData = false;

unsigned long previousMillis = 0;
const long interval = 200;

void setup() {
  Serial.begin(115200);
  Serial1.begin(38400);
  SoftSerial.begin(1200);
}

void loop() {
  comm_receive();

  //  if (Serial1.available()) {
  //    Serial.write(Serial1.read());
  //  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Constrain();
    flotToInt();
    //debug();
    SendData();
  }
}





