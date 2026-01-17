#define Servo1 5
#define Servo2 6

void openBk(int Bk = 1) {
  switch (Bk) {
    case 1:
      servo(Servo1, 180);
      delay(550);
      servo(Servo1, 28);
      break;
    case 2:
      servo(Servo1, 180);
      delay(550);
      servo(Servo1, 28);
      break;
    case 3:
      servo(Servo2, 180);
      delay(550);
      servo(Servo2, 28);
      break;
    case 4:
      servo(Servo2, 180);
      delay(550);
      servo(Servo2, 28);
      break;
  }
}

void closeBk() {
  servo(Servo2, 28);
  servo(Servo2, 28);
}