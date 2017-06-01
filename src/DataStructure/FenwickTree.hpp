#ifndef FENWICK_TREE_HPP
#define FENWICK_TREE_HPP 1

#include <cstring>
#ifndef MAX
#define MAX 1024
#endif

struct FenwickTree
{
    /* 数组下标从1开始 */
    int bit[MAX];
};

int LowBit(int i)
{
    return i & (-i);
}

FenwickTree *FenwickTreeNew()
{
    FenwickTree *t = new FenwickTree();
    if (!t) {
        return NULL;
    }

    memset(t->bit, 0, MAX * sizeof(int));
    return t;
}

FenwickTree *FenwickTreeNewFromArray(int s[MAX])
{
    FenwickTree *t = new FenwickTree();
    if (!t) {
        return NULL;
    }

    memset(t->bit, 0, MAX * sizeof(int));
    /* 数组下标从1开始 */
    for (int i = 1; i < MAX; i++) {
        t->bit[i] = s[i];
        for (int j = i-1; j > i-LowBit(i); j--)
            t->bit[i] += s[i];
    }

    return t;
}

void FenwickTreeFree(FenwickTree *t)
{
    delete t;
}

void FenwickTreeAdd(FenwickTree *t, int i, int v)
{
    for (int j = i; j < MAX; j += LowBit(j)) {
        t->bit[j] += v;
    }
}
int FenwickTreeSum(FenwickTree *t, int i)
{
    int sum = 0;
    for (int j = i; j > 0; j -= LowBit(j)) {
        sum += t->bit[j];
    }
    return sum;
}

#endif
