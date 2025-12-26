#include <POP32.h>

#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Servo.h>

MPU6050 mpu;

Servo sv1;
Servo sv2;

#define sv1PIN 6
#define sv2PIN 5

int16_t gx, gy, gz;
float yaw = 0;
float currentYaw = 0;
unsigned long lastTime;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  delay(100);

  if (!mpu.testConnection()) {
    Serial.println("MPU6050 NOT FOUND");
    while (1)
      ;
  }
  mpu.CalibrateGyro(6);
  mpu.CalibrateAccel(6);
  lastTime = millis();

  sv1.attach(sv1PIN);
  sv2.attach(sv2PIN);

  sv1.detach();
  sv2.detach();
  
  ao();
  beep();
  showMessageCenter("SSKW RB Ready");
}

void loop() {
  if (SW_A()) SLeft();
  if (SW_B()) SRight();
}

void showMessageCenter(const char* msg) {
  oled.clear();
  oled.text(3, 4, msg);
  oled.show();
}
