#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <cstring>

struct Set {
  int father[MAX];
};

// create DisjointSet
Set *DisjointSetNew();

// free DisjointSet
void DisjointSetFree(Set *s);

// union DisjointSet
void DisjointSetUnion(Set *s, int i, int j);

// query DisjointSet
bool DisjointSetQuery(Set *s, int i, int j);

