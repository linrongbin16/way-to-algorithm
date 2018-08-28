#include "BinarySearch.h"

std::pair<bool, int> BinarySearch(int *s, int beg, int end, int x) {
  int low = beg;
  int high = end - 1;
  int mid;
  int index;
  while (low <= high) {
    mid = (low + high) / 2;
    if (s[mid] == x) {
      index = mid;
      return std::make_pair(true, index);
    } else if (s[mid] > x) {
      high = mid - 1;
    } else if (s[mid] < x) {
      low = mid + 1;
    }
  }
  return std::make_pair(false, -1);
}
