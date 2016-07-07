#include "Recursion.hpp"
#include <cmath>
#include <cassert>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8

int main()
{
    int s[MAX];
    for (int i = 1; i < TEST_N_MAX; i++)
        for (int j = 1; j < TEST_M_MAX; j++) {
            vector<int*> r = Recursion(s, i, j, 0);
            assert(r.size() == pow(j, i));
            int *s0, sum0;
            /* 第一个排列组合必然是[0, 0, ..., 0] */
            s0 = r[0];
            sum0 = 0;
            for (int k = 0; k < i; k++) {
                assert(s0[k] == 0);
                sum0 = sum0 * 10 + s0[k];
            }
            assert(sum0 == 0);
            /* 排列组合的所有情况相当于依次递增的i位j进制正整数 */
            for (int k = 0; k < r.size()-1; k++) {
                int *s1 = r[k];
                int *s2 = r[k + 1];
                int sum1 = 0, sum2 = 0;
                for (int p = 0; p < i; p++) {
                    sum1 = sum1 * j + s1[p];
                    sum2 = sum2 * j + s2[p];
                }
                assert(sum1 == sum2 - 1);
            }
            for (int k = 0; k < r.size(); k++) {
                delete[] r[k];
            }
        }

    return 0;
}
