#include "DisjointSet.hpp"
#include <iostream>
#include <cassert>
using namespace std;

void PrintSet(DisjointSet *s, int n)
{
    for (int i = 0; i < n; i++) {
        cout << s->father[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void test1()
{
    /* test1 */
    DisjointSet *s = DisjointSetNew();
    assert(s);
    DisjointSetUnion(s, 0, 4);
    PrintSet(s, 10);
    DisjointSetUnion(s, 1, 9);
    PrintSet(s, 10);
    DisjointSetUnion(s, 0, 2);
    PrintSet(s, 10);
    DisjointSetUnion(s, 1, 3);
    PrintSet(s, 10);
    DisjointSetUnion(s, 3, 5);
    PrintSet(s, 10);
    DisjointSetUnion(s, 6, 8);
    PrintSet(s, 10);
    DisjointSetUnion(s, 2, 6);
    PrintSet(s, 10);
    DisjointSetUnion(s, 1, 7);
    PrintSet(s, 10);

    assert(DisjointSetQuery(s, 1, 3));
    assert(DisjointSetQuery(s, 1, 5));
    assert(DisjointSetQuery(s, 1, 7));
    assert(DisjointSetQuery(s, 1, 9));
    assert(DisjointSetQuery(s, 3, 5));
    assert(DisjointSetQuery(s, 3, 7));
    assert(DisjointSetQuery(s, 3, 9));
    assert(DisjointSetQuery(s, 5, 7));
    assert(DisjointSetQuery(s, 5, 9));
    assert(DisjointSetQuery(s, 7, 9));

    assert(DisjointSetQuery(s, 0, 2));
    assert(DisjointSetQuery(s, 0, 4));
    assert(DisjointSetQuery(s, 0, 6));
    assert(DisjointSetQuery(s, 0, 8));
    assert(DisjointSetQuery(s, 2, 4));
    assert(DisjointSetQuery(s, 2, 6));
    assert(DisjointSetQuery(s, 2, 8));
    assert(DisjointSetQuery(s, 4, 6));
    assert(DisjointSetQuery(s, 4, 8));
    assert(DisjointSetQuery(s, 6, 8));

    assert(!DisjointSetQuery(s, 0, 1));
    assert(!DisjointSetQuery(s, 2, 3));
    assert(!DisjointSetQuery(s, 4, 5));
    assert(!DisjointSetQuery(s, 6, 7));
    assert(!DisjointSetQuery(s, 8, 9));

    DisjointSetFree(s);
}

int main()
{
    test1();
    return 0;
}
