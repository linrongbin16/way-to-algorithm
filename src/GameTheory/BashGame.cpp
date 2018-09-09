#include "BashGame.h"

bool BashGame(int n, int m) {
  int s = n % (m + 1);
  return s != 0;
}

