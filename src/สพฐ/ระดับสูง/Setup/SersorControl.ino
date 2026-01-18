float rgbToHue(uint16_t r, uint16_t g, uint16_t b) {
  float rf = r, gf = g, bf = b;

  float maxc = max(rf, max(gf, bf));
  float minc = min(rf, min(gf, bf));
  float delta = maxc - minc;

  if (delta == 0.0f) return 0.0f;

  float hue;
  if (maxc == rf)
    hue = 60.0f * fmodf((gf - bf) / delta, 6.0f);
  else if (maxc == gf)
    hue = 60.0f * (((bf - rf) / delta) + 2.0f);
  else
    hue = 60.0f * (((rf - gf) / delta) + 4.0f);

  if (hue < 0.0f) hue += 360.0f;
  return hue;
}

const char* checkColor(uint16_t r, uint16_t g, uint16_t b) {

  float rf = r / 65535.0f;
  float gf = g / 65535.0f;
  float bf = b / 65535.0f;

  float maxc = max(rf, max(gf, bf));
  float minc = min(rf, min(gf, bf));
  float delta = maxc - minc;

  float hue = rgbToHue(r, g, b);

  if ((hue <= 30) || (hue >= 330)) return "Red";
  if (hue <= 37) return "Yellow";
  if (hue <= 50) return "White";
  if (hue <= 80) return "Black";
  if (hue <= 150) return "Green";
  if (hue <= 210) return "Cyan";
  if (hue <= 270) return "Blue";
  if (hue <= 330) return "Magenta";

  return "Unknown";
}

void CheckColor() {
  while (1) {
    uint16_t r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);

    if (c > 0) {
      r = (float)r / c * 65535.0f;
      g = (float)g / c * 65535.0f;
      b = (float)b / c * 65535.0f;
    }
    float hue = rgbToHue(r, g, b);

    const char* color = checkColor(r, g, b);

    Serial.print("R: ");
    Serial.print(r);
    Serial.print("\n");
    Serial.print("G: ");
    Serial.print(g);
    Serial.print("\n");
    Serial.print("B: ");
    Serial.print(b);
    Serial.print("\n");
    Serial.print("Hue: ");
    Serial.print(hue);
    Serial.print("\n");
    Serial.print(" -> ");
    Serial.println(color);
    Serial.print("\n\n");

    showMessageCenter(color);
    delay(1);
  }
}