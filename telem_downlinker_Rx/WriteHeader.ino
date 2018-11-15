void writeHeader() {

  int len1 = strlen_P(telemHeader);
  for (k = 0; k < len1; k++)
  {
    myChar =  pgm_read_byte_near(telemHeader + k);
    telemFile.print(myChar);
  }

  int len2 = strlen_P(trackHeaderA);
  for (k = 0; k < len2; k++)
  {
    myChar =  pgm_read_byte_near(trackHeaderA + k);
    trackFile.print(myChar);
  }

  trackFile.print(Lon, 5);
  trackFile.print(F("</longitude>\n<latitude>"));
  trackFile.print(Lat, 5);

  int len3 = strlen_P(trackHeaderB);
  for (k = 0; k < len3; k++)
  {
    myChar =  pgm_read_byte_near(trackHeaderB + k);
    trackFile.print(myChar);
  }
}











