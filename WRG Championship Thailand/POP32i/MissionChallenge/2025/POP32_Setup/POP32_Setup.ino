#include <POP32.h>

int l1, l, c, r, r1;

int RefL1 = 3719;
int RefL = 3717;
int RefC = 3719;
int RefR = 3715;
int RefR1 = 3710;

int Error, PreError, Integral;

void setup() {
	beep();
	oled.text(3, 4, "Sawas Dee Krub");
	oled.show();
}

void loop() {
	if (SW_OK()) LineTracing();
	if (SW_A()) MazeMission();
	if (SW_B()) BallZone();
}
