#include "DuplicableCombination.hpp"
#include <cassert>
#include <unordered_set>
#include <string>
#include <cmath>

using namespace std;

#define MAX 64

void AssertUnique(const vector<vector<int>> &v) {
    unordered_set<string> us;
    for (int i = 0; i < v.size(); i++) {
        string tmp;
        for (int j = 0; j < v[i].size(); j++) {
            tmp.append(to_string(v[i][j]));
        }
        assert( us.find(tmp) == us.end() );
        us.insert(tmp);
    }
}

int main()
{
    for (int i = 1; i < MAX; i++) {
        //初始化数组s
        vector<int> s(i, 0);
        for (int j = 0; j < i; j++) {
            s[j] = j;
        }
        for (int j = 1; j <= i; j++) {
            vector<vector<int>> ret = DuplicableCombination(s, j);
            assert( (double)ret.size() == std::pow<double>(j, i) );
            AssertUnique(ret);
        }
    }
    return 0;
}
