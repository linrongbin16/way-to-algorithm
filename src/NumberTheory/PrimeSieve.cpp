#include "PrimeSieve.h"
#include <cassert>
#include <cstring>

// 使用字节操作支持更大的素数
// 每个bit表示一个数字是否为素数

#define TABLE_SIZE 4096
#define CHAR_SIZE (TABLE_SIZE * 8)
#define int_div(a, b) ((a) / (b))
#define int_mod(a, b) ((a) & ((b)-1))
#define table_count(n) (int_div(n, CHAR_SIZE) + 1)
#define table_index(n) int_div(n, CHAR_SIZE)
#define char_index(n) (int_mod(n, CHAR_SIZE) / 8)
#define bit_index(n) int_mod(n, 8)

#define bit_set(tb, n)                                                         \
  do {                                                                         \
    (tb)[table_index(n)][char_index(n)] |= (1 << bit_index(n));                \
  } while (0)

#define bit_reset(tb, n)                                                       \
  do {                                                                         \
    (tb)[table_index(n)][char_index(n)] &= ~(1 << bit_index(n));               \
  } while (0)

#define bit_get(tb, n) ((tb)[table_index(n)][char_index(n)])

PrimeTable *PrimeTableNew(int n, enum PrimeTableType type) {
  PrimeTable *p = new PrimeTable();
  p->n = n;
  int tb_cnt = table_count(n);
  p->table.uchar_table = new unsigned char *[tb_cnt];
  for (int i = 0; i < tb_cnt; i++) {
    p->table.uchar_table[i] = new unsigned char[TABLE_SIZE];
    std::memset(p->table.uchar_table[i], 0, TABLE_SIZE);
  }
  return p;
}

void PrimeTableFree(PrimeTable *p) {
  assert(p);
  int tb_cnt = table_count(p->n);
  for (int i = 0; i < tb_cnt; i++) {
    delete[] p->bits[i];
  }
  delete[] p->bits;
  if (p->flags) {
    delete[] p->flags;
  }
}

PrimeTable *EratosthenesSieve(int n) {
  for (int i = 0; i < n; i++) {
    bit_set(p->bits, i);
  }

  bit_reset(p->bits, 0);
  bit_reset(p->bits, 1);

  for (int i = 2; i < n; i++) {
    if (bit_get(p->bits, i)) {
      for (int j = i * 2; j < n; j += i)
        bit_reset(p->bits, j);
    }
  }
  return p;
}

PrimeTable *EulerSieve(int n) {
  PrimeTable *p = new PrimeTable();
  p->n = n;
  int tb_cnt = table_count(n);
  p->bits = new unsigned char *[tb_cnt];
  p->flags = new unsigned char *[tb_cnt];
  for (int i = 0; i < tb_cnt; i++) {
    p->bits[i] = new unsigned char[TABLE_SIZE];
    p->flags[i] = new unsigned char[TABLE_SIZE];
    std::memset(p->bits[i], 0, TABLE_SIZE);
    std::memset(p->flags[i], 0, TABLE_SIZE);
  }

  for (int i = 2; i < n; i++) {
    if (!bit_get(p->flags, i)) {
      bit_set(p->bits, i);
    }
    for (int j = 0; i * prime[j] < n; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }

  return prime;
}

bool IsPrime(const PrimeTable *p, int x) {}

