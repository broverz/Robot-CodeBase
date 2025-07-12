void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    mManual(100, 100, 1500, true);
    mManual(100, -100, 150, true);
    mManual(100, 100, 150, true);
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}