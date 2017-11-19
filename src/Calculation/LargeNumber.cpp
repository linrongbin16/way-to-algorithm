// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "LargeNumber.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define TEST_MAX 1024


auto main() -> int {
  assert(Add(Init(1), Init(2)) );
  return 0;
}
