void Lcd(char x) {

  if (messFreq > 10000 && clear == 0) {
    oled1.clear();
    oled2.clear();
    clear = 1;
  }

  if (messFreq < 10000) {
    clear = 0;
  }

  if (x == 3) {

    oled1.setCursor(0, 4);
    oled1.print(F("Lat:"));
    oled1.print(Lat, 5);

    oled1.setCursor(0, 6);
    oled1.print(F("Lon:"));
    oled1.print(Lon, 5);

    oled1.setCursor(83, 2);
    oled1.print(F("Sat:"));
    if (Sat < 10) {
      Space(1);
    }
    oled1.print(Sat);

    oled1.setCursor(0, 2);
    oled1.print(F("Alt:"));
    if (Alt > 99) {
    } else if (Alt - HAlt > 9) {
      Space(1);
    } else if (Alt - HAlt >= 0) {
      Space(1);
      Space(1);
    } else if (Alt - HAlt < -9) {
    } else if (Alt - HAlt < 0) {
      Space(1);
    }
    oled1.print(Alt - HAlt, 1);
    oled1.print(F("m"));

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

    oled1.setCursor(55, 0);
    oled1.print("Spd:");
    if (Speed > 99) {
    } else if (Speed > 9) {
      Space(1);
    } else if (Speed >= 0) {
      Space(1);
      Space(1);
    }
    oled1.print(Speed);
    oled1.print("kph");

    oled1.setCursor(100, 4);
    if (Mode == 0) {
      oled1.print(" Man");
    }    if (Mode == 1) {
      oled1.print(" Cir");
    }    if (Mode == 2) {
      oled1.print("Stab");
    }    if (Mode == 4) {
      oled1.print("Acro");
    }    if (Mode == 5) {
      oled1.print("FBWA");
    }    if (Mode == 6) {
      oled1.print("FBWB");
    }    if (Mode == 7) {
      oled1.print("Crse");
    }    if (Mode == 8) {
      oled1.print("Attn");
    }    if (Mode == 10) {
      oled1.print("Auto");
    }    if (Mode == 11) {
      oled1.print(" RTL");
    }    if (Mode == 12) {
      oled1.print("Loit");
    }

    oled1.setCursor(100, 6);
    if (State >= 128) {
      oled1.print(" Arm");
    } else {
      oled1.print("Darm");
    }

  }

  if (x == 4) {

    oled2.setCursor(0, 0);
    oled2.print("Vlt:");
    if (Volt < 10) {
      oled2.print(Volt, 2);
    } else {
      oled2.print(Volt, 1);
    }
    oled2.print("v");

    oled2.setCursor(0, 2);
    oled2.print("Bat:");
    if (BatP > 99) {
    } else if (BatP > 9) {
      Space(2);
    } else {
      Space(2);
      Space(2);
    }
    oled2.print(BatP);
    oled2.print("%");

    oled2.setCursor(0, 4);
    oled2.print("Lnk:");
    if (Rssi > 99) {
    } else if (Rssi > 9) {
      Space(2);
    } else {
      Space(2);
      Space(2);
    }
    oled2.print(Rssi);
    oled2.print("%");

    oled2.setCursor(70, 0);
    oled2.print("Cur:");
    if (Current < 9) {
      oled2.print(Current, 1);
    } else {
      oled2.print(Current, 0);
    }
    oled2.print("A");

    oled2.setCursor(65, 4);
    oled2.print("Msg:");
    if (Msg == 1) {
      Space(2);
      Space(2);
      oled2.print("New");
    } else {
      Space(2);
      Space(2);
      oled2.print("Old");
    }


    oled2.setCursor(65, 2);
    if (tracking == 0) {
      oled2.print(F("Dst:"));
      if (Range < 1000) {
        if (Range > 999) {

        } else if (Range > 99) {

          Space(2);
        } else if (Range > 10) {
          Space(2);

          Space(2);
        } else {
          Space(2);

          Space(2);
          Space(2);
        }
        oled2.print(Range, 0);
      } else {
        oled2.print((Range / 1000), 1);
        oled2.print(F("K"));
      }
      oled2.print(F("m"));
    } else {
      Space(2);
      Space(2);
      oled2.print(F("No Trk"));
    }

    oled2.setCursor(0, 6);
    oled2.print(F("Log:"));
    if (LogSD == 0) {
      if (count > 99999) {
      } else if (count > 9999) {
        Space(2);
      } else if (count > 999) {
        Space(2);
        Space(2);
      } else if (count > 99) {
        Space(2);
        Space(2);
        Space(2);
      } else if (count > 9) {
        Space(2);
        Space(2);
        Space(2);
        Space(2);
      } else {
        Space(2);
        Space(2);
        Space(2);
        Space(2);
        Space(2);
      }
      oled2.print(count);
    } else {
      oled2.print("No Log");
    }
  }

  if (x == 5) {
    oled2.setCursor (92, 6);
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
