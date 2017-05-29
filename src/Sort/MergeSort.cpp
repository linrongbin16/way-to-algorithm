#include "MergeSort.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;


auto AssertNotAscendingOrder(int s[MAX], int n) -> void
{
     bool res = true;
     for (int i = 0; i < n - 1; ++i) {
          if (s[i] > s[i + 1]) {
               res = false;
               break;
          }
     }
     assert(!res);
}
auto AssertAscendingOrder(int s[MAX], int n) -> void
{
     bool res = true;
     for (int i = 0; i < n - 1; ++i) {
          if (s[i] > s[i + 1]) {
               res = false;
               break;
          }
     }
     assert(res);
}
auto AssertMergeSort(int s[MAX], int n) -> void
{
     AssertNotAscendingOrder(s, n);
     MergeSort(s, 0, n);
     AssertAscendingOrder(s, n);
}


#define TEST_MAX 1024

auto main(void) -> int
{
     int s[MAX];

     for (int i = 0; i < TEST_MAX; ++i) {
          for (int j = 0; j < MAX; ++j) {
               s[j] = rand() % TEST_MAX;
          }
          AssertMergeSort(s, MAX);
     }

     return 0;
}
