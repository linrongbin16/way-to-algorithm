#include "ExtendedEuclid.h"
#include "Util.h"
#include <cassert>
#include <tuple>
using namespace std;

#define MAX 4096

int main(void) {
  for (int i = 0; i < MAX; i++) {
    int a = abs(rand() % MAX);
    int b = abs(rand() % MAX);
    tuple<int, int, int> result = ExtendedEuclid(a, b);
    AssertGcd(a, b, get<0>(result));
    assert(a * get<1>(result) + b * get<2>(result) == get<0>(result));
  }
  return 0;
}

