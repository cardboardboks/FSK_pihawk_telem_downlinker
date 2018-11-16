void FileInt() {

  oled1.clear();
  oled1.setCursor (0, 0);
  oled1.print(F("Init Files"));

  const uint8_t KML_BASE_NAME_SIZE = sizeof(KML_BASE_NAME) - 1;
  char  trackFileName[13] = KML_BASE_NAME "000.kml";

  const uint8_t CSV_BASE_NAME_SIZE = sizeof(CSV_BASE_NAME) - 1;
  char  telemFileName[13] = CSV_BASE_NAME "000.csv";

  while (sd.exists(trackFileName)) {
    if (trackFileName[KML_BASE_NAME_SIZE + 2] != '9') {
      trackFileName[KML_BASE_NAME_SIZE + 2]++;
    }
    else if (trackFileName[KML_BASE_NAME_SIZE + 1] != '9') {
      trackFileName[KML_BASE_NAME_SIZE + 2] = '0';
      trackFileName[KML_BASE_NAME_SIZE + 1]++;
    }
    else  if (trackFileName[KML_BASE_NAME_SIZE] != '9') {
      trackFileName[KML_BASE_NAME_SIZE + 2] = '0';
      trackFileName[KML_BASE_NAME_SIZE + 1] = '0';
      trackFileName[KML_BASE_NAME_SIZE]++;
    }
  }


  while (sd.exists(telemFileName)) {
    if (telemFileName[CSV_BASE_NAME_SIZE + 2] != '9') {
      telemFileName[CSV_BASE_NAME_SIZE + 2]++;
    }
    else if (telemFileName[CSV_BASE_NAME_SIZE + 1] != '9') {
      telemFileName[CSV_BASE_NAME_SIZE + 2] = '0';
      telemFileName[CSV_BASE_NAME_SIZE + 1]++;
    }
    else  if (telemFileName[CSV_BASE_NAME_SIZE] != '9') {
      telemFileName[CSV_BASE_NAME_SIZE + 2] = '0';
      telemFileName[CSV_BASE_NAME_SIZE + 1] = '0';
      telemFileName[CSV_BASE_NAME_SIZE]++;
    }
  }
  if (!trackFile.open(trackFileName, O_CREAT | O_WRITE | O_EXCL)) {
  }
  if (!telemFile.open(telemFileName, O_CREAT | O_WRITE | O_EXCL)) {
  }

  writeHeader();

  trackName = trackFileName;
  telemName = telemFileName;

  oled1.setCursor (0, 1);
  oled1.print(F("Made File:"));

  oled1.setCursor (0, 3);
  oled1.print(trackName);

  oled1.setCursor (0, 2);
  oled1.print(telemName);

  count = 0;
  delay(2000);
}

