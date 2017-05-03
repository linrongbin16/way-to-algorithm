#include "BinarySearch.hpp"
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


#define TEST_MAX 1024

int main()
{
    int s[MAX];
    int index;
    for (int i = 0; i < MAX; ++i)
        s[i] = i;

    for (int i = 1; i < TEST_MAX; ++i) {
        int *s = new int[i];
        for (int j = 0; j < i; ++j)
            s[j] = j;
        for (int j = -TEST_MAX; j < 0; ++j) {
            assert(!BinarySearch(s, 0, i, j, index));
        }
        for (int j = 0; j < i; ++j) {
            assert(BinarySearch(s, 0, i, j, index));
            assert(index == j);
        }
        for (int j = i; j < 2 * TEST_MAX; ++j) {
            assert(!BinarySearch(s, 0, i, j, index));
        }
        delete[] s;
    }

    return 0;
}
