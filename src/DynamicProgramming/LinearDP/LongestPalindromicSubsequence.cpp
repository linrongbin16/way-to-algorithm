#include "LongestPalindromicSubsequence.h"
#include "../Util.h"
#include <algorithm>
#include <utility>

std::pair<int, int> LongestPalindromicSubsequence(const int *s, int n) {
  int **f = Array2DNew(n + 1, n + 1);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = (i == j);
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = k - 1, j = k + 1; i >= 1 && j <= n; i--, j++) {
      f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
    }
    for (int i = k, j = k + 1; i >= 1 && j <= n; i--, j++) {
      f[i][j] =
          (i + 1 == j) ? (s[i] == s[j]) : (f[i + 1][j - 1] && s[i] == s[j]);
    }
  }

  int maxlen = 0;
  int beg = 0, end = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (f[i][j]) {
        if (maxlen < j - i + 1) {
          maxlen = j - i + 1;
          beg = i;
          end = j;
        }
      }
    }
  }

  Array2DFree(f, n + 1);
  return std::make_pair(beg, end);
}

