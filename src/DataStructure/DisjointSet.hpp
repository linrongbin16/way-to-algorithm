#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <cstring>


//
// interface
//

struct Set {
  int father[MAX];
};

Set *DisjointSetNew();
void DisjointSetFree(Set *s);
void DisjointSetUnion(Set *s, int i, int j);
bool DisjointSetQuery(Set *s, int i, int j);


//
// implement
//

namespace detail {

  int FindFather(Set *s, int i);

}

Set *DisjointSetNew() {
  Set *s = new Set();
  if (!s) {
    return nullptr;
  }
  for (int i = 0; i < MAX; i++)
    s->father[i] = i;
  return s;
}

void DisjointSetFree(Set *s) {
  delete s;
}

void DisjointSetUnion(Set *s, int i, int j) {
  int i_father = detail::FindFather(s, i);
  int j_father = detail::FindFather(s, j);
  s->father[j] = i_father;
}

bool DisjointSetQuery(Set *s, int i, int j) {
  return detail::FindFather(s, i) == detail::FindFather(s, j);
}

namespace detail {

  int FindFather(Set *s, int i) {
    if (s->father[i] != i)
      s->father[i] = FindFather(s, s->father[i]);
    return s->father[i];
  }

}
