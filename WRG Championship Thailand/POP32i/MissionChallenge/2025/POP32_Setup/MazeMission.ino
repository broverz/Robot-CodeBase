void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    FF(100, 220);
    FL(100, 110);
    FF(-100, 225);
    FF(100, 580);
    // FL(100, 165);
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}