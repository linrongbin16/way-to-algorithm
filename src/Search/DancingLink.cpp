#include "DancingLink.h"
#include "Util.h"
#include <cstring>
#include <iostream>
#include <vector>

#define index(i, j, n, m) ((j) + (i) * (m))

// up[i],down[i],left[i],right[i]
//分别为节点i的上下左右邻节点下标
static int up[MAX], down[MAX], left[MAX], right[MAX];
// row[i],col[i]为节点i的行号和列号
static int row[MAX], col[MAX];
// 精确覆盖
static int cover[MAX];

static void DumpGraph(int s[MAX][MAX], int n, int m) {
  std::cout << std::endl << "dump -- n: " << n << ", m: " << m << std::endl;
  std::cout << "s[i][j]:p,row,col,up,down,left,right -- " << std::endl;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int p = index(i, j, n, m);
      std::cout << "s[" << i << "," << j << "]: (" << p << "," << row[p] << ","
                << col[p] << "," << up[p] << "," << down[p] << "," << left[p]
                << "," << right[p] << ") ";
    }
    std::cout << std::endl;
  }
}

static void BuildLink(int s[MAX][MAX], int n, int m) {
  // 初始化节点下标
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << "s[" << i << "," << j << "]: " << index(i, j, n, m) << " ";
    }
    std::cout << std::endl;
  }

  // 头节点[0,n]
  for (int i = 0; i <= m; i++) {
    row[i] = 0;
    col[i] = i;
    up[i] = i;
    down[i] = i;
    left[i] = (i > 0) ? (i - 1) : m;
    right[i] = (i < m) ? (i + 1) : 0;
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int p = index(i, j, n, m);
      if (!p)
        continue;
      row[p] = i;
      col[p] = j;

      // 找到p下方节点
      for (int k = i + 1;; (k < n) ? (k++) : (k = 0))
        if (s[k][j]) {
          down[p] = index(k, j, n, m);
          up[index(k, j, n, m)] = p;
          break;
        }
      // 找到p上方节点
      for (int k = i - 1;; (k > 1) ? (k--) : (k = n))
        if (s[k][j]) {
          up[p] = index(k, j, n, m);
          down[index(k, j, n, m)] = p;
          break;
        }
      // 找到p右方节点
      for (int k = j + 1;; (k < m) ? (k++) : (k = 1))
        if (s[i][k]) {
          right[p] = index(i, k, n, m);
          left[index(i, k, n, m)] = p;
          break;
        }
      // 找到p左方节点
      for (int k = j - 1;; (k > 1) ? (k--) : (k = m))
        if (s[i][k]) {
          left[p] = index(i, k, n, m);
          right[index(i, k, n, m)] = p;
          break;
        }
    } // for
}

static void Remove(int x) {
  //在头节点的一行删除节点x
  left[right[x]] = left[x];
  right[left[x]] = right[x];

  //所有包含x的子集
  for (int p = down[x]; p != x; p = down[p]) {
    //在列上删除子集上除了x的其他节点
    for (int q = right[p]; q != p; q = right[q]) {
      up[down[q]] = up[q];
      down[up[q]] = down[q];
    }
  }
}

static void Resume(int x) {
  //在头节点的一行恢复节点x
  left[right[x]] = x;
  right[left[x]] = x;

  //所有包含x的子集
  for (int p = up[x]; p != x; p = up[p]) {
    //在列上恢复子集上除了x的其他节点
    for (int q = right[p]; q != p; q = right[q]) {
      up[down[q]] = q;
      down[up[q]] = q;
    }
  }
}

static bool Dance(int x, int s[MAX][MAX], int n, int m) {
  //头节点一行的所有元素都被删除
  //只剩0节点
  if (left[0] == 0) {
    return true;
  }

  Remove(x);
  //遍历所有包含x的子集
  for (int p = down[x]; p != x; p = down[p]) {
    //选择子集row[p]
    cover[row[p]] = 1;
    std::cout << "row[" << p << "]:" << row[p] << ", cover[" << row[p]
              << "]:" << cover[row[p]] << std::endl;

    //删除包含子集row[p]所有元素的子集
    for (int q = p; q != p; q = right[q])
      Remove(col[q]);

    //下一个元素x+1
    if (Dance(x + 1, s, n, m))
      return true;

    //排除子集row[p]
    cover[row[p]] = 0;
    std::cout << "row[" << p << "]:" << row[p] << ", cover[" << row[p]
              << "]:" << cover[row[p]] << std::endl;

    //恢复链表
    for (int q = left[p]; q != p; q = left[q])
      Resume(col[q]);
  }
  Resume(x);
  return false;
}

std::pair<bool, std::vector<int>> DancingLink(int n, int m, int s[MAX][MAX]) {
  std::memset(up, 0, MAX * sizeof(int));
  std::memset(down, 0, MAX * sizeof(int));
  std::memset(left, 0, MAX * sizeof(int));
  std::memset(right, 0, MAX * sizeof(int));
  std::memset(row, 0, MAX * sizeof(int));
  std::memset(col, 0, MAX * sizeof(int));
  std::memset(cover, 0, MAX * sizeof(int));

  BuildLink(s, n, m);
  DumpGraph(s, n, m);
  bool dance = Dance(1, s, n, m);
  return std::make_pair(dance, BuildVector(cover, 0, m + 1));
}

