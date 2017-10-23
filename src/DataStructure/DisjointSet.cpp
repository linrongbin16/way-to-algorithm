// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "DisjointSet.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

auto PrintSet(DisjointSet *s, int n) -> void {
  for (int i = 0; i < n; i++) {
    cout << s->father[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << endl << endl;
}

auto test1() -> void {
  DisjointSet *s = DisjointSetNew();
  assert(s);
  DisjointSetUnion(s, 0, 4);
  DisjointSetUnion(s, 1, 9);
  DisjointSetUnion(s, 0, 2);
  DisjointSetUnion(s, 1, 3);
  DisjointSetUnion(s, 3, 5);
  DisjointSetUnion(s, 6, 8);
  DisjointSetUnion(s, 2, 6);
  DisjointSetUnion(s, 1, 7);

  assert(DisjointSetQuery(s, 1, 3));
  assert(DisjointSetQuery(s, 1, 5));
  assert(DisjointSetQuery(s, 1, 7));
  assert(DisjointSetQuery(s, 1, 9));
  assert(DisjointSetQuery(s, 3, 5));
  assert(DisjointSetQuery(s, 3, 7));
  assert(DisjointSetQuery(s, 3, 9));
  assert(DisjointSetQuery(s, 5, 7));
  assert(DisjointSetQuery(s, 5, 9));
  assert(DisjointSetQuery(s, 7, 9));

  assert(DisjointSetQuery(s, 0, 2));
  assert(DisjointSetQuery(s, 0, 4));
  assert(DisjointSetQuery(s, 0, 6));
  assert(DisjointSetQuery(s, 0, 8));
  assert(DisjointSetQuery(s, 2, 4));
  assert(DisjointSetQuery(s, 2, 6));
  assert(DisjointSetQuery(s, 2, 8));
  assert(DisjointSetQuery(s, 4, 6));
  assert(DisjointSetQuery(s, 4, 8));
  assert(DisjointSetQuery(s, 6, 8));

  assert(!DisjointSetQuery(s, 0, 1));
  assert(!DisjointSetQuery(s, 2, 3));
  assert(!DisjointSetQuery(s, 4, 5));
  assert(!DisjointSetQuery(s, 6, 7));
  assert(!DisjointSetQuery(s, 8, 9));

  DisjointSetFree(s);
}

auto test2() -> void {
  DisjointSet *s = DisjointSetNew();
  assert(s);
  DisjointSetUnion(s, 1, 2);
  DisjointSetUnion(s, 1, 3);
  DisjointSetUnion(s, 0, 4);
  DisjointSetUnion(s, 4, 5);

  assert(DisjointSetQuery(s, 1, 2));
  assert(DisjointSetQuery(s, 2, 3));
  assert(DisjointSetQuery(s, 0, 4));
  assert(DisjointSetQuery(s, 4, 5));

  assert(!DisjointSetQuery(s, 0, 1));
  assert(!DisjointSetQuery(s, 0, 2));
  assert(!DisjointSetQuery(s, 0, 3));
  assert(!DisjointSetQuery(s, 1, 0));
  assert(!DisjointSetQuery(s, 1, 4));
  assert(!DisjointSetQuery(s, 1, 5));

  DisjointSetFree(s);
}

auto main() -> int {
  test1();
  test2();
  return 0;
}
