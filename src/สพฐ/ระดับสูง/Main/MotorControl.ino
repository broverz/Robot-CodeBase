#define MoMaxSpeed1 75
#define MoMaxSpeed2 75
#define MoMaxSpeed3 75
#define MoMaxSpeed4 75

void Motor(int S1 = 75, int S2 = 75, int S3 = 75, int S4 = 75) {
  motor(1, constrain(S1, -100, MoMaxSpeed1));  // หน้าซ้าย
  motor(2, constrain(S2, -100, MoMaxSpeed2));  // หน้าขวา
  motor(3, constrain(S3, -100, MoMaxSpeed3));  // หลังซ้าย
  motor(4, constrain(S4, -100, MoMaxSpeed4));  // หลังขวา
}

void FF(int S = 75, int timeout = 500) {
  Motor(S, S, S, S);
  delay(timeout);
  ao();
}

void TT(int S = 75, int timeout = 500) {
  Motor(-S, S, -S, S);
  delay(timeout);
  ao();
}

void SL(int S = 75, int timeout = 500) {
  Motor(-S, S, S, -S);
  delay(timeout);
  ao();
}

void SR(int S = 75, int timeout = 500) {
  Motor(S, -S, -S, S);
  delay(timeout);
  ao();
}
