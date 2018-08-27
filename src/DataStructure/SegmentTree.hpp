#pragma once

#include <assert.h>
#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

/* ����������������������ݽṹ */
/* �ڵ��±�Ϊx�Ľڵ� �����Һ��ӽڵ���±�Ϊ LEFT_CHILD(x) RIGHT_CHILD(x) ���ڵ���±�Ϊ
 * FATHER(x) */
#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x)-1) / 2)

struct SegmentTree {
    /* �ڵ�i���������ΧΪ[left_node[i], right_node[i]] ������ĺ�Ϊsum[i] */
    int left_node[MAX * 3];
    int right_node[MAX * 3];
    int sum[MAX * 3];
};

/* ������s[start, end]��ʼ��Ϊ������ ���ڵ�rootΪ0 */
static int SegmentTreeInitRec(SegmentTree *t, int root, int s[MAX], int start,
                              int end)
{
    if (start == end) {
        t->left_node[root] = start;
        t->right_node[root] = end;
        t->sum[root] = s[start];
        return t->sum[root];
    }

    int mid = (start + end) / 2;
    int left_sum = SegmentTreeInitRec(t, LEFT_CHILD(root), s, start, mid);
    int right_sum = SegmentTreeInitRec(t, RIGHT_CHILD(root), s, mid + 1, end);
    t->left_node[root] = start;
    t->right_node[root] = end;
    t->sum[root] = left_sum + right_sum;
    return t->sum[root];
}

SegmentTree *SegmentTreeNew(int s[MAX], int start, int end)
{
    SegmentTree *t = new SegmentTree();
    if (!t) {
        return NULL;
    }
    SegmentTreeInitRec(t, 0, s, start, end);
    return t;
}

void SegmentTreeFree(SegmentTree *t) { delete t; }

/* ����s[index]��v */
static void SegmentTreeAddRec(SegmentTree *t, int root, int index, int v)
{
    if (t->left_node[root] > index || t->right_node[root] < index) {
        return;
    }

    assert(t->left_node[root] <= index);
    assert(t->right_node[root] >= index);
    t->sum[root] += v;

    if (t->left_node[root] == t->right_node[root]) {
        return;
    }
    SegmentTreeAddRec(t, LEFT_CHILD(root), index, v);
    SegmentTreeAddRec(t, RIGHT_CHILD(root), index, v);
}

void SegmentTreeAdd(SegmentTree *t, int index, int value)
{
    SegmentTreeAddRec(t, 0, index, value);
}

/* ��ѯ����s[start, end]��Χ�ĺ� */
int SegmentTreeQueryRec(SegmentTree *t, int root, int start, int end)
{
    int mid = (t->left_node[root] + t->right_node[root]) / 2;
    if (t->left_node[root] >= start && t->right_node[root] <= end) {
        return t->sum[root];
    }
    else if (end <= mid) {
        return SegmentTreeQueryRec(t, LEFT_CHILD(root), start, end);
    }
    else if (start >= mid + 1) {
        return SegmentTreeQueryRec(t, RIGHT_CHILD(root), start, end);
    }
    else {
        return SegmentTreeQueryRec(t, LEFT_CHILD(root), start, mid) +
               SegmentTreeQueryRec(t, RIGHT_CHILD(root), mid + 1, end);
    }
}

int SegmentTreeQuery(SegmentTree *t, int start, int end)
{
    return SegmentTreeQueryRec(t, 0, start, end);
}
