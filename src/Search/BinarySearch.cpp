#include "BinarySearch.hpp"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


#define TEST_MAX 1024

auto main() -> int
{
    int s[MAX];

    for (int i = 1; i < TEST_MAX; ++i) {
        for (int j = 0; j < i; ++j)
            s[j] = j;
        for (int j = -TEST_MAX; j < 0; ++j) {
            auto r = BinarySearch(s, 0, i, j);
            assert(not get<0>(r));
        }
        for (int j = 0; j < i; ++j) {
            auto r = BinarySearch(s, 0, i, j);
            assert(get<0>(r));
            assert(get<1>(r) == j);
        }
        for (int j = i; j < TEST_MAX; ++j) {
            auto r = BinarySearch(s, 0, i, j);
            assert(not get<0>(r));
        }
    }

    return 0;
}
