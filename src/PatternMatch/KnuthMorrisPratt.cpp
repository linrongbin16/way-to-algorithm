#include "KnuthMorrisPratt.h"
#include <string>
#include <vector>

static void BuildPartialMatchTable(const std::string &pattern, int *pmt) {
  pmt[0] = -1;
  for (int i = 1; i < pattern.length(); i++) {
    if (i > 0 && pattern[pmt[i - 1] + 1] == pattern[i]) {
      pmt[i] = pmt[i - 1] + 1;
    } else {
      pmt[i] = -1;
    }
  }
}

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern) {
  std::vector<int> match;
  int pmt[MAX];
  BuildPartialMatchTable(pattern, pmt);

  int i = 0;
  int j = 0;
  while (i < text.length()) {
    if (j == 0 && text[i] != pattern[j]) {
      i++;
    } else if (j < pattern.length() && text[i] == pattern[j]) {
      i++;
      j++;
    } else {
      // j >= pattern.length() 时
      // text[i] != pattern[j] 时
      // 沿着后缀指针跳转
      j = pmt[j - 1] + 1;
    }
    if (j == pattern.length()) {
      match.push_back(i - j);
    }
  }

  return match;
}

