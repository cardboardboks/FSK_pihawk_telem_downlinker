void writeHeader() {

  DateTime now = rtc.now();

  telemFile.print(F("Date/Time"));
  telemFile.print(F(","));
  telemFile.print(now.year(), DEC);
  telemFile.print('/');
  telemFile.print(now.month(), DEC);
  telemFile.print('/');
  telemFile.print(now.day(), DEC);
  telemFile.print(F(" "));
  telemFile.print(now.hour(), DEC);
  telemFile.print(':');
  telemFile.print(now.minute(), DEC);
  telemFile.print(':');
  telemFile.println(now.second(), DEC);

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











