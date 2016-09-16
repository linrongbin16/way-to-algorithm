#include "DancingLink.hpp"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main()
{
    /* 集合s成员为[1,7] */
    int n = 7;
    /* 集合s子集为[1,6] */
    int m = 6;
    /* subset[i,j]=index 表示子集j包含成员i 在矩阵中该节点的下标号为index */
    int subset[MAX][MAX];
    /* 精确覆盖的结果 */
    int cover[MAX];
    memset(subset, 0, MAX * MAX * sizeof(int));
    subset[1][1] = 1; subset[1][3] = 2; subset[1][5] = 3; subset[1][6] = 4;
    subset[2][1] = 5; subset[2][4] = 6; subset[2][5] = 7; subset[2][7] = 8;
    subset[3][2] = 9; subset[3][6] = 10; subset[3][7] = 11;
    subset[4][2] = 12; subset[4][3] = 13; subset[4][6] = 14;
    subset[5][4] = 15; subset[5][5] = 16; subset[5][7] = 17;
    subset[6][5] = 18;

    assert(DancingLink(n, m, subset, cover));
    assert(!cover[1] && cover[2] && cover[3] && !cover[4] && !cover[5] && cover[6] && !cover[7]);

    n = 7;
    m = 6;
    memset(subset, 0, MAX * MAX * sizeof(int));
    subset[1][1] = 1; subset[1][4] = 2; subset[1][7] = 3;
    subset[2][1] = 4; subset[2][4] = 5;
    subset[3][4] = 6; subset[3][5] = 7; subset[3][7] = 8;
    subset[4][3] = 9; subset[4][5] = 10; subset[4][6] = 11;
    subset[5][2] = 12; subset[5][3] = 13; subset[5][6] = 14; subset[5][7] = 15;
    subset[6][2] = 16; subset[6][7] = 17;

    assert(DancingLink(n, m, subset, cover));
    assert(!cover[1] && cover[2] && !cover[3] && cover[4] && !cover[5] && !cover[6]);

    n = 7;
    m = 6;
    memset(subset, 0, MAX * MAX * sizeof(int));
    subset[1][3] = 1; subset[1][5] = 2; subset[1][6] = 3;
    subset[2][1] = 4; subset[2][4] = 5; subset[2][7] = 6;
    subset[3][2] = 7; subset[3][3] = 8; subset[3][6] = 9;
    subset[4][1] = 10; subset[4][4] = 11;
    subset[5][2] = 12; subset[5][7] = 13;
    subset[6][4] = 14; subset[6][5] = 15; subset[6][7] = 16;

    assert(DancingLink(n, m, subset, cover));
    assert(cover[1] && !cover[2] && !cover[3] && cover[4] && cover[5] && !cover[6]);
    return 0;
}
