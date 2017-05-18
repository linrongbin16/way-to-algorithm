#include "AStarSearch.hpp"
#include <assert.h>
using namespace std;

bool IsAdjacentNode(PuNode a, PuNode b)
{
    int diff = 0;
    int pos1, pos2;
    for (int i = 0; i < 9; i++)
        if (a.value[i] != b.value[i]) {
            diff += 1;
            if (diff == 1)
                pos1 = i;
            else
                pos2 = i;
        }
    if (diff != 2)
        return false;

    if (a.value[pos1] != 'x' && a.value[pos2] != 'x')
        return false;
    if (b.value[pos1] != 'x' && b.value[pos2] != 'x')
        return false;

    return a.value[pos1] == b.value[pos2] && a.value[pos2] == b.value[pos1];
}

void UnitTest(PuNode beg, PuNode end)
{
    vector<PuNode> path = EightFigurePuzzle(beg, end);
    assert(path.size() > 0);
    assert(path[0] == beg);
    assert(path[path.size() - 1] == end);
    for (int i = 0; i < path.size() - 1; i++) {
        assert(IsAdjacentNode(path[i], path[i + 1]));
    }
}

int main()
{
    PuNode beg, end;

    /* case 1:
    beg      end
    1 3 4    1 2 3
    8 x 5    8 x 4
    7 2 6    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "1348x5726", 9);
    memcpy(end.value, "1238x4765", 9);
    UnitTest(beg, end);

    /* case 2:
    beg      end
    2 3 1    1 2 3
    7 x 8    8 x 4
    6 5 4    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "2317x8654", 9);
    memcpy(end.value, "1238x4765", 9);
    UnitTest(beg, end);

    /* case 3:
    beg      end
    2 3 1    1 2 3
    8 x 4    8 x 4
    7 6 5    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "2318x4765", 9);
    memcpy(end.value, "1238x4765", 9);
    UnitTest(beg, end);

    /* case 4:
    beg      end
    1 2 3    2 3 1
    8 x 4    8 x 4
    7 6 5    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "1238x4765", 9);
    memcpy(end.value, "2318x4765", 9);
    UnitTest(beg, end);

    /* case 5:
    beg      end
    1 2 3    2 3 1
    8 x 4    8 x 4
    7 6 5    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "1238x4765", 9);
    memcpy(end.value, "2318x4765", 9);
    UnitTest(beg, end);

    /* case 6:
    beg      end
    2 8 3    1 2 3
    1 x 4    8 x 4
    7 6 5    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "2831x4765", 9);
    memcpy(end.value, "1238x4765", 9);
    UnitTest(beg, end);

    /* case 7:
    beg      end
    1 3 4    1 2 3
    8 x 5    8 x 4
    7 2 6    7 6 5
    */
    memset(&beg, 0, sizeof(beg));
    memset(&end, 0, sizeof(end));
    memcpy(beg.value, "1348x5726", 9);
    memcpy(end.value, "1238x4765", 9);
    UnitTest(beg, end);

    return 0;
}

