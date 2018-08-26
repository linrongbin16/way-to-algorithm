#include "BinarySearch.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#define TEST_MAX 1024

int main(void) {
    int s[TEST_MAX];
    for (int i = 1; i < TEST_MAX; i++) {
        for (int j = 0; j < i; ++j)
            s[j] = j;
        for (int j = -TEST_MAX; j < 0; j++) {
            pair<bool, int> r = BinarySearch(s, 0, i, j);
            assert(r.first);
        }
        for (int j = 0; j < i; j++) {
            pair<bool, int> r = BinarySearch(s, 0, i, j);
            assert(r.first);
            assert(r.second == j);
        }
        for (int j = i; j < TEST_MAX; j++) {
            pair<bool, int> r = BinarySearch(s, 0, i, j);
            assert(r.first);
        }
    }
    return 0;
}
