void LineTracing() {
  beep();
  oled.clear();
  while (true) {
    ShowADC();

    // sleep(2000);
    // break;
  }
  oled.clear();
  oled.text(3, 4, "Press A to go to the next step");
  oled.show();
}