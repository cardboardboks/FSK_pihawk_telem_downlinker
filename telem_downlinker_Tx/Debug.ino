void debug() {

  //Serial.print(Lat, 5);
  //Serial.print("\t");
  //Serial.print(Lon, 5);
  //Serial.print("\t");

  if (dataPacketH == 0) {
    Serial.print("A");
    LatLonDebug();
    Serial.print(Alt);
    Serial.print("\t");
    Serial.print(Course);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Alt + Course);
    Serial.print("\n");
  }
  if (dataPacketH == 1) {
    Serial.print("V");
    LatLonDebug();
    Serial.print(Volt);
    Serial.print("\t");
    Serial.print(Current);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Volt + Current);
    Serial.print("\n");
  }
  if (dataPacketH == 2) {
    Serial.print("R");
    LatLonDebug();
    Serial.print(Speed);
    Serial.print("\t");
    Serial.print(BatP);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Speed + BatP);
    Serial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 0) {
    Serial.print("S");
    LatLonDebug();
    Serial.print(Sat);
    Serial.print("\t");
    Serial.print(Rssi);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Sat + Rssi);
    Serial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 1) {
    Serial.print("O");
    LatLonDebug();
    Serial.print(State);
    Serial.print("\t");
    Serial.print(Mode);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + State + Mode);
    Serial.print("\n");
  }
  if (dataPacketH == 3 && dataPacketL == 2) {
    Serial.print("X");
    LatLonDebug();
    Serial.print(Msg);
    Serial.print("\t");
    Serial.print(Spare);
    Serial.print("\t");
    Serial.print(LATI + LATF1 + LATF2 + LONI + LONF1 + LONF2 + Msg + Spare);
    Serial.print("\n");
  }

}

void LatLonDebug() {
  Serial.print("\t");
  //print Lat interger
  Serial.print(LATI);

  //print Lat first fractional, add padding if needed
  if (LATF1 > 9) {
    Serial.print("\t");
  } else {
    Serial.print(",0");
  }
  Serial.print(LATF1);

  //print Lat second fractional, add padding if needed
  if (LATF2 > 99) {
    Serial.print("\t");
  } else if (LATF2 > 9) {
    Serial.print(",0");
  } else {
    Serial.print(",00");
  }
  Serial.print(LATF2);
  Serial.print("\t");

  //print Lon interger
  Serial.print(LONI);

  //print Lon first fractional, add padding if needed
  if (LONF1 > 9) {
    Serial.print("\t");
  } else {
    Serial.print(",0");
  }
  Serial.print(LONF1);

  //print Lon second fractional, add padding if needed
  if (LONF2 > 99) {
    Serial.print("\t");
  } else if (LONF2 > 9) {
    Serial.print(",0");
  } else {
    Serial.print(",00");
  }
  Serial.print(LONF2);
  Serial.print("\t");
}

