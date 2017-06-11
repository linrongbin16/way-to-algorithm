#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP 1

#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 128
#endif


auto BreadthFirstSearch(int g[MAX][MAX], int n, int beg) -> vector<int>
{
    vector<int> sequence;
    queue<int> que;
    int visited[MAX];

    memset(visited, 0, sizeof(visited));
    que.push(beg);
    visited[beg] = 1;

    while(not que.empty()) {
        int e = que.front();
        que.pop();
        sequence.push_back(e);

        // for each node adjacent to e
        for(int i = 0; i < n; i++)
            if(i != e and g[e][i] and not visited[i]) {
                que.push(i);
                visited[i] = 1;
            }
    }

    return sequence;
}

#endif
