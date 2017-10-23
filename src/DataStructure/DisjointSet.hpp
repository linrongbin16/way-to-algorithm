// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#ifndef DATASTRUCTURE_DISJOINTSET_HPP
#define DATASTRUCTURE_DISJOINTSET_HPP

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>


struct DisjointSet {
  int father[MAX];
};

static int FindFather(DisjointSet *s, int i) {
  if (s->father[i] != i)
    s->father[i] = FindFather(s, s->father[i]);
  return s->father[i];
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
  int i_father = FindFather(s, i);
  int j_father = FindFather(s, j);
  s->father[j] = i_father;
}

auto DisjointSetQuery(DisjointSet *s, int i, int j) -> bool {
  return FindFather(s, i) == FindFather(s, j);
}


#endif
