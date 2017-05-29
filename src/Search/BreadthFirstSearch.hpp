#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP 1

#include <deque>
#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct Position {
    int row;
    int col;

    Position() : row(0), col(0) {}
    Position(int r, int c) : row(r), col(c) {}
    bool operator==( const Position & other) { return row == other.row and col == other.col; }
    bool operator!=( const Position & other) { return not (*this == other); }
};

/* 4个方向: 上 下 右 左 */
/* m行n列二维方格 row范围[0, m) col范围[0, n)*/
const int direction_col[4] = { 0, 0, 1, -1 };
const int direction_row[4] = { 1, -1, 0, 0 };

/* 递归生成从beg到end的路径 */
auto BFSPath(Position father[MAX][MAX], Position end, vector<Position> &path) -> void
{
    if (father[end.row][end.col] != end) {
        BFSPath(father, father[end.row][end.col], path);
    }
    path.push_back(end);
}

auto BreadthFirstSearch(int m, int n, Position beg, Position end) -> vector<Position>
{
    Position father[MAX][MAX];
    int visit[MAX][MAX];

    memset(visit, 0, MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            father[i][j] = Position(i, j);

    deque<Position> que;
    que.push_back(beg);
    /* beg.first是row 范围是[0, m) */
    /* beg.second是col 范围是[0, n) */
    visit[beg.row][beg.col] = 1;

    while (!que.empty()) {
        Position node = que.front();
        que.pop_front();
        if (node == end) {
            vector<Position> path;
            BFSPath(father, node, path);
            return path;
        }

        /* 上下左右4个方向 */
        for (int i = 0; i < 4; i++) {
            int neighbor_row = node.row + direction_row[i];
            int neighbor_col = node.col + direction_col[i];
            /* 检查边界和是否访问过/染红 */
            if (neighbor_row >= 0
                and neighbor_row < m
                and neighbor_col >= 0
                and neighbor_col < n
                and not visit[neighbor_row][neighbor_col]) {
                /* 加入等待队列 */
                que.push_back(Position(neighbor_row, neighbor_col));
                /* 染红 */
                visit[neighbor_row][neighbor_col] = 1;
                /* 记录父节点 */
                father[neighbor_row][neighbor_col] = Position(node.row, node.col);
            }
        }
    }

    return vector<Position>();
}

#endif
