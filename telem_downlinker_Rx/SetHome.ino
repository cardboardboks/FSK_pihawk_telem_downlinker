void SetHome() {
  int counter = 0;

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print(F("Set Home  Pos:"));
  lcd.setCursor (10, 1);
  lcd.print(F("Ang:"));
  lcd.setCursor (0, 2);
  lcd.print(F("Wating"));
  lcd.setCursor (0, 3);
  lcd.print(F("for Data..."));

  while (true) {
    ReciveData(0);
    GPSCalc();
    Lcd(5);
    if (digitalRead(4) == LOW && Lat == 0) {
      counter ++;
      if (counter > 200) {
        lcd.clear();
        lcd.setCursor (2, 1);
        lcd.print(F("Logging  Without"));
        lcd.setCursor (5, 2);
        lcd.print(F("Tracking!!"));
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

      lcd.setCursor (15, 0);
      lcd.print(F("Set!"));
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

      lcd.setCursor (15, 1);
      lcd.print(F("Set!"));
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
