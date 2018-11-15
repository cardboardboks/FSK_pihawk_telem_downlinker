void  SdInt() {
reInt:
  int counter = 0;


  lcd.clear();

  // initialize the SD card at SPI_HALF_SPEED
  lcd.setCursor (0, 0);
  lcd.print(F("Init SD Card"));
  lcd.setCursor (0, 1);

  if (!sd.cardBegin(SD_CHIP_SELECT, SPI_HALF_SPEED)) {
    lcd.print(F("Init failed!"));
    lcd.setCursor (0, 2);
    lcd.print(F("No Card?"));
    lcd.setCursor (0, 3);
    lcd.print(F("Try Again?"));
    while (true) {
      if (digitalRead(4) == LOW) {
        counter++;
        if (counter > 200) {
          lcd.clear();
          lcd.setCursor (2, 1);
          lcd.print(F("Running  Without"));
          lcd.setCursor (6, 2);
          lcd.print(F("Logging!"));
          LogSD = 1;
          goto passInt;
        }
      }
      if (digitalRead(4) == HIGH && counter > 1) {
        counter = 0;
        goto reInt;
      }
    }
    return;
  } else {
    LogSD = 0;
    lcd.print(F("Card Found"));
    delay(2000);
  }

  uint32_t ocr;
  if (!sd.card()->readOCR(&ocr)) {
    return;
  }
  if (!sd.fsBegin()) {
    return;
  }

  SdSize();
  FileInt();

passInt:

  delay(2000);
}

