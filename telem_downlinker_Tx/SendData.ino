void SendData() {

  if (dataPacketH == 1) {
    SoftSerial.print("A");
    SoftSerial.println(LATI);
    SoftSerial.println(LATF1);
    SoftSerial.print(LATF2);
  }
  if (dataPacketH == 2) {
    SoftSerial.print("A");
    SoftSerial.println(LONI);
    SoftSerial.println(LONF1);
    SoftSerial.print(LONF2);
  }
  if (dataPacketH == 3) {
    SoftSerial.print("A");
    SoftSerial.println(Alt);
    SoftSerial.print(Course);
  }
  if (dataPacketH == 4) {
    SoftSerial.print("V");
    SoftSerial.println(Volt);
    SoftSerial.print(Current);
  }
  if (dataPacketH == 5) {
    SoftSerial.print("R");
    SoftSerial.println(Speed);
    SoftSerial.print(BatP);
  }
  if (dataPacketH == 6 && dataPacketL == 0) {
    SoftSerial.print("S");
    SoftSerial.println(Sat);
    SoftSerial.print(Rssi);
  }
  if (dataPacketH == 6 && dataPacketL == 1) {
    SoftSerial.print("O");
    SoftSerial.println(State);
    SoftSerial.print(Mode);
  }
  if (dataPacketH == 6 && dataPacketL == 2) {
    SoftSerial.print("X");
    SoftSerial.println(Msg);
    SoftSerial.print(Spare);
  }

  if (dataPacketH < 6) {
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


