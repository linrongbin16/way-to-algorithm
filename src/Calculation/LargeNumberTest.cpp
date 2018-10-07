#include "LargeNumber.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

int main() {
  for (int i = 0; i < MAX; i++) {
    int a = rand();
    int b = rand();
    a = (rand() % 2 == 0) ? a : (-a);
    b = (rand() % 2 == 0) ? b : (-b);
    assert(Eq(Add(Number(a), Number(b)), Number(a + b)));
    assert(Eq(Sub(Number(a), Number(b)), Number(a - b)));
    assert(Eq(Mul(Number(a), Number(b)), Number(a * b)));
    string s1 = ToString(Add(Number(a), Number(b)));
    string s2 = ToString(Number(a + b));
    string s3 = to_string(a + b);
    string s4 = ToString(Sub(Number(a), Number(b)));
    string s5 = ToString(Number(a - b));
    string s6 = to_string(a - b);
    string s7 = ToString(Mul(Number(a), Number(b)));
    string s8 = ToString(Number(a * b));
    string s9 = to_string(a * b);
    assert(s1 == s2);
    assert(s2 == s3);
    assert(s4 == s5);
    assert(s5 == s6);
    assert(s7 == s8);
    assert(s8 == s9);
  }
  return 0;
}

