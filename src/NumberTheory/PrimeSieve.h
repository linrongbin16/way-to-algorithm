#pragma once

struct PrimeTable {
  int n;
  union {
    int **int_table;
    unsigned char **uchar_table;
  } table;

  enum PrimeTableType { INT_TABLE, UCHAR_TABLE };
};

PrimeTable *PrimeTableNew(int n, enum PrimeTableType type);

void PrimeTableFree(PrimeTable *p);

PrimeTable *EratosthenesSieve(int n);

PrimeTable *EulerSieve(int n);

bool IsPrime(const PrimeTable *p, int x);

