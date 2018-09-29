#include "BinarySearch.h"
#include <utility>

std::pair<bool, int> BinarySearch(int *s, int beg, int end, int x) {
  int low = beg;
  int high = end - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (s[mid] == x) {
      return std::make_pair(true, mid);
    } else if (s[mid] > x) {
      high = mid - 1;
    } else if (s[mid] < x) {
      low = mid + 1;
    }
  }
  return std::make_pair(false, -1);
}

