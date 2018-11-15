void Constrain() {

  //  float RLAT = 0;
  //  float RLON = 0;

  //  RLAT = (float)random(100);
  //  RLON = (float)random(100);
  //  RLON = RLON / 100000;
  //  RLAT = RLAT / 100000;

  //  Lat += RLAT;
  //  Lon += RLON;
  //  Alt += (float)(random(-2, 2));
  //
  //  Volt = 1;
  //  Current = 5;
  //  Rssi = 10;
  //  Packet = 20;
  //  Sat = 0;
  //  Spare = 0;


  if (Lat > 90) {
    Lat = 90;
  }
  if (Lat < -90) {
    Lat = -90;
  }
  if (Lon > 180) {
    Lon = 180;
  }
  if (Lon < -180) {
    Lon = -180;
  }
  if (Alt > 5000) {
    Alt = 5000;
  }
  if (Alt < -500) {
    Alt = -500;
  }
  if (Course > 360) {
    Course = 360;
  }
  if (Course < 0) {
    Course = 0;
  }
  if (Volt > 999) {
    Volt = 999;
  }
  if (Volt < 0) {
    Volt = 0;
  }
  if (Current > 2000) {
    Current = 2000;
  }
  if (Current < 0) {
    Current = 0;
  }
  if (Rssi > 255) {
    Rssi = 255;
  }
  if (Rssi < 0) {
    Rssi = 0;
  }
  if (Packet > 255) {
    Packet = 255;
  }
  if (Packet < 0) {
    Packet = 0;
  }
  if (Sat > 40) {
    Sat = 40;
  }
  if (Sat < 0) {
    Sat = 0;
  }
  if (Speed > 3000) {
    Speed = 3000;
  }
  if (Speed < 0) {
    Speed = 0;
  }
  if (Spare0 > 255) {
    Spare0 = 255;
  }
  if (Spare0 < 0) {
    Spare0 = 0;
  }
  if (Spare1 > 255) {
    Spare1 = 255;
  }
  if (Spare1 < 0) {
    Spare1 = 0;
  }
}

