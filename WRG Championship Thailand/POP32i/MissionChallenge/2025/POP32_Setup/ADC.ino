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
  if (l1 < RefL1) l1 = 0;
  else l1 = 1;
  if (l < RefL) l = 0;
  else l = 1;
  if (c < RefC) c = 0;
  else c = 1;
  if (r < RefR) r = 0;
  else r = 1;
  if (r1 < RefR1) r1 = 0;
  else r1 = 1;
  ADC();
}

void CalError() {
  ConvertADC();
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