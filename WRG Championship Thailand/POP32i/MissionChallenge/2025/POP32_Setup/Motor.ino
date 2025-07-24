// mManual กำหนดเอง
// FF เดินหน้าใส่ 100 ถอยหลัง -100
// FL เลื้ยวซ้าย
// FR เลื้ยวชวา

void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false) {
  motor(Motor_Left, rspeed);
  motor(Motor_Right, lspeed);
  sleep(timeout);
  ao();
  if (doBeep) beep();
}

void FF(int speed = 100, int timeout = 250) {
  mManual(speed, speed, timeout);
  // mManual(-speed, -speed, 80);
}

void FL(int speed = 100, int timeout = 250) {
  mManual(speed, -speed, timeout);
  // mManual(-speed, speed, 25);
}

void FR(int speed = 100, int timeout = 250) {
  mManual(-speed, speed, timeout);
  // mManual(speed, -speed, 25);
}

void gyroTurn(float targetAngle, int speed) {
  mpu.update();
  float startAngle = mpu.getAngleZ();
  float target = startAngle + targetAngle;

  if (targetAngle > 0) {
    while (mpu.getAngleZ() < target) {
      mpu.update();
      motor(Motor_Left, -speed);
      motor(Motor_Right, speed);
      delay(5);
    }
  } else {
    while (mpu.getAngleZ() > target) {
      mpu.update();
      motor(Motor_Left, speed);
      motor(Motor_Right, -speed);
      delay(5);
    }
  }
  ao();
}

void gyroFF(int timeout = 140, int baseSpeed = 100) {
  mpu.update();
  float initialAngle = mpu.getAngleZ();
  unsigned long startTime = millis();

  while (millis() - startTime < timeout) {
    mpu.update();
    float error = initialAngle - mpu.getAngleZ();
    float correction = 2.0 * error;

    int leftSpeed = constrain(baseSpeed - correction, 0, 100);
    int rightSpeed = constrain(baseSpeed + correction, 0, 100);

    motor(Motor_Left, leftSpeed);
    motor(Motor_Right, rightSpeed);
    delay(10);
  }
  ao();
}

void gyroFL(int deg = 41, int timeoutFF = 0) {
  gyroFF(timeoutFF);
  gyroTurn(deg, 100);
  ao();
  delay(50);
}

void gyroFR(int deg = 41, int timeoutFF = 0) {
  gyroFF(timeoutFF);
  gyroTurn(-deg, 100);
  ao();
  delay(50);
}
