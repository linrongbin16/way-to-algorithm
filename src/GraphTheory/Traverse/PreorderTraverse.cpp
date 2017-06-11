#include "PreorderTraverse.hpp"
#include <cassert>
#include <iostream>
using namespace std;

struct Test {
    int n;
    vector<int> result;
} test_cases[] = {
    {
        10,
        { 0, 1, 3, 7, 8, 4, 9, 2, 5, 6 },
    },
    {
        6,
        { 0, 1, 3, 4, 2, 5 },
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
    for (int i = 0; i < sizeof(test_cases)/sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<int> r = PreorderTraverse(t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}
