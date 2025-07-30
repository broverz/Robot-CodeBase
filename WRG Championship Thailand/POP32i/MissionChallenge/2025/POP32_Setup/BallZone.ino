void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);
void gyroFF(int timeout = 140, int baseSpeed = 100);
void gyroFL(int deg = 41, int timeoutFF = 0);
void gyroFR(int deg = 41, int timeoutFF = 0);
void fanMotor(int timeout = 1000);

void BallZone() {
  beep();
  showMessageCenter("Ball Zone");
  servo(4, 152);
  servo(5, 152);
  servo(6, 152);
  while (true) {
    // gyroFF(190, 100);
    // fanMotor(5000);
    // gyroFF(12000, 45);
    break;
  }
  showMessageCenter("End Game");
}

void fanMotor(int timeout = 1000) {
  motor(3, 100);
  motor(4, 100);
  sleep(timeout);
}