void SdWriteLog() {

  DateTime now = rtc.now();

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
  telemFile.print(now.second(), DEC);
  comma();
  telemFile.print(Lat, 6);
  comma();
  telemFile.print(Lon, 6);
  comma();
  telemFile.print(Alt);
  comma();
  telemFile.print(Course);
  comma();
  telemFile.print(Volt, 2);
  comma();
  telemFile.print(Current, 2);
  comma();
  telemFile.print(Rssi);
  comma();
  telemFile.print(BatP);
  comma();
  telemFile.print(Sat);
  comma();
  telemFile.print(Speed, 1);
  comma();
  telemFile.print(State);
  comma();
  telemFile.print(Mode);
  comma();
  telemFile.print(Msg);
  comma();
  telemFile.println(Spare);

  trackFile.print(Lon, 6);
  trackFile.print(F(","));
  trackFile.print(Lat, 6);
  trackFile.print(F(","));
  trackFile.println(Alt);

}
void comma() {
  telemFile.print(F(","));
}

