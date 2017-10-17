#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP 1

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
    return NULL;
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
