void  SdInt() {
reInt:
  int counter = 0;


  oled1.clear();

  // initialize the SD card at SPI_HALF_SPEED
  oled1.setCursor (0, 0);
  oled1.print(F("Init SD Card"));
  oled1.setCursor (0, 1);

  if (!sd.cardBegin(SD_CHIP_SELECT, SPI_HALF_SPEED)) {
    oled1.print(F("Init failed!"));
    oled1.setCursor (0, 2);
    oled1.print(F("No Card?"));
    oled1.setCursor (0, 3);
    oled1.print(F("Try Again?"));
    while (true) {
      if (digitalRead(4) == LOW) {
        counter++;
        if (counter > 200) {
          oled1.clear();
          oled1.setCursor (2, 1);
          oled1.print(F("Running  Without"));
          oled1.setCursor (6, 2);
          oled1.print(F("Logging!"));
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
    oled1.print(F("Card Found"));
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

