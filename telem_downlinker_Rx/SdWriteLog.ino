void SdWriteLog() {

  telemFile.print(Lat, 5);
  comma();
  telemFile.print(Lon, 5);
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
  telemFile.print(Packet);
  comma();
  telemFile.print(Sat);
  comma();
  telemFile.print(Speed, 1);
  comma();
  telemFile.print(Spare0);
  comma();
  telemFile.println(Spare1);

  trackFile.print(Lon, 5);
  trackFile.print(",");
  trackFile.print(Lat, 5);
  trackFile.print(",");
  trackFile.println(Alt);

}
void comma() {
  telemFile.print(",");
}

