void MFC() {

  byte messageP[] = {LatP, LonP, AltP, SpeedP, CourseP, VoltP, CurrentP, FixP, RssiP, BatPP, SatP, StateP, ModeP, SpareP};

  byte i;
  for (i = 0; i < 14; i++) {
    if (messageP[i] == 2) {
      hFreqIntervalRatioCount ++;
    }
    if (messageP[i] == 1) {
      mFreqIntervalRatioCount ++;
    }
    if (messageP[i] == 0) {
      lFreqIntervalRatioCount ++;
    }
  }

  sendInterval = 1000 / messageFreq;

  hFreqInterval = ((100 - messageFreqOvershoot) / hFreqIntervalRatio) * sendInterval;
  mFreqInterval = ((100 - messageFreqOvershoot) / mFreqIntervalRatio) * sendInterval;
  lFreqInterval = ((100 - messageFreqOvershoot) / lFreqIntervalRatio) * sendInterval;

//  Serial.print("Total Messages per Minute = ");
//  Serial.println((60000 / hFreqInterval) + (60000 / mFreqInterval) + (60000 / lFreqInterval));
//  Serial.print("Messages Interviel = ");
//  Serial.print(sendInterval);
//  Serial.println(" ms");

}

