#include "DancingLink.h"
#include "Util.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

#define index(i, j, m) ((j) + (i) * (m))

// uplink[i],downlink[i],leftlink[i],rightlink[i]
//分别为节点i的上下左右邻节点下标
static int uplink[MAX], downlink[MAX], leftlink[MAX], rightlink[MAX];
// rowlink[i],collink[i]为节点i的行号和列号
static int rowlink[MAX], collink[MAX];
// 精确覆盖
static int chose[MAX];
// 覆盖元素
static int cover[MAX];

static void DumpGraph(int s[MAX][MAX], int n, int m) {
  std::cout << std::endl << "dump -- n: " << n << ", m: " << m << std::endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (s[i][j]) {
        int p = index(i, j, m);
        std::cout << "s[" << i << "," << j << "]:" << p
                  << ", u/d/l/r:" << uplink[p] << "/" << downlink[p] << "/"
                  << leftlink[p] << "/" << rightlink[p] << std::endl;
      }
    }
  }
}

static void BuildLink(int s[MAX][MAX], int n, int m) {
  std::memset(uplink, 0, MAX * sizeof(int));
  std::memset(downlink, 0, MAX * sizeof(int));
  std::memset(leftlink, 0, MAX * sizeof(int));
  std::memset(rightlink, 0, MAX * sizeof(int));
  std::memset(rowlink, 0, MAX * sizeof(int));
  std::memset(collink, 0, MAX * sizeof(int));
  std::memset(cover, 0, MAX * sizeof(int));
  std::memset(chose, 0, MAX * sizeof(int));

  // 初始化头节点[0,n]
  for (int i = 0; i <= m; i++) {
    assert(i >= 0);
    assert(i < MAX);
    s[0][i] = 1;
    rowlink[i] = 0;
    collink[i] = i;
    uplink[i] = i;
    downlink[i] = i;
    leftlink[i] = (i > 0) ? (i - 1) : m;
    rightlink[i] = (i < m) ? (i + 1) : 0;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!s[i][j])
        continue;

      int p = index(i, j, m);
      assert(p >= 0);
      assert(p < MAX);
      rowlink[p] = i;
      collink[p] = j;

      // 找到p下方节点
      // k:[0, n]
      for (int k = (i + 1 > n) ? 0 : i + 1;; k = (k + 1 > n) ? 0 : k + 1)
        if (s[k][j]) {
          assert(index(k, j, m) >= 0);
          assert(index(k, j, m) < MAX);
          downlink[p] = index(k, j, m);
          uplink[index(k, j, m)] = p;
          break;
        }
      // 找到p上方节点
      // k:[0, n]
      for (int k = (i - 1 < 0) ? n : i - 1;; k = (k - 1 < 0) ? n : k - 1)
        if (s[k][j]) {
          assert(index(k, j, m) >= 0);
          assert(index(k, j, m) < MAX);
          uplink[p] = index(k, j, m);
          downlink[index(k, j, m)] = p;
          break;
        }
      // 找到p右方节点
      // k:[1, m]
      for (int k = (j + 1 > m) ? 1 : j + 1;; k = (k + 1 > m) ? 1 : k + 1)
        if (s[i][k]) {
          assert(index(i, k, m) >= 0);
          assert(index(i, k, m) < MAX);
          rightlink[p] = index(i, k, m);
          leftlink[index(i, k, m)] = p;
          break;
        }
      // 找到p左方节点
      // k:[1, m]
      for (int k = (j - 1 < 1) ? m : j - 1;; k = (k - 1 < 1) ? m : k - 1)
        if (s[i][k]) {
          assert(index(i, k, m) >= 0);
          assert(index(i, k, m) < MAX);
          leftlink[p] = index(i, k, m);
          rightlink[index(i, k, m)] = p;
          break;
        }
    } // for
}

static void Remove(int i) {
  //在头节点的一行删除节点i
  leftlink[rightlink[i]] = leftlink[i];
  rightlink[leftlink[i]] = rightlink[i];
  cover[collink[i]] = 1;

  //所有包含i的子集
  for (int p = downlink[i]; p != i; p = downlink[p]) {
    //在列上删除子集上除了i的其他节点
    for (int q = rightlink[p]; q != p; q = rightlink[q]) {
      uplink[downlink[q]] = uplink[q];
      downlink[uplink[q]] = downlink[q];
    }
  }
}

static void Resume(int i) {
  //在头节点的一行恢复节点i
  leftlink[rightlink[i]] = i;
  rightlink[leftlink[i]] = i;
  cover[collink[i]] = 0;

  //所有包含i的子集
  for (int p = uplink[i]; p != i; p = uplink[p]) {
    //在列上恢复子集上除了i的其他节点
    for (int q = rightlink[p]; q != p; q = rightlink[q]) {
      uplink[downlink[q]] = q;
      downlink[uplink[q]] = q;
    }
  }
}

static bool Dance(int x, int s[MAX][MAX], int n, int m) {
  //头节点一行的所有元素都被删除
  //只剩0节点
  if (leftlink[0] == 0) {
    return true;
  }

  //已经被子集覆盖
  //不再重复操作
  if (cover[collink[x]]) {
    return Dance(x + 1, s, n, m);
  }

  Remove(index(0, x, m));
  DumpGraph(s, n, m);
  //遍历所有包含x的子集
  for (int p = downlink[index(0, x, m)]; p != index(0, x, m); p = downlink[p]) {
    //选择子集rowlink[p]
    chose[rowlink[p]] = 1;

    //删除包含子集rowlink[p]所有元素的子集
    for (int q = rightlink[p]; q != p; q = rightlink[q])
      Remove(index(0, collink[q], m));
    DumpGraph(s, n, m);

    //下一个元素x+1
    if (Dance(x + 1, s, n, m))
      return true;

    //排除子集rowlink[p]
    chose[rowlink[p]] = 0;

    //恢复链表
    for (int q = leftlink[p]; q != p; q = leftlink[q])
      Resume(index(0, collink[q], m));
    DumpGraph(s, n, m);
  }
  Resume(index(0, x, m));
  DumpGraph(s, n, m);
  return false;
}

std::pair<bool, std::vector<int>> DancingLink(int n, int m, int s[MAX][MAX]) {
  BuildLink(s, n, m);
  DumpGraph(s, n, m);
  bool dance = Dance(1, s, n, m);
  return std::make_pair(dance, BuildVector(chose, 0, n + 1));
}

