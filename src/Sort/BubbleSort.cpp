#include "BubbleSort.hpp"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

#define MAX 64

auto AssertNotAscendingOrder(vector<int> &s, int n) -> void
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(!res);
}
auto AssertAscendingOrder(vector<int> &s, int n) -> void
{
    bool res = true;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] > s[i+1]) {
            res = false;
            break;
        }
    }
    assert(res);
}
auto AssertBubbleSort(vector<int> &s, int n) -> void
{
    AssertNotAscendingOrder(s, n);
    BubbleSort(s, 0, n);
    AssertAscendingOrder(s, n);
}


#define TEST_MAX 1024

auto main(void) -> int
{
    vector<int> s(MAX, 0);

    for (int i = 0; i < TEST_MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            s[j] = rand() % TEST_MAX;
        }
        AssertBubbleSort(s, MAX);
    }

    return 0;
}
