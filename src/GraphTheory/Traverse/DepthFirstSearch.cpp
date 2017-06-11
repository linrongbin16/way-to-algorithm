#include "DepthFirstSearch.hpp"
#include <cassert>

struct Test {
    int g[MAX][MAX];
    int n;
    int beg;
    vector<int> result;
} test_cases[] = {
    {
        {
            { 0, 1, 0, 0, 1, 1 },
            { 1, 0, 1, 1, 0, 1 },
            { 0, 1, 0, 1, 0, 1 },
            { 0, 1, 2, 0, 1, 0 },
            { 1, 0, 0, 1, 0, 0 },
            { 1, 1, 1, 0, 0, 0 },
        },
        6, 0,
        { },
    },
};

int main()
{
    return 0;
}