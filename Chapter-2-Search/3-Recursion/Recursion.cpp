#include "Recursion.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

#define TEST_N_MAX 6
#define TEST_M_MAX 16

int main()
{
    for (int i = 0; i < TEST_N_MAX; i++)
        for (int j = 1; j < TEST_M_MAX; j++) {
            int *s = new int[i];
            Recursion(s, i, j, 0);
            delete[] s;
        }

    return 0;
}
