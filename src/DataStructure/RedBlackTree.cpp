#include "RedBlackTree.hpp"
#include <assert.h>
#include <math.h>
#include <string>

#define TEST_MAX 1024

int main()
{
    RedBlackTree *t = RedBlackTreeNew();
    assert(t);

    for (int i = 1; i <= TEST_MAX; i++) {
        RedBlackTreeInsert(t, i);
    }
    for (int i = 1; i <= TEST_MAX; i++) {
        assert(RedBlackTreeFind(t, i));
    }
    for (int i = 1; i <= TEST_MAX; i++) {
        RedBlackTreeErase(t, i);
    }
    RedBlackTreeFree(t);

    return 0;
}
