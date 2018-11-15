void FileInt() {

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print(F("Init Files"));

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

  lcd.setCursor (0, 1);
  lcd.print(F("Made File:"));

  lcd.setCursor (0, 3);
  lcd.print(trackName);

  lcd.setCursor (0, 2);
  lcd.print(telemName);

  count = 0;
  delay(2000);
}

