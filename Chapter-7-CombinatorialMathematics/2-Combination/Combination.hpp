#ifndef COMBINATION_HPP
#define COMBINATION_HPP

//#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

unordered_set<int> MakeChoice(int s[MAX], vector<int> & choose)
{
    unordered_set<int> r;
    for (int i = 0; i < choose.size(); i++)
        if (choose[i])
            r.insert(s[i]);
    return r;
}

void MoveOneToHead(vector<int> & vec, int n)
{
    int i = 0, j = n-1;
    while (i < j) {
        while (vec[i] == 1 && i < j)
            i++;
        while (vec[j] == 0 && i < j)
            j--;
        std::swap(vec[i], vec[j]);
    }
}

bool NextChoice(vector<int> & vec)
{
    for (int i = 0; i < vec.size()-1; i++) {
        if (vec[i] == 1 && vec[i+1] == 0) {
            std::swap(vec[i], vec[i+1]);

            // 将i之前的1都移动到前面 0移动到后面
            // 得到的结果为 |1|1|...|1|0|0|...|0|i|...
            MoveOneToHead(vec, i);
            return true;
        }
    }
    return false;
}

vector<unordered_set<int>> Combination(int s[MAX], int n, int m)
{
    // 初始化 A=[1, 1, 1, 0, ..., 0]
    vector<int> choose;
    for (int i = 0; i < n; i++) {
        if (i < m)
            choose.push_back(1);
        else
            choose.push_back(0);
    }

    vector<unordered_set<int>> comb;

    do {
        comb.push_back(MakeChoice(s, choose));
    } while (NextChoice(choose));

    /*
    cout << endl;
    for (int i = 0; i < comb.size(); i++) {
        for (unordered_set<int>::iterator j = comb[i].begin(); j != comb[i].end(); j++) {
            cout << *j << " ";
        }
        cout << endl;
    }
    */

    return comb;
}


#endif
