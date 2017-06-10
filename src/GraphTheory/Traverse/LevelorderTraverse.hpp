#ifndef LEVELORDER_TRAVERSE_HPP
#define LEVELORDER_TRAVERSE_HPP

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif


/* 节点i的左孩子节点为i*2+1 右孩子节点为i*2+2 */
/* 根节点为0 */
auto LevelorderTraverse(int n) -> vector<int>
{
    vector<int> seq;

    deque<int> dequeue;
    dequeue.push_back(0);

    while (!dequeue.empty()) {
        int index = dequeue.front();
        dequeue.pop_front();
        seq.push_back(index);
        int left_index = index * 2 + 1;
        int right_index = index * 2 + 2;
        if (left_index >= 0 and left_index < n) dequeue.push_back(left_index);
        if (right_index >= 0 and right_index < n) dequeue.push_back(right_index);
    }

    return seq;
}



#endif
