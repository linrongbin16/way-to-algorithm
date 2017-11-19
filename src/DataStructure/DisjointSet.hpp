// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>


//
// interface
//

struct DisjointSet {
  int father[MAX];
};

auto DisjointSetNew() -> DisjointSet*;
auto DisjointSetFree(DisjointSet *s) -> void;
auto DisjointSetUnion(DisjointSet *s, int i, int j) -> void;
auto DisjointSetQuery(DisjointSet *s, int i, int j) -> bool;


//
// implement
//

namespace detail {

  auto FindFather(DisjointSet *s, int i) -> int;

}

auto DisjointSetNew() -> DisjointSet* {
  DisjointSet *s = new DisjointSet();
  if (!s) {
    return nullptr;
  }
  for (int i = 0; i < MAX; i++)
    s->father[i] = i;
  return s;
}

auto DisjointSetFree(DisjointSet *s) -> void {
  delete s;
}

auto DisjointSetUnion(DisjointSet *s, int i, int j) -> void {
  int i_father = detail::FindFather(s, i);
  int j_father = detail::FindFather(s, j);
  s->father[j] = i_father;
}

auto DisjointSetQuery(DisjointSet *s, int i, int j) -> bool {
  return detail::FindFather(s, i) == detail::FindFather(s, j);
}

namespace detail {

  auto FindFather(DisjointSet *s, int i) -> int {
    if (s->father[i] != i)
      s->father[i] = FindFather(s, s->father[i]);
    return s->father[i];
  }

}
