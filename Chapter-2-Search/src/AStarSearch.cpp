#include "AStarSearch.hpp"
#include <assert.h>
using namespace std;

bool IsAdjacentNode(pair<int, int> a, pair<int, int> b)
{
    int diff = 0;
    int pos1, pos2;
    return (a.first == b.first + 1 && a.second == b.second)
        || (a.first == b.first - 1 && a.second == b.second)
        || (a.first == b.first && a.second == b.second + 1)
        || (a.first == b.first && a.second == b.second - 1);
}

void UnitTest(int m, int n, pair<int, int> beg, pair<int, int> end)
{
    vector<pair<int, int> > path = AStarSearch(m, n, beg, end);
    assert(path.size() > 0);
    assert(path[0] == beg);
    assert(path[path.size() - 1] == end);
    for (int i = 0; i < path.size() - 1; i++) {
        assert(IsAdjacentNode(path[i], path[i + 1]));
    }
}


#define TEST_MAX 10

int main()
{
    pair<int, int> beg, end;
    for (int i = 0; i < TEST_MAX; i++)
        for (int j = 0; j < TEST_MAX; j++) 
            for (int p = 0; p < TEST_MAX; p++)
                for (int q = 0; q < TEST_MAX; q++)
                    UnitTest(MAX, MAX, pair<int, int>(i, j), pair<int, int>(p, q));

    return 0;
}
