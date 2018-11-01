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
    {"helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihopeyo"
     "uenjoy",
     "oo",
     {11, 30, 34}},
    {"sting", "in", {2}},
    {"abedget", "be", {1}},
    {"aaaaaaaa", "aa", {0, 1, 2, 3, 4, 5, 6}},
    {"shherishers", "her", {2, 7}},
    {"helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihop"
     "eyouenjoy",
     "i",
     {24, 26, 54, 66}},
};

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];
    assert(KnuthMorrisPratt(t.text, t.pattern) == t.pos);
  }
  return 0;
}

