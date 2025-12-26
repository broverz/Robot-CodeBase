extern MPU6050 mpu;
extern int16_t gx, gy, gz;
extern float yaw, currentYaw;
extern unsigned long lastTime;

#define Motor_Left 1
#define Motor_Right 3

void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false) {
  motor(Motor_Left, rspeed);
  motor(Motor_Right, lspeed);
  delay(timeout);
  ao();
  if (doBeep) beep();
}

void FF(int speed = 100, int timeout = 250) {
  mManual(speed, speed, timeout);
}
void FL(int speed = 100, int timeout = 250) {
  mManual(speed, -speed, timeout);
}
void FR(int speed = 100, int timeout = 250) {
  mManual(-speed, speed, timeout);
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

void calibrateGyro() {
  long sum = 0;
  for (int i = 0; i < 1000; i++) {
    mpu.getRotation(&gx, &gy, &gz);
    sum += gz;
    delay(2);
  }
  mpu.setZGyroOffset(-sum / 1000);
}

void gyroFF(int timeMs, int speed) {
  unsigned long start = millis();
  while (millis() - start < timeMs) {
    mManual(speed, speed);
    updateMPU();
  }
  mManual(0, 0);
}

void gyroFL(float angle) {
  updateMPU();
  float target = currentYaw + angle;
  while (currentYaw < target) {
    mManual(-80, 80);
    updateMPU();
  }
  mManual(0, 0);
}

void gyroFR(float angle) {
  updateMPU();
  float target = currentYaw - angle;
  while (currentYaw > target) {
    mManual(80, -80);
    updateMPU();
  }
  mManual(0, 0);
}
