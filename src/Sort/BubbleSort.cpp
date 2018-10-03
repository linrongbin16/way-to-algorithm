#include "BubbleSort.h"
#include <utility>

void BubbleSort(int *s, int beg, int end) {
  for (int i = end - 1; i >= beg; i--)
    for (int j = beg; j < i; j++)
      if (s[j] > s[j + 1])
        std::swap(s[j], s[j + 1]);
}

