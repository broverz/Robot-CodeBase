int l1, l, c, r, r1, eye0;

void SRight() {
  resetYaw();
  delay(500);

  lineTrackingPID();
  resetYaw();
  delay(100);
  gyroFF(60, 55);
  gyroFL(80);
  delay(60);

  lineTrackingPID();
  resetYaw();
  delay(100);
  delay(60);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(160, 55);
  // grabBk();
  // gyroFR(160);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(150, 55);
  // gyroFR(76);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(150, 55);
  // putBk();

  // gyroFR(160);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(150, 55);
  // gyroFR(76);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(150, 55);
  // gyroFL(76);

  // gyroFF(180, 55);

  // grabBk();

  // gyroFR(80);
  // gyroFF(50,55);

  // lineTrackingPID();
  // resetYaw();
  // delay(50);
  // gyroFF(150, 55);

  // gyroFF(275, 55);

  // putBk();
}