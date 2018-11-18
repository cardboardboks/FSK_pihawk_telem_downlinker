void SdWriteLog() {

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
  trackFile.print(",");
  trackFile.print(Lat, 6);
  trackFile.print(",");
  trackFile.println(Alt);

}
void comma() {
  telemFile.print(",");
}

