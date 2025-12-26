void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false);

#define sv1Open 20
#define sv1Close 90
#define sv2Open 160
#define sv2Close 90

void grabBk() {
  mManual(0, 0); ao();
  sv1.attach(sv1PIN);
  sv2.attach(sv2PIN);

  sv1.write(sv1Open);
  sv2.write(sv1Close);
  delay(300);

  sv1.write(sv2Open);
  sv2.write(sv2Close);
  delay(500);

  sv1.detach();
  sv2.detach();

  beep();
}
