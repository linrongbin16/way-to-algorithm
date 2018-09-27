#include "AhoCorasickAutomata.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define TEST_MAX 1024

struct Test {
  string text;
  vector<string> pattern;
  unordered_map<string, vector<int>> match;
} tests[] = {
    {
        "sting",
        {"i", "in", "tin", "sting"},
        {
            {"i", {2}},
            {"in", {2}},
            {"tin", {1}},
            {"sting", {0}},
        },
    },
    {
        "abedget",
        {"ab", "about", "at", "ate", "be", "bed", "edge", "get"},
        {
            {"ab", {0}},
            {"about", {}},
            {"at", {}},
            {"ate", {}},
            {"be", {1}},
            {"bed", {1}},
            {"edge", {2}},
            {"get", {4}},
        },
    },
    {
        "aaaaaaaa",
        {"a", "aa", "aaa", "aaaa"},
        {
            {"a", {0, 1, 2, 3, 4, 5, 6, 7}},
            {"aa", {0, 1, 2, 3, 4, 5, 6}},
            {"aaa", {0, 1, 2, 3, 4, 5}},
            {"aaaa", {0, 1, 2, 3, 4}},
        },
    },
    {
        "shherishers",
        {"he", "she", "his", "her", "hers"},
        {
            {"he", {2, 7}},
            {"she", {6}},
            {"his", {}},
            {"her", {2, 7}},
            {"hers", {7}},
        },
    },
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
            {"i", {24, 26, 54, 66}},
        },
    },
};

void AssertEqual(vector<int> s1, vector<int> s2) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  assert(s1.size() == s2.size());
  for (int i = 0; i < s1.size(); i++) {
    assert(s1[i] == s2[i]);
  }
}

void AssertEqual(unordered_map<string, vector<int>> m1,
                 unordered_map<string, vector<int>> m2) {

  unordered_map<string, vector<int>> tmp1 = m1;
  unordered_map<string, vector<int>> tmp2 = m2;
  m1.clear();
  m2.clear();
  for (unordered_map<string, vector<int>>::iterator i = tmp1.begin();
       i != tmp1.end(); i++) {
    string k1 = i->first;
    vector<int> s1 = i->second;
    if (!s1.empty()) {
      m1.insert(make_pair(k1, s1));
    }
  }
  for (unordered_map<string, vector<int>>::iterator i = tmp2.begin();
       i != tmp2.end(); i++) {
    string k2 = i->first;
    vector<int> s2 = i->second;
    if (!s2.empty()) {
      m2.insert(make_pair(k2, s2));
    }
  }

  assert(m1.size() == m2.size());
  for (unordered_map<string, vector<int>>::iterator i = m1.begin();
       i != m1.end(); i++) {
    string k1 = i->first;
    vector<int> s1 = i->second;
    assert(m2.find(k1) != m2.end());
    vector<int> s2 = m2[k1];
    AssertEqual(s1, s2);
  }
}

void DumpResult(const unordered_map<string, vector<int>> &result) {
  cout << endl << "dump size: " << result.size() << endl;
  for (auto i = result.begin(); i != result.end(); i++) {
    string key = i->first;
    vector<int> val = i->second;
    cout << "\tkey:" << key << endl;
    cout << "\tval:";
    for (int j = 0; j < val.size(); j++) {
      cout << "\t" << val[j];
    }
    cout << endl;
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

