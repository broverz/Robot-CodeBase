int lastError = 0;
float kp = 6, ki = 0, kd = 3;
float integral = 0;

int baseSpeed = 35;

void ConvertADC(bool showADC = false);

void LineTracing() {
  beep();
  oled.clear();
  while (true) {
    // ShowADC();
    CalError();
    if (Error == 100) {
      motor(Motor_Left, 0);
      motor(Motor_Right, 0);
      break;
    }
    int pid = computePID(Error);
    motor(Motor_Left, baseSpeed + pid);
    motor(Motor_Right, baseSpeed - pid);
  }
  showMessageCenter("Press A to go to the next step");
}

int computePID(int error) {
  integral += error;
  int derivative = error - lastError;
  lastError = error;
  return kp * error + ki * integral + kd * derivative;
}