#ifndef RECURSION_HPP
#define RECURSION_HPP 1

#include <iostream>
using namespace std;
#ifndef MAX
#define MAX 60
#endif


void RecursionOutput(int s[MAX], int beg, int end)
{
    for (int i = beg; i < end; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void Recursion(int s[MAX], int n, int m, int prev)
{
    /* part 1: recursion end */
    if (prev == n) {
        RecursionOutput(s, 0, n);
        return;
    }

    /* part 2: m choices of s[prev] */
    for (int i = 0; i < m; ++i) {
        s[prev] = i;
        Recursion(s, n, m, prev + 1);
    }
}


#endif
