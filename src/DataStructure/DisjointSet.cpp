#include "DisjointSet.h"
#ifndef MAX
#define MAX 1024
#endif
#include <cstring>

//
// implement
//

static int FindFather(Set *s, int i) {
    if (s->father[i] != i) s->father[i] = FindFather(s, s->father[i]);
    return s->father[i];
}

Set *DisjointSetNew() {
    Set *s = new Set();
    if (!s) {
        return nullptr;
    }
    for (int i = 0; i < MAX; i++) s->father[i] = i;
    return s;
}

void DisjointSetFree(Set *s) { delete s; }

void DisjointSetUnion(Set *s, int i, int j) {
    int i_father = FindFather(s, i);
    int j_father = FindFather(s, j);
    s->father[j] = i_father;
}

bool DisjointSetQuery(Set *s, int i, int j) {
    return FindFather(s, i) == FindFather(s, j);
}
