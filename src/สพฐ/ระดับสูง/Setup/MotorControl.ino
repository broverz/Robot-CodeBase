// extern MPU6050 mpu;
// extern int16_t gx, gy, gz;
// extern float yaw, currentYaw;
// extern unsigned long lastTime;

#define MoMaxSpeed1 75
#define MoMaxSpeed2 75
#define MoMaxSpeed3 75
#define MoMaxSpeed4 75

#define sensorL1 1200
#define sensorL2 1800
#define sensorR2 1800
#define sensorR1 1200

void mManual(int S1 = 75, int S2 = 75, int S3 = 75, int S4 = 75, int timeout = 0, bool doBeep = false) {
  motor(1, constrain(S1, -100, MoMaxSpeed1));  // หน้าซ้าย
  motor(2, constrain(S2, -100, MoMaxSpeed2));  // หน้าขวา
  motor(3, constrain(S3, -100, MoMaxSpeed3));  // หลังซ้าย
  motor(4, constrain(S4, -100, MoMaxSpeed4));  // หลังขวา
  if (timeout > 0) {
    delay(timeout);
    ao();
  }
  if (doBeep) beep();
}

void FF(int timeout = 500, int S = 75) {
  mManual(S, S, S, S);
  delay(timeout);
  ao();
}

void TT(int timeout = 500, int S = 75) {
  mManual(-S, S, -S, S);
  delay(timeout);
  ao();
}

void SL(int timeout = 500, int S = 75) {
  mManual(-S, S, S, -S);
  delay(timeout);
  ao();
}

void SR(int timeout = 500, int S = 75) {
  mManual(S, -S, -S, S);
  delay(timeout);
  ao();
}

int rd(int pin) {
  return analogRead(pin);
}

void FT(int t = 500, int S = 75) {
  unsigned long st = millis();
  while (millis() - st < t) {
    if (rd(A2) < sensorL2 && rd(A1) < sensorR2) break;
    if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
      mManual(S, S, S, S);
    else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, S, -S, S);
    else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, -S, S, -S);
  }
  ao();
}

int blackCount() {
  int c = 0;
  if (rd(A3) < sensorL1) c++;
  if (rd(A2) < sensorL2) c++;
  if (rd(A1) < sensorR2) c++;
  if (rd(A0) < sensorR1) c++;
  return c;
}
bool isLine() {
  int c = blackCount();
  return (c >= 2 && c <= 3);
}
bool isStopMark() {
  return blackCount() == 4;
}

bool FC(int S = 75) {
  if (isStopMark()) {
    ao();
    return true;
  }
  if (isLine()) {
    ao();
    return true;
  }

    if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
      mManual(S, S, S, S);
    else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, S, -S, S);
    else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, -S, S, -S);
  return false;
}


void FA(int S = 75) {
  while (true) {
    if (!FC(S)) continue;
    if (isStopMark()) break;
    ao();

    FF(200, -S);
    if (isStopMark()) {
      ao();
      return;
    }
    TT(377, -S);
    delay(150);
    if (isStopMark()) {
      ao();
      break;
    }

    unsigned long t = millis();
    bool hasLine = false;
    while (millis() - t < 600) {
      if (isStopMark()) {
        ao();
        return;
      }
      if (isLine()) {
        hasLine = true;
        break;
      }
    if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
      mManual(S, S, S, S);
    else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, S, -S, S);
    else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, -S, S, -S);
    }

    if (!hasLine) {
      ao();
      continue;
    }

    ao();
    FF(200, -S);
    if (isStopMark()) {
      ao();
      return;
    }
    TT(718, S);
    delay(150);

    t = millis();
    while (millis() - t < 600) {
      if (isStopMark()) {
        ao();
        return;
      }
    if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
      mManual(S, S, S, S);
    else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, S, -S, S);
    else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, -S, S, -S);
    }
    ao();
  }
  ao();
}

// void updateMPU() {
//   unsigned long now = micros();
//   float dt = (now - lastTime) / 1000000.0;
//   lastTime = now;

//   mpu.getRotation(&gx, &gy, &gz);
//   float gz_dps = gz / 131.0;
//   yaw += gz_dps * dt;
//   currentYaw = yaw;
// }

// void resetYaw() {
//   yaw = 0;
//   currentYaw = 0;
//   lastTime = micros();
// }

// void gyroFF(int timeMs, int speed = 75) {
//   unsigned long start = millis();
//   while (millis() - start < timeMs) {
//     mManual(speed, speed, speed, speed);
//     updateMPU();
//   }
//   mManual(0, 0, 0, 0);
//   ao();
// }

// void gyroFL(float angle) {
//   updateMPU();
//   float target = currentYaw + angle;
//   while (currentYaw < target) {
//     mManual(-75, 75, -75, 75);
//     updateMPU();
//   }
//   mManual(0, 0, 0, 0);
//   ao();
// }

// void gyroFR(float angle) {
//   updateMPU();
//   float target = currentYaw - angle;
//   while (currentYaw > target) {
//     mManual(75, -75, 75, -75);
//     updateMPU();
//   }
//   mManual(0, 0, 0, 0);
//   ao();
// }
