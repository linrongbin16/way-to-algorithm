#ifndef BIDIRECTIONAL_BREADTH_SEARCH_HPP
#define BIDIRECTIONAL_BREADTH_SEARCH_HPP 1

#include <utility>
#include <deque>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct BiNode
{
    int row;
    int col;
    int father_row;
    int father_col;

    BiNode()
    { }

    BiNode(int row_, int col_, int father_row_, int father_col_)
    {
        row = row_;
        col = col_;
        father_row = father_row_;
        father_col = father_col_;
    }
    bool operator==(const BiNode &node_) const
    {
        return row == node_.row && col == node_.col;
    }
    bool operator!=(const BiNode &node_) const
    {
        return row != node_.row || col != node_.col;
    }
};

const BiNode invalid_node(-1, -1, -1, -1);
const pair<BiNode, BiNode> invalid_node_pair(invalid_node, invalid_node);
/* 4个方向: 上 下 右 左 */
/* m行n列二维方格 row范围[0, m) col范围[0, n)*/
const int direction_row[4] = { 0, 0, 1, -1 };
const int direction_col[4] = { 1, -1, 0, 0 };

int beg_visit[MAX][MAX], end_visit[MAX][MAX];
pair<int, int> beg_father[MAX][MAX], end_father[MAX][MAX];


void BidirectionalPath(pair<int, int> beg, pair<int, int> end, pair<int, int> meet_node, deque<pair<int, int> > &path)
{
    pair<int, int> t = meet_node;
    while (t != beg) {
        path.push_front(t);
        t = beg_father[t.first][t.second];
    }
    path.push_front(beg);
    t = end_father[meet_node.first][meet_node.second];
    while (t != end) {
        path.push_back(t);
        t = end_father[t.first][t.second];
    }
    if (path[path.size()-1] != end) {
        path.push_back(end);
    }
}

deque<pair<int, int> > BidirectionalBreadthSearch(int m, int n, pair<int, int> beg, pair<int, int> end)
{
    memset(beg_visit, 0, MAX * MAX * sizeof(int));
    memset(end_visit, 0, MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            beg_father[i][j] = pair<int, int>(i, j);
            end_father[i][j] = pair<int, int>(i, j);
        }

    deque<pair<int, int> > beg_que, end_que;
    beg_que.push_back(beg);
    end_que.push_back(end);
    /* x.first是row 范围是[0, m) */
    /* x.second是col 范围是[0, n) */
    beg_visit[beg.first][beg.second] = 1;
    end_visit[end.first][end.second] = 1;
    while (true) {
        /* 先扩展beg_que */
        pair<int, int> beg_node = beg_que.front();
        beg_que.pop_front();
        if (end_visit[beg_node.first][beg_node.second] == 1) {
            deque<pair<int, int> > path;
            BidirectionalPath(beg, end, beg_node, path);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_row = beg_node.first + direction_row[i];
            int neighbor_col = beg_node.second + direction_col[i];
            if (neighbor_row >= 0 && neighbor_row < m && neighbor_col >= 0 && neighbor_col < n
                && beg_visit[neighbor_row][neighbor_col] == 0) {
                beg_que.push_back(pair<int, int>(neighbor_row, neighbor_col));
                beg_visit[neighbor_row][neighbor_col] = 1;
                beg_father[neighbor_row][neighbor_col] = pair<int, int>(beg_node.first, beg_node.second);
            }
        }

        /* 后扩展end_que */
        pair<int, int> end_node = end_que.front();
        end_que.pop_front();
        if (beg_visit[end_node.first][end_node.second] == 1) {
            deque<pair<int, int> > path;
            BidirectionalPath(beg, end, end_node, path);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_row = end_node.first + direction_row[i];
            int neighbor_col = end_node.second + direction_col[i];
            if (neighbor_row >= 0 && neighbor_row < m && neighbor_col >= 0 && neighbor_col < n
                && end_visit[neighbor_row][neighbor_col] == 0) {
                end_que.push_back(pair<int, int>(neighbor_row, neighbor_col));
                end_visit[neighbor_row][neighbor_col] = 1;
                end_father[neighbor_row][neighbor_col] = pair<int, int>(end_node.first, end_node.second);
            }
        }
    }

    return deque<pair<int, int> >();
}

#endif
