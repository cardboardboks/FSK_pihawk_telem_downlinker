void ReciveData(char x) {
  char incomingByte;

  if (Serial.available()) {
    incomingByte = Serial.read();
  }

  if (incomingByte == 65) {
    bits += 1;
    LATS = (Serial.parseFloat());
    //  LATI = atol(LATS);
    Serial.print(LATS);
    CheckSumCal(incomingByte, Lat);
  }
  //
  //  else if (incomingByte == 66) {
  //    bits += 2;
  //    AltI = (Serial.parseInt());
  //    Course = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    VoltI = Serial.parseInt();
  //    CurrentI = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    CheckSumCal(VoltI, CurrentI);
  //  }  else if (incomingByte == 67) {
  //    bits += 4;
  //    SpeedI = Serial.parseInt();
  //    BatP = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    CheckSumCal(SpeedI, BatP);
  //  }  else if  (incomingByte == 68) {
  //    bits += 8;
  //    Sat = Serial.parseInt();
  //    Rssi = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    CheckSumCal(Sat, Rssi);
  //  }  else if  (incomingByte == 69) {
  //    bits += 16;
  //    State = Serial.parseInt();
  //    Mode = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    CheckSumCal(State, Mode);
  //  }  else if  (incomingByte == 70) {
  //    bits += 32;
  //    Msg = Serial.parseInt();
  //    Spare = Serial.parseInt();
  //    CheckSum = Serial.parseInt();
  //    CheckSumCal(Msg, Spare);
  //  } else if  (incomingByte == 71) {
  //
  //  } else if  (incomingByte == 72) {
  //
  //  } else if  (incomingByte == 73) {
  //
  //  } else if  (incomingByte == 74) {
  //
  //  } else if  (incomingByte == 75) {
  //
  //  } else if  (incomingByte == 76) {
  //
  //  } else if  (incomingByte == 77) {
  //
  //  } else if  (incomingByte == 78) {
  //
  //  }
  //

  if (trigger == 1) {
    if (pass == 1) {
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
  Serial.print("\t");
  if ((x + y) == CheckSum) {
    pass = 1;
    Serial.println("pass");
  } else {
    pass = 0;
    Serial.println("fail");
  }


  trigger = 1;
}
