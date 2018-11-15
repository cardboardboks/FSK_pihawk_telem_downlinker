void debug() {

  //Serial.print(Lat, 5);
  //Serial.print(",");
  //Serial.print(Lon, 5);
  //Serial.print(",");

  if (dataPacket == 0) {
    Serial.print("A");
    LatLonDebug();
    Serial.print(Alt);
    Serial.print(",");
    Serial.print(Course);
    Serial.print(",");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Alt + Course);
    Serial.print("\n");
  }
  if (dataPacket == 1) {
    Serial.print("V");
    LatLonDebug();
    Serial.print(Volt);
    Serial.print(",");
    Serial.print(Current);
    Serial.print(",");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Volt + Current);
    Serial.print("\n");
  }
  if (dataPacket == 2) {
    Serial.print("R");
    LatLonDebug();
    Serial.print(Rssi);
    Serial.print(",");
    Serial.print(BatP);
    Serial.print(",");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Rssi + BatP);
    Serial.print("\n");
  }
  if (dataPacket == 3) {
    Serial.print("S");
    LatLonDebug();
    Serial.print(Sat);
    Serial.print(",");
    Serial.print(Speed);
    Serial.print(",");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Sat + Speed);
    Serial.print("\n");
  }
  if (dataPacket == 4) {
    SoftSerial.print("O");
    LatLon();
    SoftSerial.print(State);
    SoftSerial.print(",");
    SoftSerial.print(Mode);
    SoftSerial.print(",");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + State + Mode);
    SoftSerial.print("\n");
  }

}

void LatLonDebug() {
  //print Lat interger
  Serial.print(LATI);

  //print Lat first fractional, add padding if needed
  if (LATF1 > 9) {
    Serial.print(",");
  } else {
    Serial.print(",0");
  }
  Serial.print(LATF1);

  //print Lat second fractional, add padding if needed
  if (LATF2 > 99) {
    Serial.print(",");
  } else if (LATF2 > 9) {
    Serial.print(",0");
  } else {
    Serial.print(",00");
  }
  Serial.print(LATF2);
  Serial.print(",");

  //print Lon interger
  Serial.print(LONI);

  //print Lon first fractional, add padding if needed
  if (LONF1 > 9) {
    Serial.print(",");
  } else {
    Serial.print(",0");
  }
  Serial.print(LONF1);

  //print Lon second fractional, add padding if needed
  if (LONF2 > 99) {
    Serial.print(",");
  } else if (LONF2 > 9) {
    Serial.print(",0");
  } else {
    Serial.print(",00");
  }
  Serial.print(LONF2);
  Serial.print(",");
}

