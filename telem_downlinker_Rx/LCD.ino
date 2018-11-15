void Lcd(char x) {

  if (x == 3) {
    lcd.setCursor (0, 2);
    lcd.print(F("Lat:"));
    lcd.print(Lat, 5);

    lcd.print(F(" Sat:"));
    if (Sat < 10) {
      Space();
    }
    lcd.print(Sat);

    lcd.setCursor (0, 3);
    lcd.print(F("Lon:"));
    lcd.print(Lon, 5);

    int AltD = Alt - HAlt;
    lcd.setCursor (0, 1);
    lcd.print(F("Alt:"));
    if (AltD > 99) {
    } else if (AltD > 9) {
      Space();
    } else if (AltD >= 0) {
      Space();
      Space();
    } else if (AltD < -9) {
    } else if (AltD < 0) {
      Space();
    }
    lcd.print(AltD);
    lcd.print(F("M"));
  }

  if (x == 4) {
    if (tracking == 0) {
      lcd.print(F("  Dst:"));
      if (Range < 10000) {
        if (Range > 999) {
          Space();
        } else if (Range > 99) {
          Space();
          Space();
        } else if (Range > 10) {
          Space();
          Space();
          Space();
        } else {
          Space();
          Space();
          Space();
          Space();
        }
        lcd.print(Range, 0);
      } else {
        lcd.print((Range / 1000), 1);
        lcd.print(F("K"));
      }
      lcd.print(F("M"));
    } else {
      lcd.print(F(" ASL  No Trk"));
    }

    lcd.setCursor (0, 0);
    lcd.print(F("Crs:"));
    if (Course > 99) {
    } else if (Course > 9) {
      Space();
    } else {
      Space();
      Space();
    }
    lcd.print(Course);
    lcd.print((char)223);


    lcd.print(F("  Log:"));
    if (LogSD == 0) {
      if (count > 99999) {
      } else if (count > 9999) {
        Space();
      } else if (count > 999) {
        Space();
        Space();
      } else if (count > 99) {
        Space();
        Space();
        Space();
      } else if (count > 9) {
        Space();
        Space();
        Space();
        Space();
      } else {
        Space();
        Space();
        Space();
        Space();
        Space();
      }
      lcd.print(count);
    } else {
      lcd.print("No Log");
    }
  }




  if (x == 5) {
    lcd.setCursor (15, 3);
    unsigned long currentMillis = millis();
    messFreq = (currentMillis - previousMillis);
    if (messFreq > 5400000) {
      lcd.print(F("9min+"));
    } else if (messFreq > 60000) {
      lcd.print(messFreq / 60000);
      lcd.print(F("min+"));
    } else if (messFreq > 9999) {
      lcd.print(messFreq);
    } else if (messFreq > 999) {
      lcd.print(F("0"));
      lcd.print(messFreq);
    } else if (messFreq > 99) {
      lcd.print(F("00"));
      lcd.print(messFreq);
    }    else if (messFreq > 9) {
      lcd.print(F("000"));
      lcd.print(messFreq);
    }
  }
}
void Space() {
  lcd.print(F(" "));
}
