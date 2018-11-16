void ServoSetup() {
  if (digitalRead(4) == LOW) {
    Serial.println("Servo Setup int");
    latch = 1;
    oled1.clear();
    oled1.setCursor (1, 1);
    oled1.print(F("-Servo Setup Mode-"));
    oled1.setCursor (2, 2);
    oled1.print(F("Please use Setup"));
    oled1.setCursor (6, 3);
    oled1.print(F("Software"));

    while (true) {

      if (digitalRead(4) == HIGH) {
        latch = 0;
      }
      if (digitalRead(4) == LOW && latch == 0) {
        latch = 1;
        SaveSettings();
        oled1.setCursor (3, 0);
        oled1.print(F("-Setup  Saved-"));
        delay(2500);
        break;
      }

    }
  }
}

