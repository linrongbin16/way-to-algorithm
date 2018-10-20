#include "PrimeSieve.h"
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;

static void AssertPrime(int k) {
  int mod_count = 0;
  int sqrt_k = (int)sqrt((double)k);
  for (int i = 2; i <= sqrt_k; i++) {
    assert(k % i != 0);
  }
}

void TestSmall() {
  int n = 100000;
  BitVec *b = SimpleSieve(n);
  for (int i = 2; i < n; i++) {
    if (IsPrime(b, i)) {
      AssertPrime(i);
    }
  }
}

void TestBig() {
  int n = INT_MAX / 10;

  time_t beg, end;
  std::cerr << "Big Test on: " << n << std::endl;
  beg = std::time(0);
  std::cerr << "SimpleSieve start at: " << beg << std::endl;
  BitVec *ss = SimpleSieve(n);
  end = std::time(0);
  std::cerr << "SimpleSieve end at: " << end << std::endl;
  std::cerr << "SimpleSieve used: " << (end - beg) << " seconds" << std::endl;

  std::cerr << "EratosthenesSieve on: " << n << std::endl;
  beg = std::time(0);
  std::cerr << "EratosthenesSieve start at: " << beg << std::endl;
  BitVec *es = EratosthenesSieve(n);
  end = std::time(0);
  std::cerr << "EratosthenesSieve end at: " << end << std::endl;
  std::cerr << "EratosthenesSieve used: " << (end - beg) << " seconds"
            << std::endl;
  for (int i = 2; i < n; i++) {
    assert(IsPrime(ss, i) == IsPrime(es, i));
  }
  BitVecFree(ss);
  BitVecFree(es);
}

int main(void) {
  TestSmall();
  TestBig();
  return 0;
}

