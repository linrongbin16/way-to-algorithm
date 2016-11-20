#ifndef LEFTIST_TREE_HPP
#define LEFTIST_TREE_HPP 1

#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

/* 用数组来代替二叉树的数据结构 */
/* 节点下标为x的节点 其左右孩子节点的下标为 LEFT_CHILD(x) RIGHT_CHILD(x) 父节点的下标为 FATHER(x) */
#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x) - 1) / 2)

/* 节点i代表的区域范围为[left_node[i], right_node[i]] 该区域的和为sum[i] */
int left_node[MAX * 3];
int right_node[MAX * 3];
int sum[MAX * 3];

/* 将数组s[start, end]初始化为二叉树 根节点root为0 */
int SegmentTreeInit(int root, int s[MAX], int start, int end)
{
    if (start == end) {
        left_node[root] = start;
        right_node[root] = end;
        sum[root] = s[start];
        return sum[root];
    }

    int mid = (start + end) / 2;
    int left_sum = SegmentTreeInit( LEFT_CHILD(root), s, start, mid );
    int right_sum = SegmentTreeInit( RIGHT_CHILD(root), s, mid + 1, end );
    left_node[root] = start;
    right_node[root] = end;
    sum[root] = left_sum + right_sum;
    return sum[root];
}

/* 数组s[index]加v */
void SegmentTreeAdd(int root, int index, int v)
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
    SegmentTreeAdd( LEFT_CHILD(root), index, v );
    SegmentTreeAdd( RIGHT_CHILD(root), index, v );
}

/* 查询数组s[start, end]范围的和 */
int SegmentTreeQuery(int root, int start, int end)
{
    int mid = (left_node[root] + right_node[root]) / 2;
    if (left_node[root] >= start && right_node[root] <= end) {
        return sum[root];
    } else if (end <= mid) {
        return SegmentTreeQuery( LEFT_CHILD(root), start, end );
    } else if (start >= mid + 1) {
        return SegmentTreeQuery( RIGHT_CHILD(root), start, end );
    } else { 
        return SegmentTreeQuery( LEFT_CHILD(root), start, mid) 
            + SegmentTreeQuery( RIGHT_CHILD(root), mid + 1, end);
    }
}

#endif