#include "MergeSort.h"
#include <cstring>

static void Merge(int *s, int beg, int mid, int end) {
  int *t = new int[end + 1];
  int i = beg, j = mid, k = beg;

  while (i < mid || j < end) {
    if (i < mid && j < end) {
      if (s[i] < s[j]) {
        t[k++] = s[i++];
      } else {
        t[k++] = s[j++];
      }
    } else if (i < mid) {
      t[k++] = s[i++];
    } else if (j < end) {
      t[k++] = s[j++];
    }
  }

  std::memcpy(s + beg, t + beg, (end - beg) * sizeof(int));
  delete[] t;
}

void MergeSort(int *s, int beg, int end) {
  if (end >= beg + 2) {
    int mid = (beg + end) / 2;
    MergeSort(s, beg, mid);
    MergeSort(s, mid, end);
    Merge(s, beg, mid, end);
  }
}

