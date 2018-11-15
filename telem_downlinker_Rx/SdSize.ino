void SdSize() {

  uint32_t volTotal;
  uint32_t volFree;
  float fs;
  float ts;

  volTotal = sd.vol()->clusterCount();

  volFree = sd.vol()->freeClusterCount();

  fs = 0.000512 * volFree * sd.vol()->blocksPerCluster();

  ts = 0.000512 * volTotal * sd.vol()->blocksPerCluster();

  lcd.setCursor (0, 2);
  lcd.print(F("Total MB  Free MB"));
  lcd.setCursor (0, 3);
  lcd.print(ts, 2);
  lcd.print(F("MB"));
  lcd.setCursor (10, 3);
  lcd.print(fs, 2);
  lcd.print(F("MB"));
  delay(5000);
}

