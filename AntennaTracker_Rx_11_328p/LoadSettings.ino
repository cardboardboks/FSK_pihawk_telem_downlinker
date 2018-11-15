void LoadSettings() {

  panServoMin = EepromR(1, 2);
  panServoMid = EepromR(3, 4);
  panServoMax = EepromR(5, 6);
  panServoRange = EepromR(7, 8);
  tiltServoMin = EepromR(9, 10);
  tiltServoMid = EepromR(11, 12);
  tiltServoMax = EepromR(13, 14);
  tiltServoRange = EepromR(15, 16);

}

int EepromR(byte x, byte y) {

  int a = EEPROM.read(x);
  int b = EEPROM.read(y);
  return (a * 256 + b);

}
