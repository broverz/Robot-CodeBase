// mManual กำหนดเอง
// FF เดินหน้าใส่ 100 ถอยหลัง -100
// FL เลื้ยวซ้าย
// FR เลื้ยวชวา

const int Motor_Left = 2;
const int Motor_Right = 1;

void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true) {
  motor(Motor_Left, rspeed);
  motor(Motor_Right, lspeed);
  sleep(timeout);
  ao();
  if (doBeep) beep();
}

void FF(int speed = 100, int timeout = 250) {
  mManual(speed, speed - 6, timeout);
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
    // หมุนซ้าย
    while (mpu.getAngleZ() < target) {
      mpu.update();
      motor(1, -speed);  // ซ้ายถอย
      motor(2, speed);   // ขวาเดินหน้า
      delay(5);
    }
  } else {
    // หมุนขวา
    while (mpu.getAngleZ() > target) {
      mpu.update();
      motor(1, speed);   // ซ้ายเดินหน้า
      motor(2, -speed);  // ขวาถอย
      delay(5);
    }
  }
  ao();  // หยุดหลังหมุน
}


// === เดินหน้า (Gyro) ===
void GYROFF(int timeout = 140) {
  mpu.update();
  float initialAngle = mpu.getAngleZ();
  unsigned long startTime = millis();

  while (millis() - startTime < timeout) {
    mpu.update();
    float error = initialAngle - mpu.getAngleZ();
    float correction = 2.0 * error;

    int baseSpeed = 100;
    int leftSpeed = constrain(baseSpeed - correction, 0, 100);
    int rightSpeed = constrain(baseSpeed + correction, 0, 100);

    motor(1, leftSpeed);
    motor(2, rightSpeed);
    delay(10);
  }
  ao();
}

// === เดินหน้าแล้วเลี้ยวซ้าย 90 องศา ===
void GYROFL(int deg = 41, int timeoutFF = 0) {
  GYROFF(timeoutFF);
  gyroTurn(deg, 100);
  ao();
  delay(45);
}

// === เดินหน้าแล้วเลี้ยวขวา 90 องศา ===
void GYROFR(int deg = 41, int timeoutFF = 0) {
  GYROFF(timeoutFF);
  gyroTurn(-deg, 100);
  ao();
  delay(45);
}
