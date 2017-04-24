#ifndef DANCING_LINK_HPP
#define DANCING_LINK_HPP 1

#include <cstring>
#ifndef MAX
#define MAX 64
#endif

/* up_node[i]为节点i上方的邻节点 down_node/left_node/right_node对应分别为下方/左方/右方的邻节点 */
int up_node[MAX], down_node[MAX], left_node[MAX], right_node[MAX];
/* row[i] column[i]为节点i的行号和列号 */
int row[MAX], column[MAX];

void MakeLink(int n, int m, int subset[MAX][MAX])
{
    /* 初始化矩阵 */
    memset(up_node, 0, MAX * sizeof(int));
    memset(down_node, 0, MAX * sizeof(int));
    memset(left_node, 0, MAX * sizeof(int));
    memset(right_node, 0, MAX * sizeof(int));
    memset(row, 0, MAX * sizeof(int));
    memset(column, 0, MAX * sizeof(int));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (subset[i][j])
                subset[i][j] += n;
    /* 0为头节点head */
    for (int i = 0; i <= n; i++) {
        up_node[i] = i;
        down_node[i] = i;
        left_node[i] = i-1>=0 ? i-1 : n;
        right_node[i] = i+1<=n ? i+1 : 0;
        row[i] = 0;
        column[i] = i;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            int index = subset[i][j];
            int p;
            if (!index)
                continue;
            row[index] = i;
            column[index] = j;
            for (p = i + 1; p <= m; p++)
                if (subset[p][j]) {
                    down_node[index] = subset[p][j];
                    up_node[ subset[p][j] ] = index;
                    break;
                }
            if (p == m+1) {
                down_node[index] = j;
                up_node[j] = index;
            }
            for (p = i - 1; p >= 0; p--)
                if (subset[p][j]) {
                    up_node[index] = subset[p][j];
                    down_node[ subset[p][j] ] = index;
                    break;
                }
            if (p == -1) {
                up_node[index] = j;
                down_node[j] = index;
            }
            for (p = j + 1; ; p = p+1>n ? 1 : p + 1)
                if (subset[i][p]) {
                    right_node[index] = subset[i][p];
                    left_node[ subset[i][p] ] = index;
                    break;
                }
            for (p = j - 1; ; p = p-1<=0 ? n : p - 1)
                if (subset[i][p]) {
                    left_node[index] = subset[i][p];
                    right_node[ subset[i][p] ] = index;
                    break;
                }
        }
}
void RemoveNode(int u)
{
    /* 删除节点u */
    left_node[right_node[u]] = left_node[u];
    right_node[left_node[u]] = right_node[u];

    /* 对于节点u所在列的每个节点 */
    for (int p1 = down_node[u]; p1 != u; p1 = down_node[p1]) {
        /* 对于每个节点所在的子集/行 */
        for (int p2 = right_node[p1]; p2 != p1; p2 = right_node[p2]) {
            up_node[down_node[p2]] = up_node[p2];
            down_node[up_node[p2]] = down_node[p2];
        }
    }
}
void ResumeNode(int u)
{
    /* 恢复节点u */
    left_node[right_node[u]] = u;
    right_node[left_node[u]] = u;

    /* 对于节点u所在列的每个节点 */
    for (int p1 = up_node[u]; p1 != u; p1 = up_node[p1]) {
        /* 对于每个节点所在的子集/行 */
        for (int p2 = right_node[p1]; p2 != p1; p2 = right_node[p2]) {
            up_node[down_node[p2]] = p2;
            down_node[up_node[p2]] = p2;
        }
    }
}

bool Dance(int r, int cover[MAX])
{
    /* 0节点即为head节点 */
    /* 选择head节点右边的第1个节点u */
    int u = right_node[0];
    if (u == 0)
        return true;

    /* 删除节点u */
    /* 以及u所在列上的每个子集/每行的所有节点 */
    RemoveNode(u);

    for (int p1 = down_node[u]; p1 != u; p1 = down_node[p1]) {
        /* 尝试选择u这列中的节点p1 */
        cover[ row[p1] ] = 1;
        /* 删除节点p1所在的子集/行 */
        /* 删除节点p1所在列的每个节点所在的子集/行的所有节点 */
        for (int p2 = right_node[p1]; p2 != p1; p2 = right_node[p2])
            RemoveNode(column[p2]);

        /* 继续下1列 若矩阵为空时可以将所有成员都覆盖 则获得精确覆盖方案 */
        if (Dance(r + 1, cover))
            return true;

        /* 若矩阵为空时没有获得精确覆盖方案 说明p1选择失败 恢复所有被删掉的节点 并继续尝试u这列中的下一个节点 */
        cover[ row[p1] ] = 0;
        for (int p2 = left_node[p1]; p2 != p1; p2 = left_node[p2])
            ResumeNode(column[p2]);
    }

    /* 没有精确覆盖 恢复节点u 以及u所在列的每个节点所在的子集/行的所有节点*/
    ResumeNode(u);
    return false;
}

bool DancingLink(int n, int m, int subset[MAX][MAX], int cover[MAX])
{
    /* 集合s有n个成员[1,n] 子集subset有m个[1,m] */
    /* subset[i][j]=7 表示子集j包含成员i 节点的下标号为7 */
    /* subset[i][j]=0 表示子集j不包含成员i */
    /* 存在精确覆盖返回true并将所选的子集结果存储在cover数组中 不存在则返回false */
    memset(cover, 0, MAX * sizeof(int));
    MakeLink(n, m, subset);
    return Dance(1, cover);
}

#endif
