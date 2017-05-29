#include "Recursion.hpp"
#include <cmath>
#include <cassert>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

#define TEST_N_MAX 8
#define TEST_M_MAX 8

auto VectorToString(const vector<int> & v) -> string
{
    string s;
    for (int i = 0; i < v.size(); i++) {
        s += to_string(v[i]);
    }
    return s;
}

auto AssertUnique(const vector<string> & v) -> void
{
    unordered_set<string> uniques;
    for (int i = 0; i < v.size(); i++) {
        assert(uniques.find(v[i]) == uniques.end());
        uniques.insert(v[i]);
    }
}

auto main() -> int
{
    int s[MAX];

    for (int i = 1; i < TEST_N_MAX; i++)
        for (int j = 1; j < TEST_M_MAX; j++) {
            vector<vector<int>> result;
            Recursion(s, i, j, 0, result);
            assert( (double)result.size() == std::pow<double>(j, i) );
            vector<string> r;
            for (int k = 0; k < result.size(); k++) {
                for (int p = 0; p < result[k].size(); p++) {
                    assert(result[k][p] >= 0);
                    assert(result[k][p] <= j);
                }
                string tmp = VectorToString(result[k]);
                r.push_back(tmp);
            }
            AssertUnique(r);
        }
    return 0;
}
