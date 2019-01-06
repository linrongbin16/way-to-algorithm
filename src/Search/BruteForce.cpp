#include "BruteForce.h"
#include "Util.h"

std::vector<std::vector<int>> BruteForce(int *s, int n, int m) {
  std::vector<std::vector<int>> result;
  for (int i_0 = 0; i_0 < m; i_0++)
    for (int i_1 = 0; i_1 < m; i_1++)
      for (int i_2 = 0; i_2 < m; i_2++) /* ... */
        for (int i_n_1 = 0; i_n_1 < m; i_n_1++) {
          s[0] = i_0;
          s[1] = i_1;
          s[2] = i_2;
          /* ... */
          s[n - 1] = i_n_1;

          std::vector<int> vec;
          std::transform(s, s + n, std::back_inserter(vec), [](const int &v) { return v; });
          result.push_back(vec);
        }
  return result;
}

