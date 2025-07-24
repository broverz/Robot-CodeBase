float Kp = 15.0;
float Ki = 0.0;
float Kd = 8.0;

float integral = 0.0;
int lastError = 0;
int baseSpeed = 50;
int maxSpeed = 100;

void ConvertADC(bool showADC = false);

void LineTracing() {
  beep();
  oled.clear();
  while (true) {
    // ShowADC();
    CalError();
    // if (Error == 100) {
    //   motor(Motor_Left, 0);
    //   motor(Motor_Right, 0);
    //   break;
    // }

    // PIDControl();
    // delay(10);
  }
  showMessageCenter("Press A to go to the next step");
}

void PIDControl() {
  CalError();

  if (Error == 100) {
    motor(Motor_Left, 0);
    motor(Motor_Right, 0);
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

  motor(Motor_Left, leftSpeed);
  motor(Motor_Right, rightSpeed);
}