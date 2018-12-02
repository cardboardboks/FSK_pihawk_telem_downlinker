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

    SoftSerial.println(buff[buffTail].ident);
    SoftSerial.println(buff[buffTail].data1);
    if (buff[buffTail].ident == 65 || buff[buffTail].ident == 66) {
      SoftSerial.println(buff[buffTail].data2);
    }
    CheckSumCal(buff[buffTail].ident, buff[buffTail].data1);

    Serial.println(buff[buffTail].ident);
    Serial.println(buff[buffTail].data1);
    if (buff[buffTail].ident == 'A' || buff[buffTail].ident == 'B') {
      Serial.println(buff[buffTail].data2);
    }
    Serial.println(buff[buffTail].ident + buff[buffTail].data1);

    buffTail++;

    if (buffTail > buffSize) {
      buffTail = 0;
    }

  }
}
void CheckSumCal(char x, long y) {
  SoftSerial.println(x + y);
}
