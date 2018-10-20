#include "ModularLinearEquations.h"
#include "Euclid.h"
#include "ExtendedEuclid.h"

int ModularLinearEquations(int *a, int *m, int n) {
  int x = 1;
  for (int i = 0; i < n - 1; i++) {
    std::tuple<int, int, int> temp = ExtendedEuclid(a[i], a[i + 1]);
    x = LeastCommonMultiple(x, std::get<1>(temp));
    x = LeastCommonMultiple(x, std::get<2>(temp));
  }
  return x;
}

