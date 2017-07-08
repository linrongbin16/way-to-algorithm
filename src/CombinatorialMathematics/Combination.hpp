#ifndef COMBINATION_HPP
#define COMBINATION_HPP

// #include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

void MakeChoice(vector<int> & choose, int prev, int prev_one, int s[MAX], int n, int m, vector<unordered_set<int>> & comb)
{
    if (prev == m) {
        /*
        cout << "choose: ";
        for (int i = 0; i < choose.size(); i++) {
            cout << choose[i]<< " ";
        }
        cout << endl;
        */

        unordered_set<int> tmp;
        for (int i = 0; i < choose.size(); i++) {
            if (choose[i] == 1)
                tmp.insert(s[i]);
        }
        comb.push_back(tmp);
        return;
    }

    // prev从0开始 每次增加一个1 
    // prev_one表示上一轮的数组中最后一个1的位置
    for (int i = prev_one+1; i < n; i++) {
        if (choose[i] == 0) {
            choose[i] = 1;
            MakeChoice(choose, prev+1, i, s, n, m, comb);
            choose[i] = 0;
        }
    }
}

vector<unordered_set<int>> Combination(int s[MAX], int n, int m)
{
    // 初始化choose=[0, 0, 0, ..., 0]
    vector<int> choose;
    for (int i = 0; i < n; i++) {
        choose.push_back(0);
    }
    vector<unordered_set<int>> comb;

    // 初始时 1的数量为0个 最后一个1的位置为-1
    MakeChoice(choose, 0, -1, s, n, m, comb);

    /*
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
