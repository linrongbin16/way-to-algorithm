#ifndef EIGHT_FIGURE_PUZZLE_HPP
#define EIGHT_FIGURE_PUZZLE_HPP 1

/* 八数码问题 */

#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif
#ifndef INF
#define INF INT_MAX
#endif


struct PuNode
{
    char value[9];
    int hScore;
    int gScore;
    char fatherValue[9];

    bool operator==(const PuNode &node_) const
    {
        return memcmp(value, node_.value, 9) == 0;
    }
    bool operator!=(const PuNode &node_) const
    {
        return memcmp(value, node_.value, 9) != 0;
    }
};

/*
将矩阵
0 1 2
3 4 5
6 7 8
表示为char[9]数组
*/
const int direction[4] = { -3, 3, -1, 1 };

int XPosition(PuNode a)
{
    int i;
    for (i = 0; i < 9; i++)
        if (a.value[i] == 'x')
            break;
    return i;
}
bool InsideBoundary(int pos)
{
    return pos >= 0 && pos < 9;
}
int HScoreDiff(PuNode a, PuNode b)
{
    int diff = 0;
    for (int i = 0; i < 9; ++i)
        if (a.value[i] != b.value[i])
            ++diff;
    return diff;
}
PuNode OpenQueueMinimum(deque<PuNode> &openQue, PuNode a)
{
    PuNode res;
    int minf = INF;
    for (int i = 0; i < openQue.size(); i++) {
        int h = HScoreDiff(openQue[i], a);
        if (minf > h + openQue[i].gScore) {
            minf = h + openQue[i].gScore;
            res = openQue[i];
        }
    }
    return res;
}
void OpenQueueErase(deque<PuNode> &openQue, PuNode a)
{
    for (deque<PuNode>::iterator i = openQue.begin(); i != openQue.end(); i++) {
        if (a == *i) {
            openQue.erase(i);
            break;
        }
    }
}
bool QueueContain(deque<PuNode> &que, PuNode a, deque<PuNode>::iterator &out_iter)
{
    for (deque<PuNode>::iterator i = que.begin(); i != que.end(); i++) {
        if (a == *i) {
            out_iter = i;
            return true;
        }
    }
    return false;
}

void PuzzlePath(const deque<PuNode> &closeQue, PuNode beg, PuNode end, vector<PuNode> &path)
{
    deque<PuNode> duePath;
    while (end != beg) {
        duePath.push_front(end);
        for (int i = 0; i < closeQue.size(); i++) {
            if (memcmp(closeQue[i].value, end.fatherValue, 9) == 0) {
                end = closeQue[i];
                break;
            }
        }
    }
    duePath.push_front(beg);

    for (int i = 0; i < duePath.size(); i++) {
        path.push_back(duePath[i]);
    }
}

vector<PuNode> EightFigurePuzzle(PuNode beg, PuNode end)
{
    deque<PuNode> openQue;
    deque<PuNode> closeQue;
    openQue.push_back(beg);
    while (!openQue.empty()) {
        PuNode min_node = OpenQueueMinimum(openQue, end);

        if (min_node == end) {
            closeQue.push_back(min_node);
            vector<PuNode> path;
            PuzzlePath(closeQue, beg, min_node, path);
            return path;
        }

        closeQue.push_back(min_node);
        OpenQueueErase(openQue, min_node);

        int x_pos = XPosition(min_node);

        /* min_node中x与上下左右4个方向的数字交换位置 */
        for (int i = 0; i < 4; i++) {
            int swap_position = x_pos + direction[i];
            if (InsideBoundary(swap_position)) {
                PuNode p;
                deque<PuNode>::iterator result;
                memcpy(p.value, min_node.value, 9);
                swap(p.value[x_pos], p.value[swap_position]);
                p.gScore = min_node.gScore + 1;
                p.hScore = HScoreDiff(p, end);
                memcpy(p.fatherValue, min_node.value, 9);

                /* 若close队列中已经存在p点 跳过 */
                if (QueueContain(closeQue, p, result))
                    continue;
                /* 若close队列中不存在p点 open队列中存在p点 更新路径 */
                if (QueueContain(openQue, p, result)) {
                    /* 更新父节点和g值 获得更短路径 */
                    if (p.gScore < result->gScore) {
                        memcpy(result->fatherValue, min_node.value, 9);
                        result->gScore = p.gScore;
                    }
                }
                else {
                    /* 若close队列中不存在p点 open队列中不存在p点 加入open队列 */
                    openQue.push_back(p);
                }
            }
        }
    }

    return vector<PuNode>();
}

#endif
