#include "InorderTraverse.hpp"
#include <vector>
#include <cassert>
using namespace std;

struct Test {
    int n;
    vector<int> result;
} test_cases[] = {
    {
        10,
        { 7, 3, 8, 1, 9, 4, 0, 5, 2, 6 },
    },
    {
        6,
        { 3, 1, 4, 0, 5, 2 },
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
    for (int i = 0; i < sizeof(test_cases)/sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<int> r = InorderTraverse(t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}
