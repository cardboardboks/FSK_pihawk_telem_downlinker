void TinyGPS() {
  unsigned long chars;

  while (Serial1.available())
  {
    char c = Serial1.read();
    if (gps.encode(c)) // Did a new valid sentence come in?
      newData = true;
    Lat = gps.location.lat();
    Lon = gps.location.lng();
    Alt = (int)gps.altitude.meters();
    Course = (int)gps.course.deg();
    Sat = (int)gps.satellites.value();
    Speed = (int)(gps.speed.kmph() * 10);
  }
}

