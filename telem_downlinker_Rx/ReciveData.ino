void ReciveData(char x) {
  int incomingByte = 32;

  if (Serial.available()) {
    incomingByte = Serial.read();
  }

  if (incomingByte == 65) {
    LatLon();
    AltI = (Serial.parseInt());
    Course = Serial.parseInt();
    CheckSum = Serial.parseInt();
    CheckSumCal(AltI, Course);
  }
  if (incomingByte == 86) {
    LatLon();
    VoltI = Serial.parseInt();
    CurrentI = Serial.parseInt();
    CheckSum = Serial.parseInt();
    CheckSumCal(VoltI, CurrentI);
  }
  if (incomingByte == 82) {
    LatLon();
    Rssi = Serial.parseInt();
    BatP = Serial.parseInt();
    CheckSum = Serial.parseInt();
    CheckSumCal(Rssi, BatP);
  }
  if (incomingByte == 83) {
    LatLon();
    Sat = Serial.parseInt();
    Speed = Serial.parseInt();
    CheckSum = Serial.parseInt();
    CheckSumCal(Sat, Speed);
  }
  if (incomingByte == 79) {
    LatLon();
    State = Serial.parseInt();
    Mode = Serial.parseInt();
    CheckSum = Serial.parseInt();
    CheckSumCal(State, Mode);
  }

  if (trigger == 1) {
    if (pass == 1) {
      count++;
      unsigned long currentMillis = millis();
      unsigned long messFreqT  = (currentMillis - previousMillis);
      previousMillis = currentMillis;
      if (messFreq < 60500) {
        messFreq = messFreqT;
      }

      Volt = ((float)VoltI) / 1000;
      Current = ((float)CurrentI) / 100;
      Alt = ((float)AltI) / 10;

      Lat = IntToFloat(LATI, LATF1, LATF2);
      Lon = IntToFloat(LONI, LONF1, LONF2);

      Lcd(3);

      if (x == 1) {
        if (LogSD == 0) {
          SdWriteLog();
        }
        Lcd(4);
      }
    }
    trigger = 0;
  }
}

void LatLon() {
  LATI = Serial.parseInt();
  LATF1 = Serial.parseInt();
  LATF2 = Serial.parseInt();
  LONI = Serial.parseInt();
  LONF1 = Serial.parseInt();
  LONF2 = Serial.parseInt();
}

void CheckSumCal(int x, int y) {
  if ((LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + x + y) == CheckSum) {
    pass = 1;
  } else {
    pass = 0;
  }
  trigger = 1;
}

float IntToFloat(int I, int F1, int F2) {

  char neg = 0;
  float c;

  if (I < 0) {
    neg = -1;
    I *= neg;
  }

  c = (float)F2;
  for (int i = 0; i < 3; i++) {
    c *= .1f;
  }
  c = (float)F1 + c;
  for (int i = 0; i < 2; i++) {
    c *= .1f;
  }
  c = (float)I + c;
  if (neg == -1) {
    c *= neg;
  }
  return c;
}

