void SdClose() {

  int counter = 0;

  oled1.clear();
  oled1.setCursor (0, 0);
  oled1.print(F("Save Files"));
  delay(1000);

  trackFile.println(F("</coordinates>\n</LineString>\n</Placemark>\n</Document>\n</kml>\n"));

  trackFile.close();
  telemFile.close();

  oled1.setCursor (0, 4);
  oled1.print(trackName);
  oled1.setCursor (0, 2);
  oled1.print(telemName);
  oled1.setCursor (0, 6);
  delay(1000);
  oled1.print(F("Saved"));
  while (true) {
    if (digitalRead(4) == LOW && latch == 0) {
      counter++;
      //   Serial.println(counter);
      if (counter > 100) {
        latch = 1;
        oled1.clear();
        Lcd(3);
        Lcd(4);
        oled2.setCursor (85, 6);
        oled2.print(F("LstLog"));
        while (true) {
          if (digitalRead(4) == HIGH) {
            latch = 0;
          }
          if (digitalRead(4) == LOW && latch == 0) {
            latch = 1;
            goto End;
          }
        }
      }
    }
    if (digitalRead(4) == HIGH) {
      latch = 0;
      if ( counter > 10) {
        goto End;
      }
    }
  }
End:
  delay(10);
}


