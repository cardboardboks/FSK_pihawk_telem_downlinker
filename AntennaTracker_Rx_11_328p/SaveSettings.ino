void SaveSettings() {

  panServoMin = 1000;
  panServoMid = 1500;
  panServoMax = 2000;
  panServoRange = 90;
  tiltServoMin = 1000;
  tiltServoMid = 1500;
  tiltServoMax = 2000;
  tiltServoRange = 90;

  EepromW(1, 2 , panServoMin);
  EepromW(3, 4, panServoMid);
  EepromW(5, 6, panServoMax);
  EepromW(7, 8, panServoRange);
  EepromW(9, 10, tiltServoMin);
  EepromW(11, 12, tiltServoMid);
  EepromW(13, 14, tiltServoMax);
  EepromW(15, 16, tiltServoRange);

}

int EepromW(byte x, byte y, int number) {
  int a;
  int b;

  a = number  / 256;
  b = number  % 256;
  EEPROM.write(x, a);
  EEPROM.write(y, b);

}
