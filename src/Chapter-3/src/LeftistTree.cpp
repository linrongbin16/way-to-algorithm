#include "LeftistTree.hpp"
#include <iostream>
#include <assert.h>
using namespace std;

#define TEST_MAX 1024

int Greater(LeftistNode *a, LeftistNode *b)
{
	return b->index - a->index;
}
int Less(LeftistNode *a, LeftistNode *b)
{
	return a->index - b->index;
}

int main()
{
    for (int i = 0; i < MAX; i++) {
        LeftistTree *t = LeftistTreeNew(Greater);
        for (int j = 0; j < MAX; j++) {
			LeftistTreePush(t, j);
			assert(LeftistTreeTop(t) == j);
        }
        for (int j = MAX-1; j >= 0; j--) {
			assert(LeftistTreeTop(t) == j);
			LeftistTreePop(t);
        }
		LeftistTreeFree(t);
    }

    for (int i = 0; i < MAX; i++) {
        LeftistTree *t1 = LeftistTreeNew(Greater);
        LeftistTree *t2 = LeftistTreeNew(Greater);
        for (int j = 0; j < MAX; j++) {
			if (j % 2) {
				LeftistTreePush(t1, j);
			} else {
				LeftistTreePush(t2, j);
			}
        }
		LeftistTree *t = LeftistTreeMerge(t1, t2);
        for (int j = MAX-1; j >= 0; j--) {
			assert(LeftistTreeTop(t) == j);
			LeftistTreePop(t);
        }
		LeftistTreeFree(t);
    }

    for (int i = 0; i < MAX; i++) {
        LeftistTree *t = LeftistTreeNew(Less);
        for (int j = 0; j < MAX; j++) {
			LeftistTreePush(t, j);
			assert(LeftistTreeTop(t) == 0);
        }
        for (int j = 0; j < MAX; j++) {
			assert(LeftistTreeTop(t) == j);
			LeftistTreePop(t);
        }
		LeftistTreeFree(t);
    }

    for (int i = 0; i < MAX; i++) {
        LeftistTree *t1 = LeftistTreeNew(Less);
        LeftistTree *t2 = LeftistTreeNew(Less);
        for (int j = 0; j < MAX; j++) {
			if (j % 2) {
				LeftistTreePush(t1, j);
			} else {
				LeftistTreePush(t2, j);
			}
        }
		LeftistTree *t = LeftistTreeMerge(t1, t2);
        for (int j = 0; j < MAX; j++) {
			assert(LeftistTreeTop(t) == j);
			LeftistTreePop(t);
        }
		LeftistTreeFree(t);
    }
    return 0;
}
