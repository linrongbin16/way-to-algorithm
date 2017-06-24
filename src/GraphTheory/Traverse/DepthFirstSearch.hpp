#ifndef DEPTH_FIRST_SEARCH_HPP
#define DEPTH_FIRST_SEARCH_HPP 1

#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
#ifndef MAX
#define MAX 128
#endif

auto DFS(int g[MAX][MAX], int n, int begin, int visited[MAX], vector<int> & out_sequence) -> void
{
    visited[begin] = 1;
    out_sequence.push_back(begin);
    for (int i = 0; i < n; i++)
        if(i != begin and g[begin][i] and not visited[i])
            DFS(g, n, i, visited, out_sequence);
}

auto DepthFirstSearch(int g[MAX][MAX], int n) -> vector<int>
{
    int visited[MAX];
    // 将遍历到的节点加入sequence中
    vector<int> sequence;

    // DFS from i-node
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++ i)
        if (not visited[i]) {
            DFS(g, n, i, visited, sequence);
        }

    return sequence;
}


#endif
