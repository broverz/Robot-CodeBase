 void mManual(int lspeed = 100, int rspeed = 100, int timeout = 0, bool doBeep = false);

void grabBk() {
  mManual(0, 0); ao();

  servo(5, 80);
  delay(250);
  servo(6, 130);
  delay(500);

  servo(5, 125);
  delay(500);
  servo(6, 45);
  delay(500);

  beep();
}

void putBk() {
  mManual(0, 0); ao();

  servo(6, 110);
  delay(250);
  servo(5, 80);
  delay(500);

  servo(6, 45);
  delay(500);
  servo(5, 125);
  delay(500);

  beep();
}
