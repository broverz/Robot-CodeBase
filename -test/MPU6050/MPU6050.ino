#include <POP32.h>

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void CheckDevice() {
  byte error, address;
  int nDevices = 0;
  Serial.println("Scanning I2C...");
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found");
  Serial.println("----------------------");
}

void CheckMotion() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("AX: ");
  Serial.print(ax);
  Serial.print(" AY: ");
  Serial.print(ay);
  Serial.print(" AZ: ");
  Serial.print(az);
  Serial.print(" | GX: ");
  Serial.print(gx);
  Serial.print(" GY: ");
  Serial.print(gy);
  Serial.print(" GZ: ");
  Serial.println(gz);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();

  while (!Serial)
    ;
  Serial.println("I2C + MPU6050 Tester");

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection())
    Serial.println("MPU6050 connection successful");
  else
    Serial.println("MPU6050 connection failed");

  Serial.println("Press SW_A = I2C Scan");
  Serial.println("Press SW_B = Read MPU6050");
}

void loop() {
  if (SW_A()) {
    CheckDevice();
    delay(500);
  }

  if (SW_B()) {
    CheckMotion();
    delay(300);
  }
}
