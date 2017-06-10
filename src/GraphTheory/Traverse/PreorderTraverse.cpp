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
        { 1, 2, 4, 8, 9, 5, 10, 3, 6, 7 },
    },
    {
        6,
        { 1, 2, 4, 5, 3, 6 },
    },
};

void AssertEqual(const vector<int> & a, const vector<int> & b)
{
    cout << "a: ";
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "b: ";
    for (int i = 0; i < a.size(); i++)
        cout << b[i] << " ";
    cout << endl;
    cout << endl;
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
