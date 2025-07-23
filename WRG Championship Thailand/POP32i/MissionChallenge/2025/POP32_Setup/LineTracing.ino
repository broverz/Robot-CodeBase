float Kp = 15.0;
float Ki = 0.0;
float Kd = 8.0;

int lastError = 0;
float integral = 0;
int baseSpeed = 50;
int maxSpeed = 100;

void ConvertADC(bool showADC = false);

void LineTracing() {
  beep();
  oled.clear();
  while (true) {
    ShowADC(); // ConvertADC();
    // CalError();
    // if (Error == 100) {
    //   motor(4, 0);
    //   motor(1, 0);
    //   break;
    // }

    // PIDControl();
    // delay(10);
  }
  oled.clear();
  oled.text(3, 4, "Press A to go to the next step");
  oled.show();
}

void PIDControl() {
  CalError();

  if (Error == 100) {
    motor(4, 0);
    motor(1, 0);
    return;
  }

  int P = Error;
  integral += Error;
  int D = Error - lastError;
  lastError = Error;

  float correction = (Kp * P) + (Ki * integral) + (Kd * D);

  int leftSpeed = baseSpeed - correction;
  int rightSpeed = baseSpeed + correction;

  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);

  motor(1, leftSpeed);
  motor(4, rightSpeed);
}