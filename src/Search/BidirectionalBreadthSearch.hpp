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
    int col;
    int row;

    Position() : col(0), row(0) {}
    Position(int c, int r) : col(c), row(r) {}
    bool operator==(const Position & other) { return col == other.col and row == other.row; }
    bool operator!=(const Position & other) { return not (*this == other); }
};

/*
struct PathPosition {
    Position current;
    Position father;

    PathPosition() : current(), father() {}
    PathPosition(int c, int r, int father_c, int father_r)
            : current(c, r), father(father_c, father_r) {}
    PathPosition(const Position & current_, const Position & father_)
            : current(current_), father(father_) {}

    bool operator==(const PathPosition & other) { return current == other.current; }
    bool operator!=(const PathPosition & other) { return current != other.current; }
};
*/

// const Position invalid_position(-1, -1);
// const pair<Position, Position> invalid_pair(invalid_position, invalid_position);

/* 4个方向: 上 下 右 左 */
/* m行n列二维方格 col范围[0, m) row范围[0, n)*/
const int direction_col[4] = { 1, -1, 0, 0 };
const int direction_row[4] = { 0, 0, 1, -1 };

auto BidirectionalPath(Position beg_father[MAX][MAX],
                       Position end_father[MAX][MAX],
                       Position beg, Position end, Position meet_pos) -> deque<Position>
{
    deque<Position> path;
    Position t = meet_pos;

    while (t != beg) {
        path.push_front(t);
        t = beg_father[t.col][t.row];
    }
    path.push_front(beg);
    t = end_father[meet_pos.col][meet_pos.row];
    while (t != end) {
        path.push_back(t);
        t = end_father[t.col][t.row];
    }
    if (path.back() != end) {
        path.push_back(end);
    }

    return path;
}

bool InRange(int pos, int range)
{
    return pos >= 0 and pos < range;
}

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
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
    /* x.col 范围是[0, m) */
    /* x.row 范围是[0, n) */
    beg_visit[beg.col][beg.row] = 1;
    end_visit[end.col][end.row] = 1;

    while (true) {
        /* 先扩展beg_que */
        Position beg_node = beg_que.front();
        beg_que.pop_front();
        if (end_visit[beg_node.col][beg_node.row]) {
            deque<Position> path = BidirectionalPath(beg_father, end_father, beg, end, beg_node);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_col = beg_node.col + direction_col[i];
            int neighbor_row = beg_node.row + direction_row[i];

            if (InRange(neighbor_col, m) and InRange(neighbor_row, n) and beg_visit[neighbor_row][neighbor_col] == 0) {
                beg_que.push_back( Position(neighbor_row, neighbor_col) );
                beg_visit[neighbor_col][neighbor_row] = 1;
                beg_father[neighbor_col][neighbor_row] = Position(beg_node.col, beg_node.row);
            }
        }

        /* 后扩展end_que */
        Position end_node = end_que.front();
        end_que.pop_front();
        if (beg_visit[end_node.col][end_node.row]) {
            deque<Position> path = BidirectionalPath(beg_father, end_father, beg, end, end_node);
            return path;
        }
        for (int i = 0; i < 4; i++) {
            int neighbor_col = end_node.col + direction_col[i];
            int neighbor_row = end_node.row + direction_row[i];
            if (InRange(neighbor_col, m) and InRange(neighbor_row, n) and not end_visit[neighbor_col][neighbor_row] ) {
                end_que.push_back(Position(neighbor_col, neighbor_row));
                end_visit[neighbor_col][neighbor_row] = 1;
                end_father[neighbor_col][neighbor_row] = Position(end_node.col, end_node.row);
            }
        }
    }

    return deque<Position>();
}

#endif
