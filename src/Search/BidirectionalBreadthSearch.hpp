#ifndef BIDIRECTIONAL_BREADTH_SEARCH_HPP
#define BIDIRECTIONAL_BREADTH_SEARCH_HPP 1

#include <utility>
#include <deque>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 64
#endif

struct Position
{
    int row;
    int col;

    Position() : row(0), col(0) {}
    Position(int row_, int col_) : row(row_), col(col_) {}
    bool operator==(const Position & other) { return row == other.row and col == other.col; }
    bool operator!=(const Position & other) { return row != other.row or col != other.col; }
};

struct PathPosition {
    Position current;
    Position father;

    PathPosition() : current(), father() {}
    PathPosition(int row_, int col_, int father_row_, int father_col_)
            : current(row_, col_), father(father_row_, father_col_) {}
    PathPosition(const Position & current_, const Position & father_)
            : current(current_), father(father_) {}

    bool operator==(const PathPosition & other) { return current == other.current; }
    bool operator!=(const PathPosition & other) { return current != other.current; }
};

const Position invalid_position(-1, -1, -1, -1);
const pair<Position, Position> invalid_pair(invalid_position, invalid_position);

/* 4个方向: 上 下 右 左 */
/* m行n列二维方格 row范围[0, m) col范围[0, n)*/
const int direction_row[4] = { 0, 0, 1, -1 };
const int direction_col[4] = { 1, -1, 0, 0 };

void BidirectionalPath(Position beg_father[MAX][MAX], Position end_father[MAX][MAX],
                       Position beg, Position end, Position meet_pos, deque<Position> & path)
{
    Position t = meet_pos;
    while (t != beg) {
        path.push_front(t);
        t = beg_father[t.row][t.col];
    }
    path.push_front(beg);
    t = end_father[meet_pos.row][meet_pos.col];
    while (t != end) {
        path.push_back(t);
        t = end_father[t.row][t.col];
    }
    if (path.back() != end) {
        path.push_back(end);
    }
}

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m
 * @param n
 * @param beg
 * @param end
 * @return
 */
auto BidirectionalBreadthSearch(int m, int n, Position beg, Position end) -> deque<Position>
{
    int beg_visit[MAX][MAX], end_visit[MAX][MAX];
    Position beg_father[MAX][MAX], end_father[MAX][MAX];

    memset(beg_visit, 0, sizeof(beg_visit));
    memset(end_visit, 0, sizeof(end_visit));

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++) {
            beg_father[i][j] = Position(i, j);
            end_father[i][j] = Position(i, j);
        }

    deque<Position> beg_que, end_que;
    beg_que.push_back(beg);
    end_que.push_back(end);
    /* x.row是row 范围是[0, m) */
    /* x.col是col 范围是[0, n) */
    beg_visit[beg.row][beg.col] = 1;
    end_visit[end.row][end.col] = 1;
    while (true) {
        /* 先扩展beg_que */
        pair<int, int> beg_node = beg_que.front();
        beg_que.pop_front();
        if (end_visit[beg_node.row][beg_node.col] == 1) {
            deque<pair<int, int> > path;
            BidirectionalPath(beg, end, beg_node, path);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_row = beg_node.row + direction_row[i];
            int neighbor_col = beg_node.col + direction_col[i];
            if (neighbor_row >= 0 and neighbor_row < m and neighbor_col >= 0 and neighbor_col < n
                and beg_visit[neighbor_row][neighbor_col] == 0) {
                beg_que.push_back(pair<int, int>(neighbor_row, neighbor_col));
                beg_visit[neighbor_row][neighbor_col] = 1;
                beg_father[neighbor_row][neighbor_col] = pair<int, int>(beg_node.row, beg_node.col);
            }
        }

        /* 后扩展end_que */
        pair<int, int> end_node = end_que.front();
        end_que.pop_front();
        if (beg_visit[end_node.row][end_node.col] == 1) {
            deque<pair<int, int> > path;
            BidirectionalPath(beg, end, end_node, path);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_row = end_node.row + direction_row[i];
            int neighbor_col = end_node.col + direction_col[i];
            if (neighbor_row >= 0 and neighbor_row < m and neighbor_col >= 0 and neighbor_col < n
                and end_visit[neighbor_row][neighbor_col] == 0) {
                end_que.push_back(pair<int, int>(neighbor_row, neighbor_col));
                end_visit[neighbor_row][neighbor_col] = 1;
                end_father[neighbor_row][neighbor_col] = pair<int, int>(end_node.row, end_node.col);
            }
        }
    }

    return deque<pair<int, int> >();
}

#endif
