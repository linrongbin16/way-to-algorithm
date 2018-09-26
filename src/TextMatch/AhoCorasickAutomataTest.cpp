#include "AhoCorasickAutomata.h"
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

#define TEST_MAX 1024

struct Test {
  string text;
  vector<string> pattern;
  unordered_map<string, vector<int>> match;
} tests[] = {
    {
        "asdfasdfasdfasdf",
        {"asdf"},
        {
            {"asdf", {0, 4, 8, 12}},
        },
    },
    {
        "helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihop"
        "eyouenjoy",
        {"oo"},
        {
            {"oo", {11, 30, 34}},
        },
    },
    {
        "helloworldgoodbyeworldthisisagoodbookformanycomputersciencestudentihop"
        "eyouenjoy",
        {"oo", "world", "good", "i"},
        {
            {"oo", {11, 30, 34}},
            {"world", {5, 17}},
            {"good", {10, 29}},
            {"i", {24, 26, 40, 48}},
        },
    },
};

void AssertEqual(vector<int> v1, vector<int> v2) {
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  assert(v1.size() == v2.size());
  for (int i = 0; i < v1.size(); i++) {
    assert(v1[i] == v2[i]);
  }
}

void AssertEqual(unordered_map<string, vector<int>> m1,
                 unordered_map<string, vector<int>> m2) {
  assert(m1.size() == m2.size());
  for (unordered_map<string, vector<int>>::iterator i = m1.begin();
       i != m1.end(); i++) {
    string k1 = i->first;
    vector<int> v1 = i->second;
    assert(m2.find(k1) != m2.end());
    vector<int> v2 = m2[k1];
    AssertEqual(v1, v2);
  }
}

int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];

    AcNode *root = AhoCorasickAutomataNew(t.pattern);
    AssertEqual(AhoCorasickAutomataMatch(root, t.text), t.match);
    AhoCorasickAutomataFree(root);
  }
  return 0;
}

