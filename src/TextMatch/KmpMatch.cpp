#include "KMPMatch.h"
#include <string>
#include <vector>

// 1)第一种计算next数组的前缀函数实际上是算法导论中给出的伪代码
//不同之处仅仅在于算法导论原书中该伪代码的字符串下标是从1开始计算的
//在使用时需要把next数组整个后移一位 并且设置next[0]=-1

static void ComputePrefixFunction1(const std::string &s, int *next) {
  next[0] = 0;
  for (int i = 1; i < (int)s.length(); ++i) {
    int k = next[i - 1];
    while (s[i] != s[k] and k != 0)
      k = next[k - 1];
    if (s[i] == s[k])
      next[i] = k + 1;
    else
      next[i] = 0;
  }
  //网上的很多文档其实并没有后面这一部分代码 本文加进去是保证next[0]=-1
  for (int i = (int)s.length(); i >= 1; --i)
    next[i] = next[i - 1];
  next[0] = -1;
}

// 2)第二种计算next数组的前缀函数则是网上较为流行的一种方法 推荐使用该方法

static void ComputePrefixFunction2(const std::string &s, int *next) {
  int i = 0, j = -1;
  next[0] = -1;
  while (i < (int)s.length()) {
    if (j == -1 or s[i] == s[j])
      next[++i] = ++j;
    else
      j = next[j];
  }
}

std::vector<int> KMPMatch(const std::string &text, const std::string &str) {
  //字符串s在文本t中进行匹配
  //返回字符串在文本中匹配到的子串的数量和位置 存储于数组pos中
  std::vector<int> match;
  int next[MAX];
  ComputePrefixFunction2(text, next);

  int i = 0, j = 0;
  while (i < text.length()) {
    if (j == -1 || text[i] == str[j]) {
      ++i;
      ++j;
    } else {
      j = next[j];
    }
    if (j == str.length()) {
      match.push_back(i - j);
      j = 0;
    }
  }
  return match;
}

