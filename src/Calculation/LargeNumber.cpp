// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "LargeNumber.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <random>
using namespace std;


#define TEST_MAX 1024

int main(void) {

  Number a, b;

  for (int i = 0; i < TEST_MAX; i++) {
    int a = rand();
    int b = rand();
    assert( Init(a) + Init(b) == Init(a + b) );
    assert( Init(a) - Init(b) == Init(a - b) );
    assert( Init(a) * Init(b) == Init(a * b) );
    assert( IntString(Init(a) + Init(b)) == IntString(Init(a + b)) );
    assert( IntString(Init(a) - Init(b)) == IntString(Init(a - b)) );
    assert( IntString(Init(a) * Init(b)) == IntString(Init(a * b)) );

    double c, d;
    while ((c = (double)rand()) == 0.0) { }
    c /= (double)rand();
    while ((d = (double)rand()) == 0.0) { }
    d /= (double)rand();
    assert( Init(c) + Init(d) == Init(c + d) );
    assert( Init(c) - Init(d) == Init(c - d) );
    assert( Init(c) * Init(d) == Init(c * d) );
    assert( FloatString(Init(c) + Init(d)) == FloatString(Init(c + d)) );
    assert( FloatString(Init(c) - Init(d)) == FloatString(Init(c - d)) );
    assert( FloatString(Init(c) * Init(d)) == FloatString(Init(c * d)) );
  }

  return 0;
}
