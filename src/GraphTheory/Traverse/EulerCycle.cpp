#include "EulerCycle.h"
#include <cassert>
#include <stack>

static bool HasEulerCycle(int g[MAX][MAX], int n) {
  for (int i = 0; i < n; i++) {
    int degree = 0;
    for (int j = 0; j < n; j++) {
      if (g[i][j] > 0) {
        degree++;
      }
    }
    if (degree % 2 == 1) {
      return false;
    }
  }
  return true;
}

static int MaxDegree(int g[MAX][MAX], int *degree, int beg) {
  int d_max(0), index(-1);
  for (int i = 0; i < g.g_cnt; ++i) {
    if (i == beg)
      continue;
    //在beg相邻节点中找出最大度数节点
    if (g.g_m[beg][i] and d_max < degree[i])
      d_max = degree[i], index = i;
  }
  return (index);
}

static void Dfs(int g[MAX][MAX], int *degree, int beg, std::stack<int> &path) {
  path.push(beg);
  //找出beg相邻节点中度数最大的节点 对他进行下一次dfs
  int d_max = max_degree(g, degree, beg);
  //终止递归条件 若beg没有邻节点则递归搜索结束
  if (d_max == -1)
    return;

  //每次从当前节点向外找一条新的边
  //并将当前走过的路删除
  g.g_m[beg][d_max] = 0;
  g.g_m[d_max][beg] = 0;
  //当前节点和下一个节点的度数也减1
  --degree[beg];
  --degree[d_max];
  dfs_loop(g, degree, d_max, path);
}

std::pair<bool, std::vector<int>> EulerCycle(int g[MAX][MAX], int n) {
  if (!HasEulerCycle(g, n)) {
    return std::make_pair(false, std::vector<int>());
  }
}

bool loop_exist(int *degree, int n);
void dfs_loop(graph_matrix g, int *degree, int beg, stack<int> &path);
int max_degree(graph_matrix g, int *degree, int beg);

bool euler_loop(
    graph_matrix g,
    stack<int>
        &path) { //邻接矩阵中g.g_m[i][j]的值为0或1
                 //指代从节点i到j是否存在一条有向边 判断是否存在欧拉回路
                 //若存在则返回栈path 栈path中从底至顶
                 //逆序存储着欧拉回路的所有顶点下标号
                 //依次对path出栈即可得到欧拉回路
                 //在无向图中不用考虑这个逆序
                 //因为欧拉回路或欧拉路在无向边中可以两个方向走 path初始为空
  int degree[MAX];
  memset(degree, 0, MAX * sizeof(int));
  // degree[i]指代节点i的度数
  for (int i = 0; i < g.g_cnt; ++i)
    for (int j = 0; j < g.g_cnt; ++j)
      degree[i] += g.g_m[i][j];
  if (loop_exist((int *)degree, g.g_cnt)) {
    //判断无向连通图G中是否存在欧拉回路
    dfs_loop(g, degree, 0, path);
    return (true);
  } else
    return (false);
}
bool loop_exist(int *degree, int n) { //判断无向连通图G中是否存在欧拉回路
  for (int i = 0; i < n; ++i)
    //若存在度数为奇数的节点则不存在欧拉回路
    if (degree[i] % 2 == 1)
      return (false);
  return (true);
}
void dfs_loop(graph_matrix g, int *degree, int beg,
              stack<int> &path) { //返回的path中从底至顶
                                  //逆序存储着欧拉回路的所有顶点下标号
                                  //对path出栈即可得到欧拉回路 path初始为空
  path.push(beg);
  //找出beg相邻节点中度数最大的节点 对他进行下一次dfs
  int d_max = max_degree(g, degree, beg);
  //终止递归条件 若beg没有邻节点则递归搜索结束
  if (d_max == -1)
    return;

  //每次从当前节点向外找一条新的边
  //并将当前走过的路删除
  g.g_m[beg][d_max] = 0;
  g.g_m[d_max][beg] = 0;
  //当前节点和下一个节点的度数也减1
  --degree[beg];
  --degree[d_max];
  dfs_loop(g, degree, d_max, path);
}
int max_degree(graph_matrix g, int *degree, int beg) {
  int d_max(0), index(-1);
  for (int i = 0; i < g.g_cnt; ++i) {
    if (i == beg)
      continue;
    //在beg相邻节点中找出最大度数节点
    if (g.g_m[beg][i] and d_max < degree[i])
      d_max = degree[i], index = i;
  }
  return (index);
}

