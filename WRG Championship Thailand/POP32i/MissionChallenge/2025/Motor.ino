void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = true) {
  motor(1, lspeed);
  motor(4, rspeed);
  sleep(timeout);
  ao();
  if (doBeep) beep();
}