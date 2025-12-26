#include <NewPing.h>

#define TRIG_PIN A7
#define ECHO_PIN A8
NewPing sonar(TRIG_PIN, ECHO_PIN, 200);

int readDistance() {
  return sonar.ping_cm();
}
void mManual(int lspeed = 100, int rspeed = 100, int timeout = 500, bool doBeep = false);

void SLeft() {
  resetYaw();
  int d = readDistance();
  if (d > 0 && d < 15) {
    mManual(0, 0);
    ao();
  }

  gyroFF(300, 80);
  gyroFL(65);
  gyroFF(300, 80);

  ao();
}