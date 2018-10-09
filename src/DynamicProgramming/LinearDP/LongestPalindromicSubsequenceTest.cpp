#include "LongestPalindromicSubsequence.h"
#include <cassert>
#include <iostream>
#include <utility>
using namespace std;

#define TEST_MAX 1024

struct Test {
  int a[TEST_MAX];
  int n;
  pair<int, int> result;
} test_cases[] = {
    {{0, 1, 2, 3, 4, 5, 4, 3, 2, 9, 10}, 10, {2, 8}},   // 0
    {{0, 1, 3, 5, 15, 9, 11, 9, 15, 9}, 9, {4, 8}},     // 1
    {{0, 1, 2, 3, 3, 2, 10, 9, 9, 10, 2}, 10, {5, 10}}, // 2
    {{0, 42, 42,  5,  14, 14, 5,  -42, 14, 31,
      0, 12, 142, -5, 61, 42, 45, 42,  61, 41},
     19,
     {14, 18}},
    {{0, 12, 142, -5, 14, 15, 45, 42,  61, 41,
      0, 42, 42,  -5, 14, -5, 45, -42, 1,  31},
     19,
     {13, 15}},
    {{0, 1, 2, 1, 2, 3}, 5, {1, 3}},
};

int main(void) {
  for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
    Test &t = test_cases[i];
    pair<int, int> r = LongestPalindromicSubsequence(t.a, t.n);
    assert(r == t.result);
  }

  return 0;
}

