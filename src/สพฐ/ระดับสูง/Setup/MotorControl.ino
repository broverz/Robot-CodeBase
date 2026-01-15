#define MoMaxSpeed1 75
#define MoMaxSpeed2 75
#define MoMaxSpeed3 75
#define MoMaxSpeed4 75

void mManual(int S1 = 75, int S2 = 75, int S3 = 75, int S4 = 75, int timeout = 0, bool doBeep = false) {
  mManual(1, constrain(S1, -100, MoMaxSpeed1));  // หน้าซ้าย
  mManual(2, constrain(S2, -100, MoMaxSpeed2));  // หน้าขวา
  mManual(3, constrain(S3, -100, MoMaxSpeed3));  // หลังซ้าย
  mManual(4, constrain(S4, -100, MoMaxSpeed4));  // หลังขวา
  if (timeout > 0) {
    delay(timeout);
    ao();
  }
  if (doBeep) beep();
}

void FF(int S = 75, int timeout = 500) {
  mManual(S, S, S, S);
  delay(timeout);
  ao();
}

void TT(int S = 75, int timeout = 500) {
  mManual(-S, S, -S, S);
  delay(timeout);
  ao();
}

void SL(int S = 75, int timeout = 500) {
  mManual(-S, S, S, -S);
  delay(timeout);
  ao();
}

void SR(int S = 75, int timeout = 500) {
  mManual(S, -S, -S, S);
  delay(timeout);
  ao();
}

void updateMPU() {
  unsigned long now = micros();
  float dt = (now - lastTime) / 1000000.0;
  lastTime = now;

  mpu.getRotation(&gx, &gy, &gz);
  float gz_dps = gz / 131.0;
  yaw += gz_dps * dt;
  currentYaw = yaw;
}

void resetYaw() {
  yaw = 0;
  currentYaw = 0;
  lastTime = micros();
}

void gyroFF(int timeMs, int speed = 75) {
  unsigned long start = millis();
  while (millis() - start < timeMs) {
    mManual(speed, speed, speed, speed);
    updateMPU();
  }
  mManual(0, 0, 0, 0);
  ao();
}

void gyroFL(float angle) {
  updateMPU();
  float target = currentYaw + angle;
  while (currentYaw < target) {
    mManual(-75, 75, -75, 75);
    updateMPU();
  }
  mManual(0, 0, 0, 0);
  ao();
}

void gyroFR(float angle) {
  updateMPU();
  float target = currentYaw - angle;
  while (currentYaw > target) {
    mManual(75, -75, 75, -75);
    updateMPU();
  }
  mManual(0, 0, 0, 0);
  ao();
}
