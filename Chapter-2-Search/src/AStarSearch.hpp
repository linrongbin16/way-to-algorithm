#ifndef A_STAR_SEARCH_HPP
#define A_STAR_SEARCH_HPP 1

#include <algorithm>
#include <deque>
#include <vector>
#include <cstdlib>
#include <climits>
using namespace std;
#ifndef MAX
#define MAX 64
#endif
#ifndef INF
#define INF INT_MAX
#endif

/* 4个方向 上下左右 */
const int direction_col[4] = { 0, 0, 1, -1 };
const int direction_row[4] = { 1, -1, 0, 0 };

int g_score[MAX][MAX];
pair<int, int> father[MAX][MAX];

int HScoreDiff(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
pair<int, int> OpenQueueMinimum(deque<pair<int, int> > &openQue, pair<int, int> a)
{
    pair<int, int> res;
    int minf = INF;
    for (int i = 0; i < openQue.size(); i++) {
        int row = openQue[i].first;
        int col = openQue[i].second;
        int h = HScoreDiff(openQue[i], a);
        if (minf > h + g_score[row][col]) {
            minf = h + g_score[row][col];
            res = openQue[i];
        }
    }
    return res;
}
void OpenQueueErase(deque<pair<int, int> > &openQue, pair<int, int> a)
{
    for (deque<pair<int, int> >::iterator i = openQue.begin(); i != openQue.end(); i++) {
        if (a == *i) {
            openQue.erase(i);
            break;
        }
    }
}
bool QueueContain(deque<pair<int, int> > &que, pair<int, int> a)
{
    for (deque<pair<int, int> >::iterator i = que.begin(); i != que.end(); i++) {
        if (a == *i) {
            return true;
        }
    }
    return false;
}

void AStarPath(const deque<pair<int, int> > &closeQue, 
    pair<int, int> beg, pair<int, int> end, vector<pair<int, int> > &path)
{
    deque<pair<int, int> > duePath;
    while (end != beg) {
        duePath.push_front(end);
        for (int i = 0; i < closeQue.size(); i++) {
            if (closeQue[i] == father[end.first][end.second]) {
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

vector<pair<int, int> > AStarSearch(int m, int n, pair<int, int> beg, pair<int, int> end)
{
    deque<pair<int, int> > openQue;
    deque<pair<int, int> > closeQue;
    /* beg.first 是row 范围[0, m-1] */
    /* beg.second 是col 范围[0, n-1] */
    openQue.push_back(beg);
    while (!openQue.empty()) {
        pair<int, int> min_node = OpenQueueMinimum(openQue, end);

        if (min_node == end) {
            closeQue.push_back(min_node);
            vector<pair<int, int> > path;
            AStarPath(closeQue, beg, min_node, path);
            return path;
        }

        closeQue.push_back(min_node);
        OpenQueueErase(openQue, min_node);

        /* min_node 考虑上下左右4个方向 */
        for (int i = 0; i < 4; i++) {
            int row = min_node.first + direction_row[i];
            int col = min_node.second + direction_col[i];
            pair<int, int> p = pair<int, int>(row, col);
            if (row >= 0 && row < m && col >= 0 && col < n) {
                /* p点的g值和h值 */
                int g = g_score[min_node.first][min_node.second] + 1;
                int h = HScoreDiff(p, end);
                /* p的父节点为min_node */
                //father[p.first][p.second] = min_node;

                /* 若close队列中已经存在p点 跳过 */
                if (QueueContain(closeQue, p))
                    continue;
                /* 若close队列中不存在p点 open队列中存在p点 更新路径 */
                if (QueueContain(openQue, p)) {
                    /* 更新p的父节点和g值 获得更短路径 */
                    if (g < g_score[p.first][p.second]) {
                        father[p.first][p.second] = min_node;
                        g_score[p.first][p.second] = g;
                    }
                }
                else {
                    /* 若close队列中不存在p点 open队列中不存在p点 加入open队列 */
                    openQue.push_back(p);
                    /* p的父节点为min_node */
                    father[p.first][p.second] = min_node;
                    g_score[p.first][p.second] = g;
                }
            }
        }
    }

    return vector<pair<int, int> >();
}

#endif
