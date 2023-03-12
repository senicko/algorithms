#include <iostream>

void drawTick(int length, int label) {
  for (int i = 0; i < length; ++i)
    std::cout << '-';

  if (label != -1)
    std::cout << ' ' << label;

  std::cout << '\n';
}

void drawInterval(int centerLength) {
  if (centerLength < 1)
    return;

  drawInterval(centerLength - 1);
  drawTick(centerLength, -1);
  drawInterval(centerLength - 1);
}

void drawRuler(int distance, int tickLength) {
  drawTick(tickLength, 0);
  for (int i = 1; i <= distance; i++) {
    drawInterval(tickLength - 1);
    drawTick(tickLength, i);
  }
}

int main() {
  drawRuler(3, 5);
  return 0;
}