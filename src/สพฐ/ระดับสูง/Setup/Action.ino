void FA(int S = 75);
void FF(int timeout = 500, int S = 75);
void FT(int timeout = 500, int S = 75);
void TT(int timeout = 500, int S = 75);
// void gyroFF(int timeMs, int speed = 75);
// void gyroFL(float angle);
// void gyroFR(float angle);

void StartM() {
  // resetYaw();
  delay(500);

  FA(75);
  // FT(3000);
}

void CheckLight() {
  while (true) {
    oled.clear();
    oled.text(0, 0, "L  = %d", analogRead(A3));
    oled.text(1, 0, "LL  = %d", analogRead(A2));
    oled.text(2, 0, "RR  = %d", analogRead(A1));
    oled.text(3, 0, "R = %d", analogRead(A0));

    oled.text(6, 0, "BL = %d", analogRead(A8));
    oled.text(7, 0, "BR = %d", analogRead(A7));
    oled.show();
  }
}