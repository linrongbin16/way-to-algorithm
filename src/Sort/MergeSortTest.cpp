#include "MergeSort.h"
#include "Util.h"
#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX 1024

int main(void) {
  int s[MAX];
  for (int i = 1; i < MAX; i++) {
    std::cout << i << std::endl;
    for (int j = 0; j < i; j++) {
      s[j] = rand() % MAX;
    }
    MergeSort(s, 0, i);
    AssertAscend(s, i);
  }
  return 0;
}

