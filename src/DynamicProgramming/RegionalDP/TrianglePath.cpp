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

static std::pair<int, int> LineLeftRight(int n) {
  return std::make_pair(n * (n - 1) / 2, n * (n + 1) / 2);
}

static std::pair<int, int> UpValue(int *s, int i) {
  int h = Height(i);
  std::pair<int, int> upnode = LineLeftRight(h - 1);
  int lv, rv;
  int lu = i - h;
  if (lu < upnode.first || lu > upnode.second) {
    lv = INF;
  } else {
    lv = s[lu];
  }
  int ru = i - h + 1;
  if (ru < upnode.first || ru > upnode.second) {
    rv = INF;
  } else {
    rv = s[ru];
  }
  return std::make_pair(lv, rv);
}

int TrianglePath(int *s, int k) {
  int *f = ArrayNew(k + 1);
  for (int i = 0; i <= k; i++) {
    f[i] = 0;
  }
  for (int i = 1; i <= k; i++) {
    if (i == 1) {
      f[1] = s[1];
    } else {
      std::pair<int, int> up = UpValue(s, i);
      f[i] = std::min(up.first, up.second) + s[i];
    }
  }

  int result = INF;
  for (int i = Height(k); i <= k; i++) {
    result = std::min(result, f[i]);
  }
  ArrayFree(f);
  return result;
}

