#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP 1

#include <iostream>
using namespace std;
#ifndef MAX
#define MAX 60
#endif


void BruteForceOutput(int s[MAX], int beg, int end)
{
    for (int i = beg; i < end; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void BruteForce(int s[MAX], int n, int m)
{
    for (int i_0 = 0; i_0 < m; i_0++)
        for (int i_1 = 0; i_1 < m; i_1++)
            for (int i_2 = 0; i_2 < m; i_2++)
                /* ... */
                for (int i_n_1 = 0; i_n_1 < m; i_n_1++) {
                    s[0] = i_0;
                    s[1] = i_1;
                    s[2] = i_2;
                    /* ... */
                    s[n - 1] = i_n_1;
                    BruteForceOutput(s, 0, n);
                }
}


#endif
