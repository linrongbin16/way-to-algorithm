#include "Recursion.hpp"
#include <cmath>
#include <cassert>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8


auto AssertUnique(const vector<vector<int>> & v) -> void
{
    unordered_set<string> uniques;
    vector<string> v2;
    for (int i = 0; i < v.size(); i++) {
        string tmp;
        for (int j = 0; j < v[i].size(); j++) {
            tmp.append(to_string(v[i][j]));
        }
        v2.push_back(tmp);
    }
    for (int i = 0; i < v2.size(); i++) {
        assert(uniques.find(v2[i]) == uniques.end());
        uniques.insert(v2[i]);
    }
}

auto main() -> int {
    for (int i = 1; i < TEST_N_MAX; i++)
        for (int j = 1; j < TEST_M_MAX; j++) {
            vector<int> tmp(i, 0);
            vector<vector<int>> result;
            vector<int> candidates(j, 0);
            for (int k = 0; k < j; k++) candidates[k] = k;
            Recursion(tmp, candidates, 0, result);
            assert( (double)result.size() == std::pow<double>(j, i) );
            AssertUnique(result);
        }
    return 0;
}
