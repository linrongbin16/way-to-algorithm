#include "DancingLink.h"
#include <cstring>
#include <vector>

// up[i] down[i] left[i] right[i]
//分别为节点i的上 下 左 右的邻节点
int up[MAX], down[MAX], left[MAX], right[MAX];
// row[i] col[i] 为节点i的行号和列号
int row[MAX], col[MAX];

static void BuildLink(int s[MAX][MAX], int n, int m) {
  std::memset(up, 0, MAX * sizeof(int));
  std::memset(down, 0, MAX * sizeof(int));
  std::memset(left, 0, MAX * sizeof(int));
  std::memset(right, 0, MAX * sizeof(int));
  std::memset(row, 0, MAX * sizeof(int));
  std::memset(col, 0, MAX * sizeof(int));

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j])
        s[i][j] += n;

  /* 0为头节点head */
  for (int i = 0; i <= n; i++) {
    up[i] = i;
    down[i] = i;
    left[i] = (i - 1 >= 0) ? (i - 1) : n;
    right[i] = (i + 1 <= n) ? (i + 1) : 0;
    row[i] = 0;
    col[i] = i;
  }

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      int index = s[i][j];
      int p;
      if (!index)
        continue;
      row[index] = i;
      col[index] = j;
      for (p = i + 1; p <= m; p++)
        if (s[p][j]) {
          down[index] = s[p][j];
          up[s[p][j]] = index;
          break;
        }
      if (p == m + 1) {
        down[index] = j;
        up[j] = index;
      }
      for (p = i - 1; p >= 0; p--)
        if (s[p][j]) {
          up[index] = s[p][j];
          down[s[p][j]] = index;
          break;
        }
      if (p == -1) {
        up[index] = j;
        down[j] = index;
      }
      for (p = j + 1;; p = p + 1 > n ? 1 : p + 1)
        if (s[i][p]) {
          right[index] = s[i][p];
          left[s[i][p]] = index;
          break;
        }
      for (p = j - 1;; p = p - 1 <= 0 ? n : p - 1)
        if (s[i][p]) {
          left[index] = s[i][p];
          right[s[i][p]] = index;
          break;
        }
    }
}

static void RemoveNode(int u) {
  /* 删除节点u */
  left[right[u]] = left[u];
  right[left[u]] = right[u];

  /* 对于节点u所在列的每个节点 */
  for (int p1 = down[u]; p1 != u; p1 = down[p1]) {
    /* 对于每个节点所在的子集/行 */
    for (int p2 = right[p1]; p2 != p1; p2 = right[p2]) {
      up[down[p2]] = up[p2];
      down[up[p2]] = down[p2];
    }
  }
}

static void ResumeNode(int u) {
  /* 恢复节点u */
  left[right[u]] = u;
  right[left[u]] = u;

  /* 对于节点u所在列的每个节点 */
  for (int p1 = up[u]; p1 != u; p1 = up[p1]) {
    /* 对于每个节点所在的子集/行 */
    for (int p2 = right[p1]; p2 != p1; p2 = right[p2]) {
      up[down[p2]] = p2;
      down[up[p2]] = p2;
    }
  }
}

static bool Dance(int r, std::vector<int> &cover) {
  /* 0节点即为head节点 */
  /* 选择head节点右边的第1个节点u */
  int u = right[0];
  if (u == 0)
    return true;

  /* 删除节点u */
  /* 以及u所在列上的每个子集/每行的所有节点 */
  RemoveNode(u);
  for (int p1 = down[u]; p1 != u; p1 = down[p1]) {
    /* 尝试选择u这列中的节点p1 */
    cover[row[p1]] = 1;
    /* 删除节点p1所在的子集/行 */
    /* 删除节点p1所在列的每个节点所在的子集/行的所有节点 */
    for (int p2 = right[p1]; p2 != p1; p2 = right[p2])
      RemoveNode(col[p2]);

    /* 继续下1列 若矩阵为空时可以将所有成员都覆盖 则获得精确覆盖方案 */
    if (Dance(r + 1, cover))
      return true;
    /* 若矩阵为空时没有获得精确覆盖方案 说明p1选择失败 恢复所有被删掉的节点
     * 并继续尝试u这列中的下一个节点 */
    cover[row[p1]] = 0;

    for (int p2 = left[p1]; p2 != p1; p2 = left[p2])
      ResumeNode(col[p2]);
  }
  ResumeNode(u);
  return false;
}

std::vector<int> DancingLink(int n, int m, int s[MAX][MAX]) {
  std::vector<int> cover(m);
  std::memset(cover.data(), 0, sizeof(int) * m);
  BuildLink(s, n, m);
  Dance(1, cover);
  return cover;
}

