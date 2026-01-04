#include <POP32.h>

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <QuickPID.h>

MPU6050 mpu;

float Kp = 18.0f;
float Ki = 0.0f;
float Kd = 5.0f;

float lineInput = 0;
float lineOutput = 0;
float lineSetpoint = 0;

QuickPID pid(&lineInput, &lineOutput, &lineSetpoint,
             Kp, Ki, Kd,
             QuickPID::Action::direct);

#define sv1PIN 1
#define sv2PIN 2

int16_t gx, gy, gz;
float yaw = 0;
float currentYaw = 0;
unsigned long lastTime;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  pid.SetMode(QuickPID::Control::automatic);
  pid.SetOutputLimits(-60, 60);
  pid.SetSampleTimeUs(10000);
  pid.SetTunings(Kp, Ki, Kd);

  delay(100);

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 NOT FOUND");
    while (1)
      ;
  }
  mpu.CalibrateGyro(6);
  mpu.CalibrateAccel(6);
  lastTime = millis();

  servo(5, 125);
  servo(6, 25);

  ao();
  beep();
  showMessageCenter("SSKW RB Ready");
}

void loop() {
  if (SW_A()) SLeft();
  if (SW_OK()) SRight();
  if (SW_B()) CheckLight();
}

void showMessageCenter(const char* msg) {
  oled.clear();
  oled.text(3, 4, msg);
  oled.show();
}
