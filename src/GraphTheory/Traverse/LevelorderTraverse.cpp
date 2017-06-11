#include "LevelorderTraverse.hpp"
#include <vector>
#include <cassert>
using namespace std;

struct Test {
    int n;
    vector<int> result;
} test_cases[] = {
    {
        10,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    },
    {
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
    for (int i = 0; i < sizeof(test_cases)/sizeof(Test); i++) {
        Test & t = test_cases[i];
        vector<int> r = LevelorderTraverse(t.n);
        AssertEqual(r, t.result);
    }
    return 0;
}
