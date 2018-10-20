#include "PrimeSieve.h"
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>

// 使用字节操作支持更大的素数
// 每个bit表示一个数字是否为素数

#define TABLE_SIZE (4096 * 16)
#define int_div(a, b) ((a) / (b))
#define int_mod(a, b) ((a) & ((b)-1))
#define table_count(n) (int_div(n, TABLE_SIZE * 8) + 1)
#define table_index(n) int_div(n, TABLE_SIZE * 8)
#define char_index(n) (int_mod(n, TABLE_SIZE * 8) / 8)
#define bit_index(n) int_mod(n, 8)

#define bit_set(b, n)                                                          \
  do {                                                                         \
    (b)->bits[table_index(n)][char_index(n)] |= (1 << bit_index(n));           \
  } while (0)

#define bit_reset(b, n)                                                        \
  do {                                                                         \
    (b)->bits[table_index(n)][char_index(n)] &= ~(1 << bit_index(n));          \
  } while (0)

#define bit_get(b, n)                                                          \
  ((b)->bits[table_index(n)][char_index(n)] & (1 << bit_index(n)))

static BitVec *BitVecNew(int n) {
  BitVec *b = new BitVec();
  b->n = n;
  int tb_cnt = table_count(n);
  b->bits = new unsigned char *[tb_cnt];
  for (int i = 0; i < tb_cnt; i++) {
    b->bits[i] = new unsigned char[TABLE_SIZE];
    std::memset(b->bits[i], 0, TABLE_SIZE);
  }
  return b;
}

void BitVecFree(BitVec *b) {
  assert(b);
  int tb_cnt = table_count(b->n);
  for (int i = 0; i < tb_cnt; i++) {
    delete[] b->bits[i];
  }
  delete[] b->bits;
}

bool IsPrime(const BitVec *b, int x) { return bit_get(b, x); }

BitVec *SimpleSieve(int n) {
  BitVec *b = BitVecNew(n);
  for (int i = 2; i < n; i++) {
    int sqrt_i = sqrt((double)i);
    bool is_prime = true;
    for (int j = 2; j <= sqrt_i; j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      bit_set(b, i);
    }
  }
  return b;
}

BitVec *EratosthenesSieve(int n) {
  BitVec *b = BitVecNew(n);

  for (int i = 0; i < n; i++) {
    bit_set(b, i);
  }

  bit_reset(b, 0);
  bit_reset(b, 1);

  for (int i = 2; i < n; i++) {
    if (bit_get(b, i)) {
      for (int j = i * 2; j < n; j += i)
        bit_reset(b, j);
    }
  }
  return b;
}

