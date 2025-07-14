#include <POP32.h>

int l1, l, c, r, r1;

int RefL1 = 1780;
int RefL = 1856;
int RefC = 1759;
int RefR = 1441;
int RefR1 = 2045;

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
