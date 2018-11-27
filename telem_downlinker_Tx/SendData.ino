void SendData() {

  if (dataPacketH == 0) {
    SoftSerial.print("A");
    LatLon();
    SoftSerial.print(Alt);
    SoftSerial.print(",");
    SoftSerial.print(Course);
    SoftSerial.print(",");
    CheckSumCal(Alt, Course);
    SoftSerial.print("\n");
  }
  if (dataPacketH == 1) {
    SoftSerial.print("V");
    LatLon();
    SoftSerial.print(Volt);
    SoftSerial.print(",");
    SoftSerial.print(Current);
    SoftSerial.print(",");
    CheckSumCal(Volt, Current);
    SoftSerial.print("\n");
  }
  if (dataPacketH == 2) {
    SoftSerial.print("R");
    LatLon();
    SoftSerial.print(Speed);
    SoftSerial.print(",");
    SoftSerial.print(BatP);
    SoftSerial.print(",");
    CheckSumCal(Speed, BatP);
    SoftSerial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 0) {
    SoftSerial.print("S");
    LatLon();
    SoftSerial.print(Sat);
    SoftSerial.print(",");
    SoftSerial.print(Rssi);
    SoftSerial.print(",");
    CheckSumCal(Sat, Rssi);
    SoftSerial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 1) {
    SoftSerial.print("O");
    LatLon();
    SoftSerial.print(State);
    SoftSerial.print(",");
    SoftSerial.print(Mode);
    SoftSerial.print(",");
    CheckSumCal(State, Mode);
    SoftSerial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 2) {
    SoftSerial.print("X");
    LatLon();
    SoftSerial.print(Msg);
    SoftSerial.print(",");
    SoftSerial.print(Spare);
    SoftSerial.print(",");
    CheckSumCal(Msg, Spare);
    SoftSerial.print("\n");
  }

    if (dataPacketH < 3) {
      dataPacketH++;
    } else {
      dataPacketH = 0;
    }
    if (dataPacketL < 2) {
      dataPacketL++;
    } else {
      dataPacketL = 0;
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


