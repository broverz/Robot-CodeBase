void CheckLight() {
  while (true) {
    oled.clear();
    oled.text(0, 0, "L  = %d", analogRead(A3));
    oled.text(1, 0, "LL  = %d", analogRead(A2));
    oled.text(2, 0, "RR  = %d", analogRead(A1));
    oled.text(3, 0, "R = %d", analogRead(A0));
    oled.show();
  }
}