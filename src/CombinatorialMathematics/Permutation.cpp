#include "Permutation.hpp"
#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;

#define TEST_MAX 8

int PermutationCount(int n, int m) {
    int count = 1;
    for (int i = 1; i <= n; i++) {
        count *= i;
    }
    for (int i = 1; i <= n - m; i++) {
        count /= i;
    }
    return count;
}

void AssertDifference(const vector<vector<int>>& vs) {
    for (int i = 0; i < vs.size(); i++)
        for (int j = i + 1; j < vs.size(); j++) {
            assert(vs[i] != vs[j]);
        }
}

int main() {
    int s[MAX];
    for (int i = 0; i < MAX; i++) {
        s[i] = i;
    }

    for (int n = 1; n < TEST_MAX; n++) {
        for (int m = 1; m <= n; m++) {
            vector<vector<int>> result = Permutation(s, n, m);
            int count = PermutationCount(n, m);
            cout << "n: " << n << ", m: " << m
                 << ", result.size: " << result.size() << ", count: " << count
                 << endl;
            assert(result.size() == count);
            for (int i = 0; i < result.size(); i++) {
                assert(result[i].size() == m);
            }
            AssertDifference(result);
        }
    }

    return 0;
}
