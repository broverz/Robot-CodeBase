#include <POP32.h>

int l1, l, c, r, r1;

int RefL1 = 3619;
int RefL = 3617;
int RefC = 3616;
int RefR = 3615;
int RefR1 = 3620;

int Error, PreError, Integral;

#include "Wire.h"
#include <MPU6050_light.h>
#include <QuickPID.h>

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
