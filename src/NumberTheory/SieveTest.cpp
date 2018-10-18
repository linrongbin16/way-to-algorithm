#include "Sieve.h"
#include <cassert>
#include <ctime>
#include <iostream>
#include <list>
#include <thread>
#include <utility>
#include <vector>
using namespace std;

#define CONCURRENCY (thread::hardware_concurrency())

static void AssertPrime(int k) {
  int mod_count = 0;
  for (int i = 1; i <= k; i++) {
    if (k % i == 0) {
      mod_count++;
    }
  }
  assert(mod_count == 2);
}

static void AssertPrimeRoutine(const tuple<int, vector<int> *> &args) {
  int mod = get<0>(args);
  vector<int> &vec = *(get<1>(args));
  for (int j = 0; j < vec.size(); j++) {
    if (j % CONCURRENCY == mod && vec[j]) {
      AssertPrime(j);
    }
  }
}

int main(void) {
  vector<int> prime = Sieve(499999);

  vector<thread *> workers;
  for (int i = 0; i < CONCURRENCY; i++) {
    workers.push_back(new thread(AssertPrimeRoutine, make_tuple(i, &prime)));
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i]->join();
  }
  return 0;
}

