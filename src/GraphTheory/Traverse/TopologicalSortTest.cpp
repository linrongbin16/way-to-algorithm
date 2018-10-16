#include "TopologicalSort.hpp"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
    int g[MAX][MAX];
    int n;
    vector<int> result;
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
        { 0, 5, 1, 3, 2, 4, 6, 7 },
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
        { 0, 3, 1, 4, 2, 5, 6, 7, 8 },
    },
    {
            {
                    { 0, 0, 0, 1, 0, 0 }, // 0
                    { 1, 0, 0, 0, 0, 0 }, // 1
                    { 1, 0, 0, 0, 0, 0 }, // 2
                    { 0, 1, 1, 0, 0, 0 }, // 3
                    { 0, 0, 1, 0, 0, 0 }, // 4
                    { 0, 0, 0, 1, 1, 0 }, // 5
            },
            6,
            { 5, 4, 0, 1, 2, 3 },
    },
};


void AssertEqual(const vector<int> & a, const vector<int> & b)
{
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }
}

int main()
{
    for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<int> r = TopologicalSort(t.g, t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}