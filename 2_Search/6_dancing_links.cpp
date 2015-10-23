#include <iostream>
#include <algorithm>
#include "6_dancing_links.h"
using namespace std;

int main()
{
    int n = 7;
    int sub[MAX][MAX];
    sub[0][0] = 2; sub[0][1] = 4; sub[0][2] = 5;
    sub[1][0] = 0; sub[1][1] = 3; sub[1][2] = 6;
    sub[2][0] = 1; sub[2][1] = 2; sub[2][2] = 5;
    sub[3][0] = 0; sub[3][1] = 3;
    sub[4][0] = 1; sub[4][1] = 6;
    sub[5][0] = 3; sub[5][1] = 4; sub[5][2] = 6;
    int cnt[MAX];
    cnt[0] = 3;
    cnt[1] = 3;
    cnt[2] = 3;
    cnt[3] = 2;
    cnt[4] = 2;
    cnt[5] = 3;
    int m = 6;
    int choose[MAX];

    cout << "there're " << n << " members in set S" << endl;
    for (int i = 0; i < n; ++i)
        cout << i << ' ';
    cout << endl;
    cout << "there're " << m << " sub set" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "sub set " << i << '\t';
        for (int j = 0; j < cnt[i]; ++j) {
            cout << sub[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "dancing_links: " << dancing_links(n, sub, m, cnt, choose) << endl;
    cout << "choose: ";
    for (int i = 0; i < m; ++i)
        cout << choose[i] << ' ';
    cout << endl;

	return(0);
}
