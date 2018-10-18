#include "ExtendedEuclid.h"

std::tuple<int, int, int> ExtendedEuclid(int a, int b) {
  if (b == 0) {
    return std::make_tuple(a, 1, 0);
  }
  std::tuple<int, int, int> temp = ExtendedEuclid(b, a % b);
  int gcd = std::get<0>(temp);
  int x = std::get<1>(temp);
  int y = std::get<2>(temp);
  return std::make_tuple(gcd, x, y);
}

