#include <POP32.h>
#include <math.h>

#include <Wire.h>
#include <I2Cdev.h>
#include <Adafruit_TCS34725.h>
// #include <MPU6050.h>

// MPU6050 mpu;

// int16_t gx, gy, gz;
// float yaw = 0;
// float currentYaw = 0;
// unsigned long lastTime;

Adafruit_TCS34725 tcs =
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,
                    TCS34725_GAIN_4X);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  // mpu.initialize();

  delay(100);
  if (!tcs.begin()) {
    Serial.println("TCS34725 not found. Check wiring.");
    while (1)
      ;
  }
  // if (!mpu.testConnection()) {
  //   Serial.println("MPU6050 NOT FOUND");
  //   while (1)
  //     ;
  // }
  // mpu.CalibrateGyro(6);
  // mpu.CalibrateAccel(6);
  // lastTime = millis();

  ao();
  servo(5, 100);
  servo(6, 100);
  beep();
  showMessageCenter("SSKW RB Ready");
}

void loop() {
  if (SW_OK()) StartM();
  if (SW_A()) CheckColor();
  if (SW_B()) CheckLight();
}

void showMessageCenter(const char* msg) {
  oled.clear();
  oled.text(3, 4, msg);
  oled.show();
}