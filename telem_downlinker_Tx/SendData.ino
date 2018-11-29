void SendData() {


  if (dataPacketH == 0 && bits & 1) {
    bits -= 1;
    SoftSerial.print("A");
    SoftSerial.println(Lat);
  } else if (dataPacketH == 0) {
    dataPacketH++;
  }
  if (dataPacketH == 1 && bits & 2) {
    bits -= 2;
    SoftSerial.print("B");
    SoftSerial.println(Lon);
  } else if (dataPacketH == 1) {
    dataPacketH++;
  }



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
















//
//
//
//void SendData() {
//
//  // if (dataPacketH == 0 && bits ^ 1) {
//  if (dataPacketH == 0) {
//    // bits -= 1;
//    SoftSerial.print("A");
//    SoftSerial.println(Lat);
//  }
//  // if (dataPacketH == 1 && bits ^ 2) {
//  if (dataPacketH == 1) {
//    //  bits -= 2;
//    SoftSerial.print("B");
//    SoftSerial.println(Lon);
//  }
//
//
//
//  if (dataPacketH == 2 && dataPacketM == 0 && bits ^ 64) {
//    bits -= 64;
//    SoftSerial.print("C");
//    SoftSerial.println(Alt);
//  }
//  if (dataPacketH == 2 && dataPacketM == 1 && bits ^ 128) {
//    bits -= 128;
//    SoftSerial.print("D");
//    SoftSerial.println(Course);
//  }
//  if (dataPacketH == 2 && dataPacketM == 2 && bits ^ 256) {
//    bits -= 256;
//    SoftSerial.print("E");
//    SoftSerial.println(Volt);
//  }
//  if (dataPacketH == 2 && dataPacketM == 3 && bits ^ 4) {
//    bits -= 4;
//    SoftSerial.print("G");
//    SoftSerial.println(Speed);
//  }
//  if (dataPacketH == 2 && dataPacketM == 4 && bits ^ 512) {
//    bits -= 512;
//    SoftSerial.print("F");
//    SoftSerial.println(Current);
//  }
//
//
//
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 0 && bits ^ 1024) {
//    bits -= 1024;
//    SoftSerial.print("H");
//    SoftSerial.println(BatP);
//  }
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 1  && bits ^ 8) {
//    bits -= 8;
//    SoftSerial.print("I");
//    SoftSerial.println(Sat);
//  }
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 2  && bits ^ 2048) {
//    bits -= 2048;
//    SoftSerial.print("J");
//    SoftSerial.println(Rssi);
//  }
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 3 && bits ^ 16) {
//    bits -= 16;
//    SoftSerial.print("L");
//    SoftSerial.println(Mode);
//  }
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 4  && bits ^ 32) {
//    bits -= 32;
//    SoftSerial.print("k");
//    SoftSerial.println(State);
//  }
//  if (dataPacketH == 3  && dataPacketM == 5 && dataPacketL == 5 ) {
//    SoftSerial.print("M");
//    SoftSerial.println(Spare);
//  }
//  if (dataPacketH == 3 && dataPacketM == 5 && dataPacketL == 6 ) {
//    SoftSerial.print("N");
//    SoftSerial.println(Msg);
//  }
//
//  //  Serial.print(dataPacketH);
//  //  Serial.print("\t");
//  //  Serial.print(dataPacketM);
//  //  Serial.print("\t");
//  //  Serial.println(dataPacketL);
//
////  if (dataPacketH < 3) {
////    dataPacketH++;
////  } else {
////    dataPacketH = 0;
////  }
////
////  if (dataPacketH == 3) {
////    dataPacketM++;
////  }
////  if (dataPacketM > 4) {
////    dataPacketM = 0;
////  }
////
////  if (dataPacketH == 3 && dataPacketM == 4) {
////    dataPacketL++;
////  }
////  if (dataPacketL > 6) {
////    dataPacketL = 0;
////  }
//
//
//
//}
//


