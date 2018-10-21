#include "ModularExponentiation.h"

#define INT_BIT 30

int ModularExponentiation(int b, int e, int m) {
  int c = 1;
  for (int i = 0; i < INT_BIT && ((1 << i) < e); i++) {
    int exp_val = 1 << i;
    if (e & exp_val) {
      int temp = 1;
      for (int j = 0; j < exp_val; j++) {
        temp = (temp * b) % m;
      }
      c = (c * temp) % m;
    }
  }
  return c;
}

