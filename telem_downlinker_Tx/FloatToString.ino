void flotToInt() {

  String LATFS = String(Lat, 5);
  String LONFS = String(Lon, 5);
  String LATFS1;
  String LONFS1;
  String LATFS2;
  String LONFS2;

  if (LATFS.length() == 8) {
    LATFS.remove(0, 3);
  }
  else if (LATFS.length() == 9) {
    LATFS.remove(0, 4);
  }
  else if (LATFS.length() == 10) {
    LATFS.remove(0, 5);
  }

  if (LONFS.length() == 8) {
    LONFS.remove(0, 3);
  }
  else if (LONFS.length() == 9) {
    LONFS.remove(0, 4);
  }
  else if (LONFS.length() == 10) {
    LONFS.remove(0, 5);
  }

  LATI = (int)Lat;
  LONI = (int)Lon;

  LATFS1 = LATFS;
  LONFS1 = LONFS;
  LATFS2 = LATFS;
  LONFS2 = LONFS;

  LATFS1.remove(2, 3);
  LONFS1.remove(2, 3);
  LATFS2.remove(0, 2);
  LONFS2.remove(0, 2);

  LATF1 = LATFS1.toInt();
  LONF1 = LONFS1.toInt();
  LATF2 = LATFS2.toInt();
  LONF2 = LONFS2.toInt();
}
