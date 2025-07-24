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
    gyroFF(110);
    gyroFL(40);
    gyroFF(410);
    gyroFR(40);
    gyroFF(190);
    gyroFR(40);
    gyroFF(180);
    gyroFL(48);
    gyroFF(230);
    gyroFR(40);
    gyroFF(200);
    gyroFR(40);
    gyroFF(220);
    gyroFL(38);
    gyroFF(350);
    gyroFL(48);
    gyroFF(376);
    gyroFL(38);
    gyroFF(235);
    gyroFR(38);
    ao();
    break;
  }
  showMessageCenter("Press B to go to the next step");
}