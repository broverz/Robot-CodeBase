#include <POP32.h>

#include "Wire.h"
#include <MPU6050_light.h>
#include <QuickPID.h>

int l1, l, c, r, r1;

int RefL1 = 3895;
int RefL = 3891;
int RefC = 3892;
int RefR = 3891;
int RefR1 = 3896;

int Error;

const int Motor_Left = 1;
const int Motor_Right = 2;

MPU6050 mpu(Wire);
float currentAngle = 0.0;
float TurnOutput = 0.0;
float turnSetpoint = 0.0;
QuickPID turnPID(&currentAngle, &TurnOutput, &turnSetpoint);

void setup() {
	Serial.begin(115200);
	Wire.begin();
	mpu.begin();
	mpu.calcOffsets(true, true);
	turnPID.SetOutputLimits(-255, 255);
	turnPID.SetTunings(2.0, 5.0, 1.0);

	ao();
	beep();

	oled.text(3, 4, "Sawas Dee Krub");
	oled.show();
}

void loop() {
	if (SW_OK()) LineTracing();
	if (SW_A()) MazeMission();
	if (SW_B()) BallZone();
}

void showMessageCenter(const char* msg) {
	oled.clear();
	oled.text(3, 4, msg);
	oled.show();
}
