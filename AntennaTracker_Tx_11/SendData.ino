void SendData() {

  if (dataPacket == 0) {
    SoftSerial.print("A");
    LatLon();
    SoftSerial.print(Alt);
    SoftSerial.print(",");
    SoftSerial.print(Course);
    SoftSerial.print(",");
    CheckSumCal(Alt, Course);
    SoftSerial.print("\n");
  }
  if (dataPacket == 1) {
    SoftSerial.print("V");
    LatLon();
    SoftSerial.print(Volt);
    SoftSerial.print(",");
    SoftSerial.print(Current);
    SoftSerial.print(",");
    CheckSumCal(Volt, Current);
    SoftSerial.print("\n");
  }
  if (dataPacket == 2) {
    SoftSerial.print("R");
    LatLon();
    SoftSerial.print(Rssi);
    SoftSerial.print(",");
    SoftSerial.print(Packet);
    SoftSerial.print(",");
    CheckSumCal(Rssi, Packet);
    SoftSerial.print("\n");
  }
  if (dataPacket == 3) {
    SoftSerial.print("S");
    LatLon();
    SoftSerial.print(Sat);
    SoftSerial.print(",");
    SoftSerial.print(Speed);
    SoftSerial.print(",");
    CheckSumCal(Sat, Speed);
    SoftSerial.print("\n");
  }
  if (dataPacket == 4) {
    SoftSerial.print("O");
    LatLon();
    SoftSerial.print(Spare0);
    SoftSerial.print(",");
    SoftSerial.print(Spare1);
    SoftSerial.print(",");
    CheckSumCal(Spare0, Spare1);
    SoftSerial.print("\n");
  }

  if (dataPacket < 4) {
    dataPacket++;
  } else {
    dataPacket = 0;
  }
}

void LatLon() {
  SoftSerial.print(LATI);
  SoftSerial.print(",");
  SoftSerial.print(LATF1);
  SoftSerial.print(",");
  SoftSerial.print(LATF2);
  SoftSerial.print(",");
  SoftSerial.print(LONI);
  SoftSerial.print(",");
  SoftSerial.print(LONF1);
  SoftSerial.print(",");
  SoftSerial.print(LONF2);
  SoftSerial.print(",");
}

void CheckSumCal(int x, int y) {
  SoftSerial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + x + y);
}


