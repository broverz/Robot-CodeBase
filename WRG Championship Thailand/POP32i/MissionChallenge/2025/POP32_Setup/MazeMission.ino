void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);
void gyroFF(int timeout = 140, int baseSpeed = 100);
void gyroFL(int deg = 41, int timeoutFF = 0);
void gyroFR(int deg = 41, int timeoutFF = 0);

void MazeMission() {
  beep();
  showMessageCenter("Maze Mission");
  while (true) {
    gyroFL(42,200);
    gyroFF(410);
    gyroFR(42);
    gyroFF(385);
    gyroFR(42);
    gyroFF(200);
    gyroFR(42);
    gyroFF(210);
    gyroFL(42);
    gyroFF(210);
    gyroFL(40);
    gyroFF(210);
    gyroFR(44);
    gyroFF(210);
    gyroFR(40);
    gyroFF(375);
    gyroFL(42);
    gyroFF(210);
    gyroFL(41);
    gyroFF(525);
    gyroFL(41.5);
    gyroFF(385);
    gyroFR(38);
    ao();
    break;
  }
  showMessageCenter("Press B to go to the next step");
}