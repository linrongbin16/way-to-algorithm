#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP 1

#ifndef MAX
#define MAX 60
#endif
#include <cstring>


struct DisjointSet
{
    int father[MAX];
};

int DisjointSetFindFather(DisjointSet *s, int i)
{
    if (s->father[i] != i)
        s->father[i] = DisjointSetFindFather(s, s->father[i]);
    return s->father[i];
}

DisjointSet *DisjointSetNew()
{
    DisjointSet *s = new DisjointSet();
    if (!s) {
        return NULL;
    }

    for (int i = 0; i < MAX; i++)
        s->father[i] = i;
    return s;
}

void DisjointSetFree(DisjointSet *s)
{
    delete s;
}

void DisjointSetUnion(DisjointSet *s, int i, int j)
{
    int i_father = DisjointSetFindFather(s, i);
    int j_father = DisjointSetFindFather(s, j);
    s->father[j] = i_father;
}
bool DisjointSetQuery(DisjointSet *s, int i, int j)
{
    return DisjointSetFindFather(s, i) == DisjointSetFindFather(s, j);
}


#endif
