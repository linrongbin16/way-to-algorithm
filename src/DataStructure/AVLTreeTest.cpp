#include <assert.h>
#include <math.h>
#include "AVLTree.h"

#define TEST_MAX 1024

int main()
{
    AVLTree *t = AVLTreeNew();
    for (int i = 1; i <= TEST_MAX; i++) {
        AVLTreeInsert(t, i);
        assert(pow(2, AVLTreeDepth(t)) <= i);
    }
    assert(pow(2, AVLTreeDepth(t)) <= TEST_MAX);
    for (int i = 1; i <= TEST_MAX; i++) {
        assert(AVLTreeFind(t, i) == 1);
    }
    for (int i = 1; i <= TEST_MAX; i++) {
        AVLTreeErase(t, i);
    }
    AVLTreeFree(t);
    return 0;
}
