#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP 1

#include <deque>
#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

/* 4个方向: 上 下 右 左 */
/* m行n列二维方格 row范围[0, m) col范围[0, n)*/
const int direction_col[4] = { 0, 0, 1, -1 };
const int direction_row[4] = { 1, -1, 0, 0 };

int visit[MAX][MAX];
pair<int, int> father[MAX][MAX];

/* 递归生成从beg到end的路径 */
void BFSPath(pair<int, int> end, vector<pair<int, int> > &path)
{
    if (father[end.first][end.second] != end) {
        BFSPath(father[end.first][end.second], path);
    }
    path.push_back(end);
}

vector<pair<int, int> > BreadthFirstSearch(int m, int n, pair<int, int> beg, pair<int, int> end)
{
    memset(visit, 0, MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            father[i][j] = pair<int, int>(i, j);

    deque<pair<int, int> > que;
    que.push_back(beg);
    /* beg.first是row 范围是[0, m) */
    /* beg.second是col 范围是[0, n) */
    visit[beg.first][beg.second] = 1;

    while (!que.empty()) {
        pair<int, int> node = que.front();
        que.pop_front();
        if (node == end) {
            vector<pair<int, int> > path;
            BFSPath(node, path);
            return path;
        }

        /* 上下左右4个方向 */
        for (int i = 0; i < 4; i++) {
            int neighbor_row = node.first + direction_row[i];
            int neighbor_col = node.second + direction_col[i];
            /* 检查边界和是否访问过（即染红） */
            if (neighbor_row >= 0 && neighbor_row < m && neighbor_col >= 0 && neighbor_col < n
                && visit[neighbor_row][neighbor_col] == 0) {
                /* 加入等待队列 */
                que.push_back(pair<int, int>(neighbor_row, neighbor_col));
                /* 染红 */
                visit[neighbor_row][neighbor_col] = 1;
                /* 记录父节点 */
                father[neighbor_row][neighbor_col] = pair<int, int>(node.first, node.second);
            }
        }
    }

    return vector<pair<int, int> >();
}

#endif
