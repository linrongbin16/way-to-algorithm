#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP 1

#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 128
#endif

void DFSImpl(int g[MAX][MAX], int n, int p, int visited[MAX], vector<int> & sequence)
{
    visited[p] = 1;
    sequence.push_back(p);
    for (int i = 1; i < n; i++)
		if(i != p and g[p][i] and not visited[i])
			DFSImpl(g, n, i, visited, sequence);
}

auto DepthFirstSearch(int g[MAX][MAX], int n, int beg) -> vector<int>
{
    int visited[MAX];
    vector<int> sequence;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++ i)
        if (not visited[i])
            DFSImpl(g, n, i, visited, sequence);

    return sequence;
}


#endif
