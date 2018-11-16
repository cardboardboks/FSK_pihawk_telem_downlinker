void Lcd(char x) {

  if (x == 3) {
    oled1.setCursor(0, 4);
    oled1.print(F("Lat:"));
    oled1.print(Lat, 5);

    oled2.setCursor(70, 2);
    oled2.print(F(" Sat:"));
    if (Sat < 10) {
      Space(2);
    }
    oled2.print(Sat);

    oled1.setCursor(0, 6);
    oled1.print(F("Lon:"));
    oled1.print(Lon, 5);

    int AltD = Alt - HAlt;
    oled1.setCursor(0, 2);
    oled1.print(F("Alt:"));
    if (AltD > 99) {
    } else if (AltD > 9) {
      Space(1);
    } else if (AltD >= 0) {
      Space(1);
      Space(1);
    } else if (AltD < -9) {
    } else if (AltD < 0) {
      Space(1);
    }
    oled1.print(AltD);
    oled1.print(F("M"));
  }

  if (x == 4) {
    if (tracking == 0) {
      oled1.setCursor(65, 2);;
      oled1.print(F("  Dst:"));
      if (Range < 10000) {
        if (Range > 999) {
          Space(1);
        } else if (Range > 99) {
          Space(1);
          Space(1);
        } else if (Range > 10) {
          Space(1);
          Space(1);
          Space(1);
        } else {
          Space(1);
          Space(1);
          Space(1);
          Space(1);
        }
        oled1.print(Range, 0);
      } else {
        oled1.print((Range / 1000), 1);
        oled1.print(F("K"));
      }
      oled1.print(F("M"));
    } else {
      oled1.print(F("ASL  No Trk"));
    }

    oled1.setCursor (0, 0);
    oled1.print(F("Crs:"));
    if (Course > 99) {
    } else if (Course > 9) {
      Space(1);
    } else {
      Space(1);
      Space(1);
    }
    oled1.print(Course);
    oled1.print((char)223);

    oled2.setCursor(0, 6);
    oled1.print(F("Log:"));
    if (LogSD == 0) {
      if (count > 99999) {
      } else if (count > 9999) {
        Space(1);
      } else if (count > 999) {
        Space(1);
        Space(1);
      } else if (count > 99) {
        Space(1);
        Space(1);
        Space(1);
      } else if (count > 9) {
        Space(1);
        Space(1);
        Space(1);
        Space(1);
      } else {
        Space(1);
        Space(1);
        Space(1);
        Space(1);
        Space(1);
      }
      oled1.print(count);
    } else {
      oled1.print("No Log");
    }
  }




  if (x == 5) {
    oled2.setCursor (90, 6);
    unsigned long currentMillis = millis();
    messFreq = (currentMillis - previousMillis);
    if (messFreq > 60000) {
      if (messFreq / 60000 < 10) {
        Space(2);
      }
      oled2.print(messFreq / 60000);
      oled2.print(F("min"));
    } else if (messFreq > 9999) {
      oled2.print(messFreq);
    } else if (messFreq > 999) {
      oled2.print(F("0"));
      oled2.print(messFreq);
    } else if (messFreq > 99) {
      oled2.print(F("00"));
      oled2.print(messFreq);
    }    else if (messFreq > 9) {
      oled2.print(F("000"));
      oled2.print(messFreq);
    }
  }
}
void Space(int L) {
  if (L == 1) {
    oled1.print(F(" "));
  }
  if (L == 2) {
    oled2.print(F(" "));
  }
}
