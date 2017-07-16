#ifndef RECURSION_HPP
#define RECURSION_HPP 1

#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

auto ArrayToVector(int s[MAX], int n) -> vector<int>
{
    vector<int> r;
    for (int i = 0; i < n; i++)
        r.push_back(s[i]);
    return r;
}

/**
 * @brief Recursion 递归
 * @param s     所有成员的选择 s[i]表示成员i的选择
 * @param n     成员数量
 * @param m     选择数量
 * @param prev  上一个选择过的成员下标
 * @param comb  所有选择的集合
*/
auto Recursion(int s[MAX], int n, int m, int prev, vector<vector<int>> &comb) -> void
{
    /* 递归终止条件 */
    if (prev == n) {
        comb.push_back( ArrayToVector(s, n) );
        return;
    }

    /* 遍历当前成员s[prev] 并递归进入下一个成员 */
    for (int i = 0; i < m; ++i) {
        s[prev] = i;
        Recursion(s, n, m, prev + 1, comb);
    }
}


#endif
