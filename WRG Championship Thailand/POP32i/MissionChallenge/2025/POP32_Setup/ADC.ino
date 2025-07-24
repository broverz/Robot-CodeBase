void ShowADC() {
  l1 = analog(4);
  l = analog(3);
  c = analog(2);
  r = analog(1);
  r1 = analog(0);
  ADC();
}

inline int toBinary(int value, int ref) {
  return (value < ref) ? 0 : 1;
}

void ConvertADC(bool showADC = false) {
  l1 = toBinary(analog(4), RefL1);
  l = toBinary(analog(3), RefL);
  c = toBinary(analog(2), RefC);
  r = toBinary(analog(1), RefR);
  r1 = toBinary(analog(0), RefR1);
  if (showADC) ADC();
}

void CalError() {
  ConvertADC(true);
  if ((l1 == 1) && (l == 1) && (c == 1) && (r == 1) && (r1 == 0)) Error = 4;
  else if ((l1 == 1) && (l == 1) && (c == 1) && (r == 0) && (r1 == 0)) Error = 3;
  else if ((l1 == 1) && (l == 1) && (c == 1) && (r == 0) && (r1 == 1)) Error = 2;
  else if ((l1 == 1) && (l == 1) && (c == 0) && (r == 0) && (r1 == 1)) Error = 1;
  else if ((l1 == 1) && (l == 1) && (c == 0) && (r == 1) && (r1 == 1)) Error = 0;
  else if ((l1 == 1) && (l == 0) && (c == 0) && (r == 1) && (r1 == 1)) Error = -1;
  else if ((l1 == 1) && (l == 0) && (c == 1) && (r == 1) && (r1 == 1)) Error = -2;
  else if ((l1 == 0) && (l == 0) && (c == 1) && (r == 1) && (r1 == 1)) Error = -3;
  else if ((l1 == 0) && (l == 1) && (c == 1) && (r == 1) && (r1 == 1)) Error = -4;
  else if ((l1 == 0) && (l == 0) && (c == 0) && (r == 0) && (r1 == 0)) Error = 100;
}

void ADC() {
  oled.text(2, 0, "L1 = %d", l1);
  oled.text(3, 0, "L = %d", l);
  oled.text(4, 0, "C = %d", c);
  oled.text(5, 0, "R = %d", r);
  oled.text(6, 0, "R1 = %d", r1);
  oled.show();
}