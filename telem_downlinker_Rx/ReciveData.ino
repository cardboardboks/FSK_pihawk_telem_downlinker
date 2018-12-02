void ReciveData(char x) {
  char incomingByte;

  if (Serial.available()) {
    incomingByte = Serial.read();
  }

  if (incomingByte == 65) {
    bits ^= 1;
    LATF = (Serial.parseFloat());
    LATR = (Serial.parseFloat());
    CheckSum = Serial.parseInt();
    //    Serial.print(LATF);
    //    Serial.print(LATR);
    //    Serial.print(CheckSum);
    CheckSumCal(incomingByte, LATF);
  }
  else if (incomingByte == 66) {
    bits ^= 2;
    LONF = (Serial.parseInt());
    LONR = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    //    Serial.print(LONF);
    //    Serial.print(LONR);
    //    Serial.print(CheckSum);
    CheckSumCal(incomingByte, LONF);
  }
  else if  (incomingByte == 67) {
    bits ^= 4;
    AltI = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, AltI);
  }
  else if  (incomingByte == 68) {
    bits ^= 8;
    Course = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Course);
  }
  else if  (incomingByte == 69) {
    bits ^= 16;
    VoltI  = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, VoltI);
  }
  else if  (incomingByte == 70) {
    bits ^= 32;
    SpeedI = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, SpeedI);
  }
  else if  (incomingByte == 71) {
    bits ^= 64;
    CurrentI = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, CurrentI);
  }
  else if  (incomingByte == 72) {
    bits ^= 128;
    BatP = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, BatP);
  }
  else if  (incomingByte == 73) {
    bits ^= 256;
    Sat  = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Sat);
  }
  else if  (incomingByte == 74) {
    bits ^= 512;
    Rssi = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Rssi);
  }
  else if  (incomingByte == 75) {
    bits ^= 1024;
    Mode  = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Mode);
  }
  else if  (incomingByte == 76) {
    bits ^= 2048;
    State = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, State);
  }
  else if  (incomingByte == 77) {
    bits ^= 4096;
    Spare = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Spare );
  }
  else if  (incomingByte == 78) {
    bits ^= 8192;
    Msg = (Serial.parseInt());
    CheckSum = Serial.parseInt();
    CheckSumCal(incomingByte, Msg);
  }


  if (trigger == 1) {
    if (pass == 1) {
      Lcd(5);
      unsigned long currentMillis = millis();
      unsigned long messFreqT  = (currentMillis - previousMillis);
      previousMillis = currentMillis;
      if (messFreq < 60500) {
        messFreq = messFreqT;
      }

      Volt = ((float)VoltI) / 10;
      Current = ((float)CurrentI) / 100;
      Alt = ((float)AltI) / 10;
      Speed = ((float)SpeedI) / 10;
      Lat = IntToFloat(LATF, LATR);
      Lon = IntToFloat(LONF, LONR);

      Lcd(3);


      if (x == 1) {
        if (LogSD == 0) {
          SdWriteLog();
        }
        Lcd(4);
      }
    }
    bits = 0;
    trigger = 0;
  }
}

void CheckSumCal(int x, int y) {
  // Serial.print("\t");
  if ((x + y) == CheckSum) {
    pass = 1;
    //    Serial.println("pass");
  } else {
    pass = 0;
    //    Serial.println("fail");
  }


  trigger = 1;
}

float IntToFloat(int F, int R) {

  char neg = 1;
  int FC1 = F;
  int FC2 = F;
  float c;

  FC1 /= 10;

  FC2 -= FC1 * 10;

  F -= FC2;

  if (FC2 == 0) {
    neg = -1;
  }

  c = (float)F / 100;

  c = ((float)R / 100000) + c;

  c *= neg;
  //  Serial.println(c, 5);
  return c;
}

