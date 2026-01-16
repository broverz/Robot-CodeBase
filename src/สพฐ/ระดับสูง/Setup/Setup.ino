#include <POP32.h>

#include <Wire.h>
#include <I2Cdev.h>
// #include <MPU6050.h>

// MPU6050 mpu;

// int16_t gx, gy, gz;
// float yaw = 0;
// float currentYaw = 0;
// unsigned long lastTime;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  // mpu.initialize();

  delay(100);
  // if (!mpu.testConnection()) {
  //   Serial.println("MPU6050 NOT FOUND");
  //   while (1)
  //     ;
  // }
  // mpu.CalibrateGyro(6);
  // mpu.CalibrateAccel(6);
  // lastTime = millis();
  
  ao();
  beep();
  showMessageCenter("SSKW RB Ready");
}

void loop() {
  if (SW_A()) StartM();
  if (SW_B()) CheckLight();
}

void showMessageCenter(const char* msg) {
  oled.clear();
  oled.text(3, 4, msg);
  oled.show();
}