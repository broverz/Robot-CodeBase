void SRight() {
  resetYaw();
  delay(250);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(95, 55);
  gyroFL(25);
  gyroFF(220, 55);
  grabBk();
  gyroFF(200, -55);
  gyroFR(36);
  putNow();

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(120, 55);
  gyroFL(50);
  delay(50);

  lineTrackingPID(0, 0, 450);
  resetYaw();
  gyroFF(125, 55);
  gyroFL(41);
  gyroFF(180, 55);
  grabBkH();
  gyroFF(210, -55);
  gyroFL(44);

  lineTrackingPID(0, 0, 450);
  resetYaw();
  gyroFF(90, 55);
  gyroFR(52);


  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(65);
  gyroFF(260, 55);
  putBk();
  gyroFF(140, -55);
  gyroFR(22);
  gyroFF(140, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFL(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFL(51);
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 4500);
  resetYaw();
  gyroFF(210, -55);
  grabBk();
  gyroFL(96);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(51);


  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFL(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(52);
  gyroFF(100, 55);
  putBk();
  gyroFF(140, -55);
  gyroFL(52);
  gyroFF(90, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFR(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
  gyroFL(52);

  lineTrackingPID(0, 0);
  resetYaw();
  gyroFF(110, 55);
}