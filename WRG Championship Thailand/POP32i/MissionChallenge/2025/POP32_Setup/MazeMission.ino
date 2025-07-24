void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);
void GYROFF(int timeout = 140);
void GYROFL(int deg = 41, int timeoutFF = 0);
void GYROFR(int deg = 41, int timeoutFF = 0);

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    GYROFF(110);
    GYROFL(40);
    GYROFF(410);
    GYROFR(40);
    GYROFF(190);
    GYROFR(40);
    GYROFF(180);
    GYROFL(48);
    GYROFF(230);
    GYROFR(40);
    GYROFF(200);
    GYROFR(40);
    GYROFF(220);
    GYROFL(38);
    GYROFF(350);
    GYROFL(48);
    GYROFF(376);
    GYROFL(38);
    GYROFF(235);
    GYROFR(38);
    ao();
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}