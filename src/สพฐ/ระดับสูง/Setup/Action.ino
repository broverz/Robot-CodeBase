void FA(int S = 75);
void FF(int timeout = 500, int S = 75);
void FT(int timeout = 500, int S = 75);
void TT(int timeout = 500, int S = 75);
void gyroFF(int timeMs, int speed = 75);
void gyroFL(float angle);
void gyroFR(float angle);

void StartM() {
  delay(50);
  resetYaw();
  delay(500);

  gyroFF(500, 60);
  gyroFR(38);
}

void CheckLight() {
  while (true) {
    oled.clear();
    oled.text(0, 0, "L  = %d", analogRead(A0));
    oled.text(1, 0, "C  = %d", analogRead(A1));
    oled.text(2, 0, "R = %d", analogRead(A2));

    oled.text(4, 0, "BL = %d", analogRead(A7));
    oled.text(5, 0, "BR = %d", analogRead(A8));
    oled.show();
  }
}