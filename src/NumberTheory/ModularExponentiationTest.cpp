#include "ModularExponentiation.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX 4096

int SimpleModularExp(int b, int e, int m) {
  int c = 1;
  for (int i = 0; i < e; i++) {
    c = (c * b) % m;
  }
  return c;
}

int main(void) {
  for (int i = 0; i < MAX; i++) {
    int b = abs(rand());
    int e = abs(rand());
    int m = abs(rand());
    int c = ModularExponentiation(b, e, m);
    assert(c == SimpleModularExp(b, e, m));
  }
  std::cout << std::endl;
  return 0;
}

