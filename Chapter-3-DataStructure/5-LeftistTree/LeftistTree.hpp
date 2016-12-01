#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <assert.h>
#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

/* 用数组来代替二叉树的数据结构 */
/* 节点下标为x的节点 其左右孩子节点的下标为 LEFT_CHILD(x) RIGHT_CHILD(x) 父节点的下标为 FATHER(x) */
#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x) - 1) / 2)

struct LeftistTree {
    /* 节点i的距离为distance[i] */
    int distance[MAX * 3];
};

/* 将数组s[start, end]初始化为二叉树 根节点root为0 */
int LeftistTreeInitRec(LeftistTree *t, int root, int s[MAX], int start, int end)
{
    if (start == end) {
        t->distance[root] = s[start];
        return dist[root];
    }

    int mid = (start + end) / 2;
    int dist = LeftistTreeInit( LEFT_CHILD(root), s, start, mid );
    int dist = LeftistTreeInit( RIGHT_CHILD(root), s, mid + 1, end );
    dist[root] = left_sum + right_sum;
    return dist[root];
}

/* 数组s[index]加v */
void LeftistTreeAdd(int root, int index, int v)
{
    if (left_node[root] > index || right_node[root] < index) {
        return;
    }

    assert( left_node[root] <= index );
    assert( right_node[root] >= index );
    sum[root] += v;

    if (left_node[root] == right_node[root]) {
        return;
    }
    LeftistTreeAdd( LEFT_CHILD(root), index, v );
    LeftistTreeAdd( RIGHT_CHILD(root), index, v );
}

/* 查询数组s[start, end]范围的和 */
int LeftistTreeQuery(int root, int start, int end)
{
    int mid = (left_node[root] + right_node[root]) / 2;
    if (left_node[root] >= start && right_node[root] <= end) {
        return sum[root];
    } else if (end <= mid) {
        return LeftistTreeQuery( LEFT_CHILD(root), start, end );
    } else if (start >= mid + 1) {
        return LeftistTreeQuery( RIGHT_CHILD(root), start, end );
    } else { 
        return LeftistTreeQuery( LEFT_CHILD(root), start, mid) 
            + LeftistTreeQuery( RIGHT_CHILD(root), mid + 1, end);
    }
}

#endif