extern MPU6050 mpu;
extern int16_t gx, gy, gz;
extern float yaw, currentYaw;
extern unsigned long lastTime;

#define MoMaxSpeed1 50
#define MoMaxSpeed2 50
#define MoMaxSpeed3 75
#define MoMaxSpeed4 75

#define sensorLL 3000
#define sensorCC 3000
#define sensorRR 3000

#define sensorBL 3000
#define sensorBR 3000

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

int rd(int pin) {
  return analogRead(pin);
}
int L() {
  return rd(A0);
}
int C() {
  return rd(A1);
}
int R() {
  return rd(A2);
}

bool blackL() {
  return L() < sensorLL;
}
bool blackC() {
  return C() < sensorCC;
}
bool blackR() {
  return R() < sensorRR;
}

bool allBlack() {
  return blackL() && blackC() && blackR();
}

void follow3(int S = 75) {

  if (allBlack()) {  // เจอทั้งสาม
    ao();
    return;
  }

  if (blackL()) {  // ซ้ายสุดเจอ → ล้อขวาเดิน
    mManual(0, S, 0, S);
  } else if (blackR()) {  // ขวาสุดเจอ → ล้อซ้ายเดิน
    mManual(S, 0, S, 0);
  } else if (blackC()) {  // กลางเจอ → ตรง
    mManual(S, S, S, S);
  } else {  // ไม่เจอเส้น
    mManual(S, S, S, S);
  }
}

bool goBlock(int S = 75) {
  unsigned long st = millis();
  while (millis() - st < 550) {
    if (allBlack()) {
      ao();
      return true;  // เจอดำ
    }
    follow3(S);
  }
  ao();
  return false;  // ไม่เจอดำ
}

void turnR() {
  gyroFR(75);
}
void turnL() {
  gyroFL(75);
}

void backBlock(int S = 75) {
  gyroFF(100, -S);
    ao();
}


// void FT(int t = 500, int S = 75) {
//   unsigned long st = millis();
//   while (millis() - st < t) {
//     if (rd(A2) < sensorL2 && rd(A1) < sensorR2) break;
//     if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
//       mManual(S, S, S, S);
//     else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, -S, S, S);
//     else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, S, -S, -S);
//   }
//   ao();
// }

// bool FC(int S = 75) {
//   if (allBlack()) {
//     ao();
//     return true;
//   }

//   if (rd(A3) > sensorL1 && rd(A2) > sensorL2 && rd(A1) > sensorR2 && rd(A0) > sensorR1)
//     mManual(S, S, S, S);
//   else if (rd(A1) < sensorR2 || rd(A0) < sensorR1) mManual(-S, -S, S, S);
//   else if (rd(A2) < sensorL2 || rd(A3) < sensorL1) mManual(S, S, -S, -S);
//   return false;
// }

void FA(int S = 75) {
  while (1) {

    // เดินหน้า 1 block
    if (goBlock(S)) continue;

    // ---------- เช็คขวา ----------
    turnR();
    if (goBlock(S)) {
      backBlock(S);
      turnL();  // กลับทิศเดิม
    }

    // ---------- เช็คซ้าย ----------
    turnL();
    if (goBlock(S)) {
      backBlock(S);
      turnR();
    }

    // ---------- เดินต่อ ----------
    if (goBlock(S)) continue;

    // ถ้าเจอดำอีก → เลี้ยวซ้าย 2 ครั้ง
    turnL();
    goBlock(S);
    // if (goBlock(S)) {
    //   turnL();
    //   goBlock(S);
    // }
  }
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
    mManual(-65, -65, 65, 65);
    updateMPU();
  }
  mManual(0, 0, 0, 0);
  ao();
}

void gyroFR(float angle) {
  updateMPU();
  float target = currentYaw - angle;
  while (currentYaw > target) {
    mManual(65, 65, -65, -65);
    updateMPU();
  }
  mManual(0, 0, 0, 0);
  ao();
}
