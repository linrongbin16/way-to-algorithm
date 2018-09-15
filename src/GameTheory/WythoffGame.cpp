#include "WythoffGame.h"
#include <cmath>

double phi = ((double)1.0 + (double)sqrt(5.0f)) / (double)2.0;

bool WythoffGame(int p, int k) {
  int xa = (int)((double)k / phi);
  int xb = (int)((double)k * phi) + 1;
  int yc = (int)((double)p * phi) + 1;
  int yd = (int)((double)p / phi);

  // 边缘点必输
  // 否则必赢
  return !(k == yc || k == yd || p == xa || p == xb);
}

