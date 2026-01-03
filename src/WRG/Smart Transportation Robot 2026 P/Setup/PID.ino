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
  2460,
  3900,
  3700,
  3800,
  3800
};
int weight[NUM_SENSORS] = { -3, -1.5, 0, 1.5, 3 };

double readLinePosition() {
  long sum = 0;
  int countBlack = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorVal[i] = analogRead(sensorPin[i]);

    if (sensorVal[i] < baseLight[i]) {
      sum += weight[i];
      countBlack++;
    }
  }

  if (countBlack == 0) return 0;
  return (double)sum / countBlack;
}

bool isAllBlack() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (analogRead(sensorPin[i]) >= baseLight[i]) {
      return false;
    }
  }
  return true;
}

void lineTrackingPID() {
  while (true) {
    lineInput = readLinePosition();

    if (isAllBlack()) {
      ao();
      pid.Reset();
      return;
    }

    pid.Compute();
    lineOutput = constrain(lineOutput, -60, 60);

    Serial.print("Pos:");
    Serial.print(lineInput, 1);
    Serial.print(" Out:");
    Serial.print(lineOutput, 1);

    Serial.print(" [");
    int bars = map(lineOutput, -60, 60, -10, 10);
    for (int i = -10; i <= 10; i++) {
      if (i == 0) Serial.print("|");
      else if (i == bars) Serial.print("*");
      else Serial.print(" ");
    }
    Serial.print("]");

    int baseSpeed = 45;
    int leftSpeed = baseSpeed - lineOutput;
    int rightSpeed = baseSpeed + lineOutput;

    leftSpeed = constrain(leftSpeed, 0, 100);
    rightSpeed = constrain(rightSpeed, 0, 100);
    
    Serial.print(" L:");
    Serial.print(leftSpeed);
    Serial.print(" R:");
    Serial.println(rightSpeed);

    motor(3, leftSpeed);
    motor(1, rightSpeed);
    
    // delay(10);
  }
}
