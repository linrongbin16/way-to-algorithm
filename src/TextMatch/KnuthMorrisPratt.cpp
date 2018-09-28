#include "KnuthMorrisPratt.h"
#include <string>
#include <vector>

// pmt[i] =
//\begin{matrix}
//                -1       &   i = 0   \\
//-1       &   0 \lt i \lt m, pattern[pmt[i-1]+1] \ne pattern[i]   \\
//pmt[i-1] + 1 &  0 \lt i \lt m, pattern[pmt[i-1]+1] = pattern[i]
//\end{matrix}

static void BuildPmt(const std::string &pattern, int *pmt) {
  pmt[0] = -1;
  int i = 1;
  while (i < pattern.length()) {
    if (i > 0 && pattern[pmt[i - 1] + 1] == pattern[i]) {
      pmt[i] = pmt[i - 1] + 1;
    } else {
      pmt[i] = -1;
    }
    i++;
  }
}

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern) {
  std::vector<int> match;
  int pmt[MAX];
  BuildPmt(pattern, pmt);

  int i = 0;
  int j = 0;
  while (i < text.length()) {
    if (j == -1 || text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      j = pmt[j - 1] + 1;
    }
    if (j == pattern.length()) {
      match.push_back(i - j);
      j = 0;
    }
  }

  return match;
}

