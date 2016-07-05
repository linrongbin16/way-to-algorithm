#include "BruteForce.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

#define TEST_N_MAX 4
#define TEST_M_MAX 16

int main()
{
    int s[TEST_N_MAX];
    for (int i = 0; i < TEST_M_MAX; i++) {
        BruteForce(s, TEST_N_MAX, i);
    }

    return 0;
}
