#include "FullPermutation.hpp"
#include <cassert>
#include <unordered_set>
#include <iostream>

#define TEST_MAX 32

int FullPermutationCount(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++) {
        count *= i;
    }
    return count;
}

int main()
{
    int s[MAX];
    for (int i = 0; i < MAX; i++) {
        s[i] = i;
    }

    for (int n = 1; n < TEST_MAX; n++) {
        unordered_set<int> ss;
        for (int i = 0; i < n; i++) {
            ss.insert(i);
        }

        vector<vector<int>> result = FullPermutation(s, n);
        cout << "n: " << n << ", result.size: " << result.size() << ", count: " << FullPermutationCount(n) << endl;
        assert( result.size() == FullPermutationCount(n) );
        for (int i = 0; i < result.size(); i++) {
            unordered_set<int> rs;
            for (int j = 0; j < result[i].size(); j++)
                rs.insert(result[i][j]);
            assert(rs == ss);
        }
    }

    return 0;
}