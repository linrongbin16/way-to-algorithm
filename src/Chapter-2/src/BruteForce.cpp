#include "BruteForce.hpp"
#include <assert.h>
#include <math.h>
using namespace std;

#define TEST_N_MAX 4
#define TEST_M_MAX 16

int main()
{
    int s[TEST_N_MAX];
    for (int i = 1; i < TEST_M_MAX; i++) {
        vector<int*> result = BruteForce(s, TEST_N_MAX, i);
        assert(result.size() == pow(i, TEST_N_MAX));
        int *s0, sum0;
        s0 = result[0];
        sum0 = 0;
        for (int k = 0; k < TEST_N_MAX; k++) {
            sum0 = sum0 * 10 + s0[k];
        }
        /* 第一个排列组合必然是[0, 0, 0, 0] */
        assert(sum0 == 0);
        for (int j = 0; j < result.size()-1; j++) {
            int *s1, *s2;
            int sum1 = 0, sum2 = 0;
            s1 = result[j];
            s2 = result[j + 1];
            /* 排列组合的所有情况相当于依次递增的TEST_N_MAX位i进制正整数 */
            for (int k = 0; k < TEST_N_MAX; k++) {
                sum1 = sum1 * i + s1[k];
                sum2 = sum2 * i + s2[k];
            }
            assert(sum1 == sum2 - 1);
        }
        for (int k = 0; k < result.size(); k++) {
            delete[] result[k];
        }
    }

    return 0;
}
