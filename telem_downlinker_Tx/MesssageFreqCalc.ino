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

  hFreqInterval = (100 / hFreqIntervalRatio) * sendInterval;
  mFreqInterval = (100 / mFreqIntervalRatio) * sendInterval;
  lFreqInterval = (100 / lFreqIntervalRatio) * sendInterval;
}

