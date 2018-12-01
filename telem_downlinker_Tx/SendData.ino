void SendData() {
  //  Serial.print(buffHead);
  //  Serial.print("\t");
  //  Serial.print(buffTail);
  //  Serial.print("\t");
  //  int neg;
  //  if (buffHead - buffTail < 0) {
  //    neg = buffHead - buffTail + 20;
  //  } else {
  //    neg = buffHead - buffTail;
  //  }
  //  Serial.println(neg);

  if ( millis() - sendIntervalMillis >= sendInterval) {
    sendIntervalMillis =  millis();

    SoftSerial.print(buff[buffTail].ident);
    SoftSerial.println(buff[buffTail].data);
    CheckSumCal(buff[buffTail].ident, buff[buffTail].data);

//    Serial.print(buff[buffTail].ident);
//    Serial.print(buff[buffTail].data);
//    Serial.print("\t");
//    Serial.println(buff[buffTail].ident + buff[buffTail].data);

    buffTail++;

    if (buffTail > buffSize) {
      buffTail = 0;
    }

  }
}
void CheckSumCal(char x, long y) {
  SoftSerial.print(x + y);
}
