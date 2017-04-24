#ifndef RECURSION_HPP
#define RECURSION_HPP 1

#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


vector<int*> combinations;

vector<int*> Recursion(int s[MAX], int n, int m, int prev)
{
    /* 初始化combinations */
    if (prev == 0) {
        combinations.clear();
    }

    /* 递归终止条件 */
    if (prev == n) {
        int *one = new int[MAX];
        memcpy(one, s, MAX * sizeof(int));
        combinations.push_back(one);
        return vector<int*>();
    }

    /* 遍历当前成员s[prev] 并递归进入下一个成员 */
    for (int i = 0; i < m; ++i) {
        s[prev] = i;
        Recursion(s, n, m, prev + 1);
    }

    return combinations;
}


#endif
