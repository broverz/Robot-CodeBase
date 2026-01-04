void SLeft() {
  resetYaw();
  delay(500);

  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(10, 25);
  gyroFL(62);

  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(5, 25);
  gyroFR(62.2);
  
  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(10, 35);
  
  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(10, 35);
  
  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(10, 35);
  
  //
  lineTrackingPID();
  resetYaw();
  delay(50);
  gyroFF(10, 35);
}