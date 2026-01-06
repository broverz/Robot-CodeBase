void SRight() {
  resetYaw();
  delay(250);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);
  gyroFR(51);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);
  gyroFL(24);
  gyroFF(220, 55);
  grabBk();
  gyroFF(280, -55);
  gyroFR(54);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);
  gyroFL(50);

  lineTrackingPID();
  resetYaw();
  gyroFF(250, 55);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);
  gyroFL(51);

  lineTrackingPID();
  resetYaw();
  gyroFF(110, 55);
  gyroFL(51);
  lineTrackingPID(1);
  gyroFL(155);
  lineTrackingPID(1);
  gyroFF(110, 55);
  gyroFR(51);


}