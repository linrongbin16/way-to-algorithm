#include "ExtendedEuclid.h"

std::tuple<int, int, int> ExtendedEuclid(int a, int b) {
  // step_{k}
  // a_{k} = a
  // b_{k} = b

  if (b == 0) {

    // b_{n+1} = 0
    // gcd_{n+1} = a_{n+1}
    // x_{n+1} = 1
    // y_{n+1} = 0

    return std::make_tuple(a, 1, 0);
  }

  // step_{k+1}
  // a_{k+1} = b_{k}
  // b_{k+1} = a_{k} % b_{k}

  std::tuple<int, int, int> temp = ExtendedEuclid(b, a % b);

  // temp_{0} = gcd(a_{k+1}, b_{k+1});
  // temp_{1} = x_{k+1}
  // temp_{2} = y_{k+1}

  // x_{k} = y_{k+1}
  // y_{k} = x_{k+1} - (a_{k} / b_{k}) * y_{k+1}

  int gcd = std::get<0>(temp);
  int x = std::get<2>(temp);
  int y = std::get<1>(temp) - (a / b) * std::get<2>(temp);

  // recursion return
  return std::make_tuple(gcd, x, y);
}

