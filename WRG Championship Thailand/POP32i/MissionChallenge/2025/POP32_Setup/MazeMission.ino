void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);
void GYROFF(int timeout = 140);
void GYROFL(int deg = 61, int timeoutFF = 0);
void GYROFR(int deg = 61, int timeoutFF = 0);

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    // FF(100, 212);
    // FL(100, 130);
    // FF(100, 360);
    GYROFF(110);
    GYROFL(42);
    GYROFF(400);
    GYROFR(40);
    GYROFF(190);
    GYROFR(40);
    GYROFF(190);
    GYROFL(42);
    GYROFF(190);
    ao();
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}