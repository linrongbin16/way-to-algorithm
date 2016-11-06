#ifndef BINARY_INDEX_TREE_HPP
#define BINARY_INDEX_TREE_HPP 1

#include <cstring>
#ifndef MAX
#define MAX 1024
#endif

struct BinaryIndexTree
{
    /* 数组下标从1开始 */
    int bit[MAX];
};

int LowBit(int i)
{
    return i & (-i);
}

BinaryIndexTree *BinaryIndexTreeNew()
{
    BinaryIndexTree *t = new BinaryIndexTree();
    if (!t) {
        return NULL;
    }

    memset(t->bit, 0, MAX * sizeof(int));
    return t;
}

BinaryIndexTree *BinaryIndexTreeNewFromArray(int s[MAX])
{
    BinaryIndexTree *t = new BinaryIndexTree();
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

void BinaryIndexTreeFree(BinaryIndexTree *t)
{
    delete t;
}

void BinaryIndexTreeAdd(BinaryIndexTree *t, int i, int v)
{
    for (int j = i; j < MAX; j += LowBit(j)) {
        t->bit[j] += v;
    }
}
int BinaryIndexTreeSum(BinaryIndexTree *t, int i)
{
    int sum = 0;
    for (int j = i; j > 0; j -= LowBit(j)) {
        sum += t->bit[j];
    }
    return sum;
}

#endif
