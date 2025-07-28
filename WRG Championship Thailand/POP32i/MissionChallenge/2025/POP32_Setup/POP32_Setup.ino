#include <POP32.h>
#include <Servo.h>

#include "Wire.h"
#include <MPU6050_light.h>
#include <QuickPID.h>

int l1, l, c, r, r1;

const int RefL1 = 3617;
const int RefL = 3616;
const int RefC = 3615;
const int RefR = 3614;
const int RefR1 = 3618;

int Error;

const int Motor_Left = 1;
const int Motor_Right = 2;

MPU6050 mpu(Wire);
float currentAngle = 0.0;
float TurnOutput = 0.0;
float turnSetpoint = 0.0;
QuickPID turnPID(&currentAngle, &TurnOutput, &turnSetpoint);

Servo sv6;
Servo sv5;

void setup() {
	sv6.attach(6);
	sv5.attach(5);

	sv6.write(90);
	sv5.write(90);

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
