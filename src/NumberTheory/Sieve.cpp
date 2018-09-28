#include "Sieve.h"
#include <cstring>

std::vector<int> Sieve(int n) {
  std::vector<int> prime(n);
  std::memset(prime.data(), 1, sizeof(int) * n);

  prime[0] = 0;
  prime[1] = 0;
  prime[2] = 1;
  for (int i = 3; i < n; i += 2) {
    if (i + 1 < n) {
      prime[i + 1] = 0;
    }
    if (prime[i]) {
      for (int j = i * 2; j < n; j += i)
        prime[j] = 0;
    }
  }
  return prime;
}

