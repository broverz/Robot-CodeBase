void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true);
void FF(int speed = 100, int timeout = 250);
void FL(int speed = 100, int timeout = 250);
void FR(int speed = 100, int timeout = 250);

// mManual กำหนดเอง
// FF เดินหน้าใส่ 100 ถอยหลัง -100
// FL เลื้ยวซ้าย
// FR เลื้ยวชวา

void MazeMission() {
  beep();
  oled.clear();
  oled.text(3, 4, "Maze Mission");
  oled.show();
  while (true) {
    FF(100, 210);
    FL(100, 96);
    // FF(-100, 225);
    FF(100, 465);
    FR(100, 102);
    FF(100, 210);
    FR(100, 102);
    FF(100, 255);
    FL(100, 102);
    FF(100, 250);
    FR(100, 102);
    FF(100, 250);
    FR(100, 102);
    break;
  }
  oled.clear();
  oled.text(3, 4, "Press B to go to the next step");
  oled.show();
}