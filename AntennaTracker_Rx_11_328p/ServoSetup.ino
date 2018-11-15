void ServoSetup() {
  if (digitalRead(4) == LOW) {
    Serial.println("Servo Setup int");
    latch = 1;
    lcd.clear();
    lcd.setCursor (1, 1);
    lcd.print(F("-Servo Setup Mode-"));
    lcd.setCursor (2, 2);
    lcd.print(F("Please use Setup"));
    lcd.setCursor (6, 3);
    lcd.print(F("Software"));

    while (true) {

      if (digitalRead(4) == HIGH) {
        latch = 0;
      }
      if (digitalRead(4) == LOW && latch == 0) {
        latch = 1;
        SaveSettings();
        lcd.setCursor (3, 0);
        lcd.print(F("-Setup  Saved-"));
        delay(2500);
        break;
      }

    }
  }
}

