void SdWriteLog() {

  if (dataPacket == 0) {
    DateTime now = rtc.now();
    telemFile.print(now.minute(), DEC);
    telemFile.print(':');
    telemFile.print(now.second(), DEC);
    comma();
  }
  if (dataPacket == 1) {
    telemFile.print(Lat, 5);
    comma();
    telemFile.print(Lon, 5);
    comma();
  }
  if (dataPacket == 2) {
    telemFile.print(Alt, 1);
    comma();
    telemFile.print(Course);
    comma();
  }
  if (dataPacket == 3) {
    telemFile.print(Volt, 2);
    comma();
    telemFile.print(Current, 2);
    comma();
  }
  if (dataPacket == 4) {
    telemFile.print(Rssi);
    comma();
    telemFile.print(BatP);
    comma();
  }
  if (dataPacket == 5) {
    telemFile.print(Sat);
    comma();
    telemFile.print(Speed, 1);
    comma();
  }
  if (dataPacket == 6) {
    telemFile.print(State);
    comma();
    telemFile.print(Mode);
    comma();
  }
  if (dataPacket == 7) {
    telemFile.print(Msg);
    comma();
    telemFile.println(Spare);
  }
  if (dataPacket < 7) {
    dataPacket++;
  } else {
    dataPacket = 0;
  }

  if ( (dataPacket % 2) == 0) {
    trackFile.print(Lon, 5);
    trackFile.print(F(","));
    trackFile.print(Lat, 5);
    trackFile.print(F(","));
    trackFile.println(Alt, 1);
  }

}
void comma() {
  telemFile.print(F(","));
}

