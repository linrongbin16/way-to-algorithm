#include "header.hpp"
#include <cassert>
using namespace std;

#define TEST_M_MAX 16
#define TEST_N_MAX 16

int main()
{
    for (int i = 1; i < TEST_M_MAX; i++)
        for (int j = 1; j < TEST_N_MAX; j++) {
            pair<int, int> beg(0, 0);
            pair<int, int> end(j - 1, i - 1);
            vector<pair<int, int> > path = BreadthFirstSearch(i, j, pair<int, int>(0, 0), pair<int, int>(j - 1, i - 1));
            /* 保证路径长度为 j-1+i-1+1 */
            assert(path.size() == ((j - 1) + (i - 1) + 1));
            /* 保证起点和终点位置 */
            assert(path[0] == beg);
            assert(path[path.size() - 1] == end);
            for (int k = 0; k < path.size() - 1; k++) {
                /* 保证路径中相邻两点在二维方格中也是相邻点 */
                assert((path[k].first == path[k + 1].first
                    && path[k].second == path[k + 1].second + 1)
                    || (path[k].first == path[k + 1].first
                        && path[k].second == path[k + 1].second - 1)
                    || (path[k].first == path[k + 1].first + 1
                        && path[k].second == path[k + 1].second)
                    || (path[k].first == path[k + 1].first - 1
                        && path[k].second == path[k + 1].second));
            }
        }
    return 0;
}

