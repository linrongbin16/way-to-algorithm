#include "Sieve.h"
#include <cassert>
#include <list>
#include <thread>
#include <vector>
using namespace std;

#define CONCURRENCY 32

static void AssertPrime(int k) {
  int mod_count = 0;
  for (int i = 1; i <= k; i++) {
    if (k % i == 0) {
      mod_count++;
    }
  }
  assert(mod_count == 2);
}

static void AssertPrimeRoutine(int i, const vector<int> &prime) {
  for (int j = 0; j < prime.size(); j++) {
    if (j % CONCURRENCY == i) {
      AssertPrime(prime[j]);
    }
  }
}

int main(void) {
  vector<int> prime = Sieve(99999);

  vector<thread> workers;
  for (int i = 0; i < CONCURRENCY; i++) {
    thread t = thread(AssertPrimeRoutine, i, &prime);
    workers.push_back(t);
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i].join();
  }
  return 0;
}

