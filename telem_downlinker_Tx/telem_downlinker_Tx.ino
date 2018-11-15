#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(3, 2);

uint8_t gps_config0[14] = {0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00, 0x01, 0x00, 0xDE, 0x6A};
uint8_t gps_config1[8] = {0xB5, 0x62, 0x06, 0x08, 0x00, 0x00, 0x0E, 0x30  };

// The TinyGPS++ object
TinyGPSPlus gps;

int LATI = 0;
int LONI = 0;
int LATF1 = 0;
int LONF1 = 0;
int LATF2 = 0;
int LONF2 = 0;

float Lat = 174.830000;
float Lon = -41.090000;
int Alt = 0;
int Speed = 0;
int Course = 0;
int Volt = 5;
int Current = 7;
int Rssi = 20;
int Packet = 23;
int Sat = 0;
int Spare0 = 33;
int Spare1 = 66;
int CheckSum = 0;

int dataPacket = 0;

bool newData = false;

unsigned long previousMillis = 0;
const long interval = 200;

void setup() {
  Serial.begin(115200);
  Serial1.begin(38400);
  SoftSerial.begin(1200);

  delay(2000);
  Serial1.write(gps_config0, sizeof(gps_config0));
  Serial1.write(gps_config1, sizeof(gps_config1));
  delay(1000);
}

void loop() {

  //  if (Serial1.available()) {
  //    Serial.write(Serial1.read());
  //  }

  TinyGPS();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (gps.location.isValid()) {
      if (newData) {
        Constrain();
        flotToInt();
        //debug();
        SendData();
      }
    }
  }
}





