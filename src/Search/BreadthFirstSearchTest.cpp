#include <cassert>
#include "BreadthFirstSearch.h"
using namespace std;

#define TEST_M_MAX MAX
#define TEST_N_MAX MAX

auto AssertAdjacent(const Node& a, const Node& b) -> void
{
    bool a1 = (a.row == b.row) && (a.col == b.col + 1);
    bool a2 = (a.row == b.row) && (a.col == b.col - 1);
    bool a3 = (a.row == b.row + 1) && (a.col == b.col);
    bool a4 = (a.row == b.row - 1) && (a.col == b.col);
    assert(a1 || a2 || a3 || a4);
}

int main()
{
    for (int i = 1; i < TEST_M_MAX; i++)
        for (int j = 1; j < TEST_N_MAX; j++) {
            Node beg(0, 0);
            Node end(i - 1, j - 1);
            vector<Node> path = BreadthFirstSearch(i, j, beg, end);
            /* 保证路径长度为 j-1+i-1+1 */
            assert(path.size() == (i - 1 + j - 1 + 1));
            /* 保证起点和终点位置 */
            assert(path[0] == beg);
            assert(path[path.size() - 1] == end);
            for (int k = 0; k < path.size() - 1; k++) {
                /* 保证路径中相邻两点在二维方格中也是相邻点 */
                AssertAdjacent(path[k], path[k + 1]);
            }
        }

    return 0;
}
