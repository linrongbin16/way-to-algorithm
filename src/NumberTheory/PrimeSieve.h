#pragma once
#include <vector>

struct BitVec {
  int n;
  unsigned char **bits;
};

BitVec *SimpleSieve(int n);

BitVec *EratosthenesSieve(int n);

bool IsPrime(const BitVec *p, int x);

void BitVecFree(BitVec *p);

