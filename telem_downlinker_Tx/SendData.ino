void SendData() {


  



  if (dataPacketH == 2 && bits & 64) {
    bits -= 64;
    SoftSerial.print("C");
    SoftSerial.println(Alt);
  } else if (dataPacketH == 2) {
    dataPacketH++;
  }
  if (dataPacketH == 3 && bits & 128) {
    bits -=  128;
    SoftSerial.print("D");
    SoftSerial.println(Course);
  } else if (dataPacketH == 3) {
    dataPacketH++;
  }
  if (dataPacketH == 4 && bits & 256) {
    bits -=  256;
    SoftSerial.print("E");
    SoftSerial.println(Volt);
  } else if (dataPacketH == 4) {
    dataPacketH++;
  }
  if (dataPacketH == 5 && bits & 4) {
    bits -=  4;
    SoftSerial.print("F");
    SoftSerial.println(Speed);
  } else if (dataPacketH == 5) {
    dataPacketH++;
  }
  if (dataPacketH == 6 && bits & 512) {
    bits -=  512;
    SoftSerial.print("G");
    SoftSerial.println(Current);
  } else if (dataPacketH == 6) {
    dataPacketH++;
  }



  if (dataPacketH == 7 && bits & 1024) {
    bits -=  1024;
    SoftSerial.print("H");
    SoftSerial.println(BatP);
  } else if (dataPacketH == 7) {
    dataPacketH++;
  }
  if (dataPacketH == 8  && bits & 8) {
    bits -=  8;
    SoftSerial.print("I");
    SoftSerial.println(Sat);
  } else if (dataPacketH == 8) {
    dataPacketH++;
  }
  if (dataPacketH == 9 && bits & 2048) {
    bits -=  2048;
    SoftSerial.print("J");
    SoftSerial.println(Rssi);
  } else if (dataPacketH == 9) {
    dataPacketH++;
  }
  if (dataPacketH == 10 && bits & 16) {
    bits -=  16;
    SoftSerial.print("K");
    SoftSerial.println(Mode);
  } else if (dataPacketH == 10) {
    dataPacketH++;
  }
  if (dataPacketH == 11  && bits & 32) {
    bits -=  32;
    SoftSerial.print("L");
    SoftSerial.println(State);
  } else if (dataPacketH == 11) {
    dataPacketH++;
  }
  if (dataPacketH == 12) {
    SoftSerial.print("M");
    SoftSerial.println(Spare);
  }
  if (dataPacketH == 13) {
    SoftSerial.print("N");
    SoftSerial.println(Msg);
  }

  if (dataPacketH < 13) {
    dataPacketH++;
  } else {
    dataPacketH = 0;
  }

}
