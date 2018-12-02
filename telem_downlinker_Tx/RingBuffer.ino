void RingBuffer() {

  if ( millis() - hFreqMillis >= hFreqInterval) {
    hFreqMillis =  millis();

    if (dataPacketH == 0 && bits & 1) {
      bits ^= 1;
      //      Serial.print("a");
      //      Serial.print(",");
      buff[buffHead].ident = 'A';
      buff[buffHead].data = Lat;
      buffHead++;
    } else if (dataPacketH == 0) {
      dataPacketH++;
    }
    if (dataPacketH == 1 && bits & 2) {
      bits ^= 2;
      //      Serial.print("b");
      //      Serial.print(",");
      buff[buffHead].ident = 'B';
      buff[buffHead].data = Lon;
      buffHead++;
    } else if (dataPacketH == 1) {
      dataPacketH++;
    }

    if (dataPacketH > 1) {
      goto MSPEED;
    }
    dataPacketH++;
  }

  if ( millis() - mFreqMillis >= mFreqInterval) {
    mFreqMillis =  millis();

MSPEED:

    if (dataPacketM == 0 && bits & 64) {
      bits ^= 64;
      //      Serial.print("c");
      //      Serial.print(",");
      buff[buffHead].ident = 'C';
      buff[buffHead].data = Alt;
      buffHead++;
    } else if (dataPacketM == 0) {
      dataPacketM++;
    }
    if (dataPacketM == 1 && bits & 128) {
      bits ^=  128;
      //      Serial.print("d");
      //      Serial.print(",");
      buff[buffHead].ident = 'D';
      buff[buffHead].data = Course;
      buffHead++;
    } else if (dataPacketM == 1) {
      dataPacketM++;
    }
    if (dataPacketM == 2 && bits & 256) {
      bits ^=  256;
      //      Serial.print("e");
      //      Serial.print(",");
      buff[buffHead].ident = 'E';
      buff[buffHead].data = Volt;
      buffHead++;
    } else if (dataPacketM == 2) {
      dataPacketM++;
    }
    if (dataPacketM == 3 && bits & 4) {
      bits ^=  4;
      //      Serial.print("f");
      //      Serial.print(",");
      buff[buffHead].ident = 'F';
      buff[buffHead].data = Speed;
      buffHead++;
    } else if (dataPacketM == 3) {
      dataPacketM++;
    }
    if (dataPacketM == 4 && bits & 512) {
      bits ^=  512;
      //      Serial.print("g");
      //      Serial.print(",");
      buff[buffHead].ident = 'G';
      buff[buffHead].data = Current;
      buffHead++;
    } else if (dataPacketM == 4) {
      dataPacketM++;
    }
    if (dataPacketM > 4) {
      goto LSPEED;
    }
    dataPacketM++;
  }

  if ( millis() - lFreqMillis >= lFreqInterval) {
    lFreqMillis =  millis();

LSPEED:

    if (dataPacketL == 0 && bits & 1024) {
      bits ^=  1024;
      //      Serial.print("h");
      //      Serial.print(",");
      buff[buffHead].ident = 'H';
      buff[buffHead].data = BatP;
      buffHead++;
    } else if (dataPacketL == 0) {
      dataPacketL++;
    }
    if (dataPacketL == 1  && bits & 8) {
      bits ^=  8;
      //      Serial.print("i");
      //      Serial.print(",");
      buff[buffHead].ident = 'I';
      buff[buffHead].data = Sat;
      buffHead++;
    } else if (dataPacketL == 1) {
      dataPacketL++;
    }
    if (dataPacketL == 2 && bits & 2048) {
      bits ^=  2048;
      //      Serial.print("j");
      //      Serial.print(",");
      buff[buffHead].ident = 'J';
      buff[buffHead].data = Rssi;
      buffHead++;
    } else if (dataPacketL == 2) {
      dataPacketL++;
    }
    if (dataPacketL == 3 && bits & 16) {
      bits ^=  16;
      //      Serial.print("k");
      //      Serial.print(",");
      buff[buffHead].ident = 'K';
      buff[buffHead].data = Mode;
      buffHead++;
    } else if (dataPacketL == 3) {
      dataPacketL++;
    }
    if (dataPacketL == 4  && bits & 32) {
      bits ^=  32;
      //      Serial.print("l");
      //      Serial.print(",");
      buff[buffHead].ident = 'L';
      buff[buffHead].data = State;
      buffHead++;
    } else if (dataPacketL == 4) {
      dataPacketL++;
    }
    if (dataPacketL == 5) {
      //      Serial.print("m");
      //      Serial.print(",");
      buff[buffHead].ident = 'M';
      buff[buffHead].data = Spare;
      buffHead++;
    }
    if (dataPacketL == 6) {
      //      Serial.print("n");
      //      Serial.print(",");
      buff[buffHead].ident = 'N';
      buff[buffHead].data = Msg;
      buffHead++;
    }
    dataPacketL++;
  }

  if (dataPacketH > 1) {
    dataPacketH = 0;
  }
  if (dataPacketM > 4) {
    dataPacketM = 0;
  }
  if (dataPacketL > 6) {
    dataPacketL = 0;
  }

  if (buffHead > buffSize) {
    buffHead = 0;
  }

  //  int i;
  //  for (i = 0; i < 20; i++) {
  //    Serial.print(buff[i].ident);
  //    Serial.print(",");
  //    Serial.print(buff[i].data);
  //    Serial.print(",");
  //  }
  //  Serial.println();
}

