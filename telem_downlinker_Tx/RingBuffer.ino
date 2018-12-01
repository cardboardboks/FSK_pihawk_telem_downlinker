void RingBuffer() {

  if ( millis() - hFreqMillis >= hFreqInterval) {
    hFreqMillis =  millis();
    
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
  }

  if ( millis() - mFreqMillis >= mFreqInterval) {
    mFreqMillis =  millis();

  }

  if ( millis() - lFreqMillis >= lFreqInterval) {
    lFreqMillis =  millis();

  }
}

