void floatToInt() {

  String LATFSR = String(Lat, 5);
  String LONFSR = String(Lon, 5);

  String LATFSF = String(Lat, 5);
  String LONFSF = String(Lon, 5);


  //  Serial.print(LATFSR);
  //  Serial.print("\t");
  //  Serial.print(LONFSR);
  //  Serial.print("\t");

  if (Lat < 0) {
    LATI = 0;
    LATFSR.remove(0, 1);
    LATFSF.remove(0, 1);
  } else {
    LATI = 1;
  }

  if (Lon < 0) {
    LONI = 0;
    LONFSR.remove(0, 1);
    LONFSF.remove(0, 1);
  } else {
    LONI = 1;
  }


  LATFSF.remove((LATFSF.length() - 6), 1);
  LONFSF.remove((LONFSF.length() - 6), 1);

  LATFSF.remove((LATFSF.length() - 4), 10);
  LONFSF.remove((LONFSF.length() - 4), 10);

  LATF1 = LATFSF.toInt();
  LONF1 = LONFSF.toInt();

  LATF1 = (LATF1 *= 10) + 1;
  LONF1 = (LONF1 *= 10) + 1;

  if (LONI == 0) {
    LONF1 -= 1;
  }
  if (LATI == 0) {
    LATF1 -= 1;
  }

  LATFSR.remove((LATFSR.length() - 6), 1);
  LONFSR.remove((LONFSR.length() - 6), 1);



  if (LATFSR.length() == 6) {
    LATFSR.remove(0, 2);
  }
  else if (LATFSR.length() == 7) {
    LATFSR.remove(0, 3);
  }
  else if (LATFSR.length() == 8) {
    LATFSR.remove(0, 4);
  }

  if (LONFSR.length() == 6) {
    LONFSR.remove(0, 2);
  }
  else if (LONFSR.length() == 7) {
    LONFSR.remove(0, 3);
  }
  else if (LONFSR.length() == 8) {
    LONFSR.remove(0, 4);
  }
  else if (LONFSR.length() == 9) {
    LONFSR.remove(0, 5);
  }

  LATF2 = LATFSR.toInt();
  LONF2 = LONFSR.toInt();

  //  Serial.print(LATF1);
  //  Serial.print("\t");
  //  Serial.print(LATF2);
  //  Serial.print("\t");
  //  Serial.print(LONF1);
  //  Serial.print("\t");
  //  Serial.print(LONF2);
  //  Serial.println();
}
