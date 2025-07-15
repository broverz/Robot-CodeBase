void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true) {
  motor(1, lspeed);
  motor(4, rspeed);
  sleep(timeout);
  ao();
  if (doBeep) beep();
}

void FF(int speed = 100, int timeout = 250) {
  mManual(speed, speed, timeout);
  mManual(-speed, -speed, 50);
}

void FL(int speed = 100, int timeout = 250) {
  mManual(speed, -speed, timeout);
  mManual(-speed, speed, 25);
  //  mManual(-speed, -speed, 100);
}

void FR(int speed = 100, int timeout = 250) {
  mManual(-speed, speed, timeout);
  mManual(speed, -speed, 25);
  //  mManual(-speed, -speed, 100);
}