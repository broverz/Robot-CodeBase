void ShowADC() {
  l1 = analog(4);
  l = analog(3);
  c = analog(2);
  r = analog(1);
  r1 = analog(0);
  ADC();
}

void ConvertADC(bool showADC = false) {
  l1 = analog(4);
  l = analog(3);
  c = analog(2);
  r = analog(1);
  r1 = analog(0);

  l1 = (RefL1 <= l1) ? 1 : 0;
  l = (RefL <= l) ? 1 : 0;
  c = (RefC <= c) ? 1 : 0;
  r = (RefR <= r) ? 1 : 0;
  r1 = (RefR1 <= r1) ? 1 : 0;

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