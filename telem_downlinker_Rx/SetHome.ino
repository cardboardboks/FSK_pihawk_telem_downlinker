void SetHome() {
  int counter = 0;

  oled1.clear();
  oled2.clear();

  oled2.setCursor (28, 0);
  oled2.print(F("-Set Home-"));

  oled2.setCursor (0, 2);
  oled2.print(F("Pos:"));
  oled2.setCursor (60, 2);
  oled2.print(F("Ang:"));
  oled2.setCursor (0, 6);
  oled2.print(F("Message Age: "));

  while (true) {
    ReciveData(0);
    GPSCalc();
    Lcd(5);

    oled2.setCursor (0, 4);
    if (Sat > 0) {
      oled2.print(F("Waiting for Input.."));
    } else {
      oled2.print(F("Waiting for Data..."));
    }

    if (digitalRead(4) == LOW && Lat == 0) {
      counter ++;
      if (counter > 200) {
        oled2.clear();
        oled2.setCursor (0, 0);
        oled2.print(F("Logging  Without"));
        oled2.setCursor (0, 2);
        oled2.print(F("Tracking!!"));
        tracking = 1;
        delay(2000);
        break;
      }
    }
    if (digitalRead(4) == LOW && latch == 0 && Lat != 0 && HLat == 0) {
      latch = 1;
      HLat = Lat;
      HLon = Lon;
      HAlt = Alt;

      //      Serial.println();
      //      Serial.print(F("Home\t \t \t Lat, Lon, Alt"));
      //      tab();
      //      Serial.print(HLat, 5);
      //      tab();
      //      Serial.print(HLon, 5);
      //      tab();
      //      Serial.println(HAlt, 1);

      oled2.setCursor (30, 2);
      oled2.print(F("Set!"));
    }
    if (digitalRead(4) == LOW && latch == 0 && HLat != 0 && offSetM == -1) {
      offSetM = Angle;

      //      Serial.print(F("Aircraft\t \t Lat, Lon, Alt"));
      //      tab();
      //      Serial.print(Lat, 5);
      //      tab();
      //      Serial.print(Lon, 5);
      //      tab();
      //      Serial.println(Alt, 1);
      //      Serial.print(F("Home Angle Offest"));
      //      tab();
      //      Serial.print(F(" "));
      //      Serial.println(offSetM);
      //      Serial.println();

      oled2.setCursor (90, 2);
      oled2.print(F("Set!"));
      oled2.setCursor (0, 4);
      oled2.print(F("Angle Offest "));

      if (offSetM > 99) {
      } else if (offSetM > 9) {
        Space(2);
      } else {
        Space(2);
        Space(2);
      }
      oled2.print(offSetM, 1);
      Space(2);
      Space(2);

      delay(2000);

    }
    if (digitalRead(4) == HIGH) {
      counter = 0;
      latch = 0;
      if (offSetM != -1) {
        break;
      }
    }
  }
}

void tab() {
  Serial.print("\t");
}
