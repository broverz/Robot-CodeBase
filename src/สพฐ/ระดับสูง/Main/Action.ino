void FF(int S = 75, int timeout = 500);
void TT(int S = 75, int timeout = 500);

void Start() {
  delay(500);

  FF(75, 1550);
  TT(-75, 385);
}