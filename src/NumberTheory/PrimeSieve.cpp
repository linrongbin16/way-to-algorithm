#include "PrimeSieve.h"
#include <cstring>

std::vector<int> EratosthenesSieve(int n) {
  std::vector<int> prime(n);
  for (int i = 0; i < n; i++) {
    prime[i] = 1;
  }

  prime[0] = 0;
  prime[1] = 0;

  for (int i = 2; i < n; i++) {
    if (prime[i]) {
      for (int j = i * 2; j < n; j += i)
        prime[j] = 0;
    }
  }
  return prime;
}

std::vector<int> EulerSieve(int n) {
  std::vector<int> prime(n);
  return prime;
}

