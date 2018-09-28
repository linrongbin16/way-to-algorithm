#include "RabinKarp.h"
#include "Util.h"
#include <cmath>
#include <string>
#include <vector>

static int base = 128;
static int prime = 16777619;

static int Power(int b, int n) {
  if (n == 0) {
    return 1;
  }
  int a = b;
  for (int i = 0; i < n - 1; i++) {
    a = (a * b) % prime;
  }
  return a;
}

static void BuildFingerPrint(const std::string &s, int m, int *fp) {
  int h = 0;
  int power = Power(base, m - 1);

  for (int i = 0; i < s.length(); i++) {
    if (i - m + 1 >= 0) {
      h = (h * base + (int)s[i] - power * s[i - m + 1]) % prime;
      fp[i - m + 1] = h;
    } else {
      // 若i-m+1<0说明s[i-m+1 ... i]的长度小于m
      // 因此左边界不删除字符
      h = (h * base + (int)s[i]) % prime;
    }
  }
}

std::vector<int> RabinKarp(const std::string &text,
                           const std::string &pattern) {
  std::vector<int> match;
  int text_fp[MAX], pattern_fp;
  BuildFingerPrint(text, pattern.length(), text_fp);
  BuildFingerPrint(pattern, pattern.length(), &pattern_fp);

  for (int i = 0; i < text.length() - pattern.length() + 1; i++) {
    if (text_fp[i] == pattern_fp) {
      if (StringEq(text, i, pattern, 0, pattern.length())) {
        match.push_back(i);
      }
    }
  }
  return match;
}

