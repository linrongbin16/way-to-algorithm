#include "KnuthMorrisPratt.h"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
  string text;
  string pattern;
  vector<int> pos;
} tests[] = {
    {"asdfasdfasdfasdf", "asdf", {0, 4, 8, 12}},
    {"asdfasdfasdfasdf", "asdf", {0, 4, 8, 12}},
    {"helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihopeyo"
     "uenjoy",
     "oo",
     {11, 30, 34}},
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(KnuthMorrisPratt(t.text, t.pattern) == t.pos);
  }
  return 0;
}

