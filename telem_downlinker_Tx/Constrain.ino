void Constrain() {

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
  if (Alt > 10000) {
    Alt = 10000;
  }
  if (Alt < -10000) {
    Alt = -10000;
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
  if (BatP > 100) {
    BatP = 100;
  }
  if (BatP < 0) {
    BatP = 0;
  }
  if (Sat > 40) {
    Sat = 0;
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
  if (State > 255) {
    State = 255;
  }
  if (State < 0) {
    State = 0;
  }
  if (Mode > 255) {
    Mode = 255;
  }
  if (Mode < 0) {
    Mode = 0;
  }
  if (Msg > 1) {
    Msg = 1;
  }
  if (Msg < 0) {
    Msg = 0;
  }
}

