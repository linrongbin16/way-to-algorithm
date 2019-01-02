#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct DjSet {
  int father[MAX];
};

// create DisjointSet
DjSet *DisjointSetNew();

// free DisjointSet
void DisjointSetFree(DjSet *s);

// union DisjointSet
void DisjointSetUnion(DjSet *s, int i, int j);

// query DisjointSet
bool DisjointSetQuery(DjSet *s, int i, int j);

