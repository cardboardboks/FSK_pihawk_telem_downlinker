void Servos() {

  GPSCalc();

  offSet = offSetM;

  if (Angle - offSet >= -180 && Angle - offSet <= 180) {
    panAngle = (Angle - offSet);
  }
  if (Angle - offSet >= 181) {
    offSet = Angle - offSet;
    panAngle = (((offSet) - ((offSet - 180) * 2)) * -1);
  }
  if (Angle - offSet <= -181) {
    offSet = Angle - offSet;
    panAngle = ((offSet * -1) + ((offSet + 180) * 2));
  }

  if (Alt - HAlt > 0) {
    tiltAngle =  round( atan2 ((Alt - HAlt), Range) * 180 / 3.14159265 );
  } else {
    tiltAngle = 0;
  }


  panMs = ((((panServoMax - panServoMin) / panServoRange) * panAngle) * -1) + panServoMid;
  tiltMs = ((((tiltServoMax - tiltServoMin) / tiltServoRange) * tiltAngle)) + tiltServoMin;


  panMs = constrain(panMs, panServoMin , panServoMax);
  tiltMs = constrain(tiltMs, tiltServoMin , tiltServoMax);

  panServoRate = (panMsC - panMs) / 5;
  if (panServoRate < 0) {
    panServoRate = panServoRate * -1;
  }

  tiltServoRate = (tiltMsC - tiltMs) / 5;
  if (tiltServoRate < 0) {
    tiltServoRate = tiltServoRate * -1;
  }

  panServoRate = constrain(panServoRate, 5, 250);
  tiltServoRate = constrain(tiltServoRate, 5, 250);

  if (panMsC > panMs) {
    panMsC -= 1;
  }
  if (panMsC < panMs) {
    panMsC += 1;
  }
  if (tiltMsC > tiltMs) {
    tiltMsC -= tiltServoRate;
  }
  if (tiltMsC < tiltMs) {
    tiltMsC += tiltServoRate;
  }

  //  Serial.print(panAngle);
  //  Serial.print("\t");
  //  Serial.print(tiltAngle);
  //  Serial.print("\t");
  //  Serial.print(panServoRate);
  //  Serial.print("\t");
  //  Serial.print(tiltServoRate);
  //  Serial.print("\t");
  //  Serial.print(panMsC);
  //  Serial.print("\t");
  //  Serial.println(tiltMsC);

  panServo.writeMicroseconds(panMsC);
  tiltServo.writeMicroseconds(tiltMsC);

}

void GPSCalc() {
  if (pass == 1) {
    Angle = CourseTo(HLat, HLon, Lat, Lon);
    Range = DistanceTo(HLat, HLon, Lat, Lon);
  }
}

