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
  oled2.setCursor (0, 4);
  oled2.print(F("Wating for Data..."));
  oled2.setCursor (0, 6);
  oled2.print(F("Message Age: "));

  while (true) {
    ReciveData(0);
    GPSCalc();
    Lcd(5);
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

      Serial.println();
      Serial.print("Home\t \t \t Lat, Lon, Alt");
      Serial.print("\t");
      Serial.print(HLat, 5);
      Serial.print("\t");
      Serial.print(HLon, 5);
      Serial.print("\t");
      Serial.println(HAlt);

      oled2.setCursor (30, 2);
      oled2.print(F("Set!"));
    }
    if (digitalRead(4) == LOW && latch == 0 && HLat != 0 && offSetM == -1) {
      offSetM = Angle;

      Serial.print("Aircraft\t \t Lat, Lon, Alt");
      Serial.print("\t");
      Serial.print(Lat, 5);
      Serial.print("\t");
      Serial.print(Lon, 5);
      Serial.print("\t");
      Serial.println(Alt);
      Serial.print("Home Angle Offest");
      Serial.print("\t");
      Serial.print(" ");
      Serial.println(offSetM);
      Serial.println();

      oled2.setCursor (90, 2);
      oled2.print(F("Set!"));
    }
    if (digitalRead(4) == HIGH) {
      counter = 0;
      latch = 0;
      if (offSetM != -1) {
        delay(2000);
        break;
      }
    }
  }
}
