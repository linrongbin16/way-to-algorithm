#include "TopologicalSort.hpp"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
    int g[MAX][MAX];
    int n;
    vector<TopoNode> result;
} test_cases[] = {
    {
        {
            { 0, 1, 0, 0, 0, 1, 0, 0 },
            { 0, 0, 1, 1, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 1, 0, 0, 0 },
            { 0, 0, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 1, 1 },
            { 0, 1, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0 },
        },
        8,
        { { 0, 8 }, { 5, 7 }, { 1, 6 }, { 3, 5 }, { 2, 4 }, { 4, 3 }, { 6, 1 }, { 7, 1 } },
    },
    {
        {
            { 0, 1, 0, 1, 0, 0, 0, 0, 0 }, // 0
            { 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // 1
            { 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 2
            { 0, 0, 0, 0, 1, 0, 0, 0, 0 }, // 3
            { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, // 4
            { 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // 5
            { 0, 0, 0, 0, 0, 0, 0, 1, 1 }, // 6
            { 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // 7
            { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 8
        },
        9,
        { { 0, 9 }, { 3, 6 }, { 1, 5 }, { 4, 5 }, { 2, 4 }, { 5, 3 }, { 6, 3 }, { 7, 2 }, { 8, 1 } },
    },
};


void AssertEqual(const vector<TopoNode> & a, const vector<TopoNode> & b)
{
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i].index == b[i].index);
        assert(a[i].distance == b[i].distance);
    }
}

int main()
{
    for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<TopoNode> r = TopologicalSort(t.g, t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}