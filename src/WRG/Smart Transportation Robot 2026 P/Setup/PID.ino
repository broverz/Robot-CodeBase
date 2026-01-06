#define NUM_SENSORS 5

// int sensorPin[NUM_SENSORS] = {A1, A2, A3};
// int sensorVal[NUM_SENSORS];
// int baseLight[NUM_SENSORS] = {
//   3900,
//   3800,
//   3800
// };
// int weight[NUM_SENSORS] = {-1, 0, 1};

int sensorPin[NUM_SENSORS] = { A0, A1, A2, A3, A4 };
int sensorVal[NUM_SENSORS];
int baseLight[NUM_SENSORS] = {
  3500,
  3540,
  3550,
  3120,
  3500
};
float weight[NUM_SENSORS] = { -3, -1.5, 0, 1.5, 3 };

double readLinePosition() {
  double sum = 0;
  double total = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorVal[i] = analogRead(sensorPin[i]);

    double value = baseLight[i] - sensorVal[i];
    if (value < 0) value = 0;

    sum += value * weight[i];
    total += value;
  }

  if (total == 0) return 0;
  return sum / total;
}

bool isCenterAllBlack() {
  int centerIndex[3] = { 1, 2, 3 };

  for (int i = 0; i < 3; i++) {
    int idx = centerIndex[i];
    if (analogRead(sensorPin[idx]) >= baseLight[idx]) {
      return false;
    }
  }
  return true;
}

bool isAllBlack() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (analogRead(sensorPin[i]) >= baseLight[i]) {
      return false;
    }
  }
  return true;
}

void lineTrackingPID(int slow = 0, unsigned long timeout = 0, unsigned long timeoutSlow = 0) {
  unsigned long startTime = millis();

  while (true) {
    if (timeout > 0) {
      if (millis() - startTime >= timeout) {
        ao();
        pid.Reset();
        return;
      }
    }

    lineInput = readLinePosition();
    if (isCenterAllBlack()) {
      ao();
      pid.Reset();
      return;
    }

    pid.Compute();
    lineOutput = constrain(lineOutput, -60, 60);

    int leftSpeed, rightSpeed;
    if (slow == 1) {
      leftSpeed = 40 - lineOutput;
      rightSpeed = 41 + lineOutput;
    } else {
      leftSpeed = 57 - lineOutput;
      rightSpeed = 54 + lineOutput;
      if (timeoutSlow > 0) {
        if (millis() - startTime >= timeoutSlow) {
          leftSpeed = 40 - lineOutput;
          rightSpeed = 41 + lineOutput;
        }
      }
    }

    leftSpeed = constrain(leftSpeed, 0, 100);
    rightSpeed = constrain(rightSpeed, 0, 100);

    motor(3, leftSpeed);
    motor(1, rightSpeed);

    // delay(5);
  }
}
