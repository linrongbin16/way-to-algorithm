#pragma once
#include <utility>
#include <vector>
#ifndef MAX
#define MAX 128
#endif

/**
 * @param n   集合s的元素数量 s = [1,2,...,n]
 * @param m   子集的数量 t = [s[1], s[2], ..., s[m]]
 * @param s   s[i][j] = 1表示子集s[i]包含元素j
 * @return    返回的数组ret[i] = 1表示精确覆盖中包括子集s[i]
 */
std::pair<bool, std::vector<int>> DancingLink(int n, int m, int s[MAX][MAX]);

