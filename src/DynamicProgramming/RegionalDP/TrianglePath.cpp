#include "TrianglePath.h"
#include "../Util.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <utility>

static int Height(int i) {
  int n = (int)std::sqrt((double)2 * (double)i);
  for (; n < MAX; n++) {
    int left = (n - 1) * n / 2;
    int right = n * (n + 1) / 2;
    if (left <= i && i <= right) {
      return n;
    }
  }
  assert(n != MAX);
  return n;
}

static std::pair<int, int> Range(int n) {
  return std::make_pair(n * (n - 1) / 2 + 1, n * (n + 1) / 2);
}

int TrianglePath(int *s, int k) {
  assert(Range(Height(k)).second == k);

  int *f = ArrayNew(k + 1);
  for (int i = 0; i <= k; i++) {
    f[i] = 0;
  }
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      f[1] = s[1];
    } else {
      int h = Height(i);
      std::pair<int, int> up_node = Range(h - 1);
      int l = i - h;
      int r = i - h + 1;

      int lu_value, ru_value;
      if (l < up_node.first || l > up_node.second) {
        lu_value = INF;
      } else {
        lu_value = f[l];
      }
      if (r < up_node.first || r > up_node.second) {
        ru_value = INF;
      } else {
        ru_value = f[r];
      }
      f[i] = std::min(lu_value, ru_value) + s[i];
    }
  }

  int result = INF;
  for (int i = Range(Height(k)).first; i <= Range(Height(k)).second; i++) {
    result = std::min(result, f[i]);
  }
  ArrayFree(f);
  return result;
}

