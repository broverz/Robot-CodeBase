void BallZone() {
  beep();
  oled.clear();
  oled.text(3, 4, "Ball Zone");
  oled.show();
  while (true) {
    sleep(2000);
    break;
  }
  oled.clear();
  oled.text(3, 4, "End Game");
  oled.show();
}