void SdSize() {

  uint32_t volTotal;
  uint32_t volFree;
  float fs;
  float ts;

  volTotal = sd.vol()->clusterCount();

  volFree = sd.vol()->freeClusterCount();

  fs = 0.000512 * volFree * sd.vol()->blocksPerCluster();

  ts = 0.000512 * volTotal * sd.vol()->blocksPerCluster();

  oled1.setCursor (0, 2);
  oled1.print(F("Total MB  Free MB"));
  oled1.setCursor (0, 3);
  oled1.print(ts, 2);
  oled1.print(F("MB"));
  oled1.setCursor (10, 3);
  oled1.print(fs, 2);
  oled1.print(F("MB"));
  delay(5000);
}

