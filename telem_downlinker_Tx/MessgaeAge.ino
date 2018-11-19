void MsgAge() {

  total = total - readings[readIndex];
  MsgNew = Time;
  readings[readIndex] = (MsgNew - MsgOld) / 1000;
  MsgOld = MsgNew;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  Msg = total / numReadings;

}


