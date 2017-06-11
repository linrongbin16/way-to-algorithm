#include "DepthFirstSearch.hpp"
#include <cassert>

struct Test {
    int g[MAX][MAX];
    int n;
    int beg;
    vector<int> result;
} test_cases[] = {
    {
        {
            { 0, 1, 0, 0, 1, 1 },
            { 1, 0, 1, 1, 0, 1 },
            { 0, 1, 0, 1, 0, 1 },
            { 0, 1, 2, 0, 1, 0 },
            { 1, 0, 0, 1, 0, 0 },
            { 1, 1, 1, 0, 0, 0 },
        },
        6,
        { 0, 1, 2, 3, 4, 5 },
    },
};

void AssertEqual(const vector<int> & a, const vector<int> & b)
{
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++)
        assert(a[i] == b[i]);
}

int main()
{
    for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<int> r = DepthFirstSearch(t.g, t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}