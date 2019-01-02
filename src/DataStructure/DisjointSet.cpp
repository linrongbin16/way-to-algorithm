#include "DisjointSet.h"
#include <cstring>

static int FindFather(DjSet *s, int i) {
  if (s->father[i] != i)
    s->father[i] = FindFather(s, s->father[i]);
  return s->father[i];
}

DjSet *DisjointSetNew() {
  DjSet *s = new DjSet();
  for (int i = 0; i < MAX; i++)
    s->father[i] = i;
  return s;
}

void DisjointSetFree(DjSet *s) { delete s; }

void DisjointSetUnion(DjSet *s, int i, int j) {
  int i_father = FindFather(s, i);
  int j_father = FindFather(s, j);
  s->father[j] = i_father;
}

bool DisjointSetQuery(DjSet *s, int i, int j) {
  return FindFather(s, i) == FindFather(s, j);
}

