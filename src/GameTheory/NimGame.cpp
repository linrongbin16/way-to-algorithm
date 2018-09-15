#include "NimGame.h"
#include <cmath>

bool NimGame(int *s, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum ^ s[i];
  }
  return sum != 0;
}

