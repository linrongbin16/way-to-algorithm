#include "MergeSort.hpp"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;


void AssertNotAscendingOrder(int s[MAX], int n)
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
void AssertAscendingOrder(int s[MAX], int n)
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
void AssertMergeSort(int s[MAX], int n)
{
     AssertNotAscendingOrder(s, n);
     MergeSort(s, 0, n);
     AssertAscendingOrder(s, n);
}


#define TEST_MAX 1024

int main(void)
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
