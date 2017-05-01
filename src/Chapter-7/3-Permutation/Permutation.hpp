#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

// #include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include "Combination.hpp"
#include "FullPermutation.hpp"
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

int *SetToArray(unordered_set<int> & us)
{
    int *s = new int[MAX];
    unordered_set<int>::iterator i;
    int j;
    for (i = us.begin(), j = 0; i != us.end(); i++, j++)
        s[j] = *i;
    return s;
}

void MergePermutation(vector<vector<int>> & result, vector<vector<int>> & merge)
{
    for (int i = 0; i < merge.size(); i++) {
        result.push_back(merge[i]);
    }
}

vector<vector<int>> Permutation(int s[MAX], int n, int m)
{
    vector<unordered_set<int>> comb = Combination(s, n, m);

    vector<vector<int>> perm;

    for (int i = 0; i < comb.size(); i++) {
        int *tmp = SetToArray(comb[i]);
        vector<vector<int>> fperm = FullPermutation(tmp, comb[i].size());
        delete[] tmp;
        MergePermutation(perm, fperm);
    }

    /*
    cout << endl; 
    for (int i = 0; i < perm.size(); i++) {
        for (int j = 0; j < perm[i].size(); j++)
            cout << perm[i][j] << " ";
        cout << endl; 
    }
    */
    

    return perm;
}


#endif
