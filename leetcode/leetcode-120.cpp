#include <string>
using namespace std;

#define MAX 1001

class Solution {
  bool f[MAX][MAX];

public:
  string longestPalindrome(string s) {
    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        f[i][j] = (i == j);
      }
    }

    for (int k = 0; k < s.length(); k++) {
      for (int i = k - 1, j = k + 1; i >= 0 && j < s.length(); i--, j++) {
        f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
      }
      for (int i = k, j = k + 1; i >= 0 && j < s.length(); i--, j++) {
        f[i][j] =
            (i + 1 == j) ? (s[i] == s[j]) : (f[i + 1][j - 1] && s[i] == s[j]);
      }
    }

    int maxlen = 0;
    int beg = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j < s.length(); j++) {
        if (f[i][j]) {
          if (maxlen < j - i + 1) {
            maxlen = j - i + 1;
            beg = i;
            end = j;
          }
        }
      }
    }

    return s.substr(beg, end - beg + 1);
  }
};

