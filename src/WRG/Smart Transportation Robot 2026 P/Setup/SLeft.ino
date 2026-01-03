void SLeft() {
  resetYaw();
  delay(500);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 35);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 25);
  gyroFL(55);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 35);
  gyroFR(55);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 25);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 25);
  gyroFR(55);

  //
  lineTrackingPID();
  delay(50);
  resetYaw();
  gyroFF(10, 25);
}