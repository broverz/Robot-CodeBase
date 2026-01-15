void FF(int timeout = 500,int S = 75);
void TT(int timeout = 500,int S = 75);
void gyroFF(int timeMs, int speed = 75);
void gyroFL(float angle);
void gyroFR(float angle);

void Start() {
  resetYaw();
  delay(500);

  gyroFF(450);
  gyroFF(45);
}

void CheckLight() {
  while (true) {
    oled.clear();
    oled.text(0, 0, "L  = %d", analogRead(A3));
    oled.text(1, 0, "LL  = %d", analogRead(A2));
    oled.text(2, 0, "RR  = %d", analogRead(A1));
    oled.text(3, 0, "R = %d", analogRead(A0));
    oled.show();
  }
}