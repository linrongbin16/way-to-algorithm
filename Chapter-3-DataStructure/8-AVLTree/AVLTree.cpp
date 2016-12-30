#include "AVLTree.hpp"
#include <assert.h>
#include <math.h>

#define TEST_MAX 1024

int main()
{
    AVLTree *t = AVLTreeNew();

    for (int i = 1; i <= TEST_MAX; i++) {
        AVLTreeInsert(t, i);
        /* AVL树的高度不大于 log(N) */
        assert( pow(2, ) );
    }
    return 0;
}
