void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    FF(100, 212);
    FL(100, 166);
    FF(100, 538);
    FR(100, 108);
    FF(100, 225);
    FR(100, 145);

    FF(100, 315);
    FL(100, 165);
    FF(100, 295);
    FR(100, 160);
    FF(100, 270);
    FR(100, 155);

    FF(100, 260);
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}