#include "TopologicalSort.hpp"

struct Test {
    int g[MAX][MAX];
    int n;
    vector<TopoNode> result;
} test_cases[] = {
    {
        {
            { },
            {},
            {},
            {},
            {},
            {},
        },
        6,
        { {}, {}, {} },
    },
    {
        {},
        6,
        { {}, {}, {} },

    },
};

void AssertEqual(const vector<TopoNode> & a, const vector<TopoNode> & b)
{
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i].index == b[i].index);
        assert(a[i].depth == b[i].depth);
    }
}

int main()
{
    for (int i = 0; i < sizeof(test_cases) / sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<TopoNode> r = TopologicalSort(t.g, t.n);
    }
    return 0;
}