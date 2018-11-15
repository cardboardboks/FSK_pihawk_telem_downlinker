void SdClose() {

  int counter = 0;

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print(F("Save Files"));
  delay(1000);

  trackFile.println(F("</coordinates>\n</LineString>\n</Placemark>\n</Document>\n</kml>\n"));

  trackFile.close();
  telemFile.close();

  lcd.setCursor (0, 2);
  lcd.print(trackName);
  lcd.setCursor (0, 1);
  lcd.print(telemName);
  lcd.setCursor (0, 3);
  delay(1000);
  lcd.print(F("Saved"));
  while (true) {
    if (digitalRead(4) == LOW && latch == 0) {
      counter++;
      Serial.println(counter);
      if (counter > 100) {
        latch = 1;
        lcd.clear();
        Lcd(3);
        Lcd(4);
        lcd.setCursor (14, 3);
        lcd.print(F("LstLog"));
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


