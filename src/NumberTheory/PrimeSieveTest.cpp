#include "PrimeSieve.h"
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

static void AssertPrimeRoutine(const tuple<int, BitVec *> &args) {
  int mod = get<0>(args);
  BitVec *b = get<1>(args);
  for (int j = 0; j < b->n; j++) {
    if (j % CONCURRENCY == mod && IsPrime(b, j)) {
      AssertPrime(j);
    }
  }
}

void TestSimplePrime(int n) {
  BitVec *b = SimpleSieve(n);
  vector<thread *> workers;
  for (int i = 0; i < CONCURRENCY; i++) {
    workers.push_back(new thread(AssertPrimeRoutine, make_tuple(i, b)));
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i]->join();
  }
  BitVecFree(b);
}

void TestEratosthenesSieve(int n) {
  BitVec *b = EratosthenesSieve(n);
  vector<thread *> workers;
  for (int i = 0; i < CONCURRENCY; i++) {
    workers.push_back(new thread(AssertPrimeRoutine, make_tuple(i, b)));
  }
  for (int i = 0; i < workers.size(); i++) {
    workers[i]->join();
  }
  BitVecFree(b);
}

int main(void) {
  TestSimplePrime(999999);
  TestEratosthenesSieve(999999);
  return 0;
}

