#include <POP32.h>

#include <Wire.h>
#include <I2Cdev.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);

  ao();
  beep();
  showMessageCenter("SSKW RB Ready");
}

void loop() {
  if (SW_OK()) Start();
  if (SW_A()) CheckLight();
}

void showMessageCenter(const char* msg) {
  oled.clear();
  oled.text(3, 4, msg);
  oled.show();
}