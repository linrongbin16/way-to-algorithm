#include "SegmentTree.h"
#include <cassert>

#define left_child(x) (2 * (x) + 1)
#define right_child(x) (2 * (x) + 2)
#define father(x) (((x)-1) / 2)

static int SegmentTreeNewRec(SegNode *t, int s[MAX], int root, int beg,
                             int end) {
  if (end == beg + 1) {
    t->left[root] = beg;
    t->right[root] = end;
    t->sum[root] = s[beg];
    return t->sum[root];
  }

  int mid = (beg + end) / 2;
  t->left[root] = beg;
  t->right[root] = end;
  t->sum[root] = SegmentTreeNewRec(t, s, left_child(root), beg, mid) +
                 SegmentTreeNewRec(t, s, right_child(root), mid, end);
  return t->sum[root];
}

static void SegmentTreeAddRec(SegNode *t, int root, int i, int v) {
  if (t->left[root] > i || t->right[root] <= i) {
    return;
  }

  assert(t->left[root] <= i);
  assert(t->right[root] > i);
  t->sum[root] += v;
  SegmentTreeAddRec(t, left_child(root), i, v);
  SegmentTreeAddRec(t, right_child(root), i, v);
}

static int SegmentTreeSumRec(SegNode *t, int root, int beg, int end) {
  int mid = (t->left[root] + t->right[root]) / 2;
  if (t->left[root] == beg && t->right[root] == end) {
    return t->sum[root];
  } else if (end <= mid) {
    return SegmentTreeSumRec(t, left_child(root), beg, end);
  } else if (beg >= mid) {
    return SegmentTreeSumRec(t, right_child(root), beg, end);
  } else {
    return SegmentTreeSumRec(t, left_child(root), beg, mid) +
           SegmentTreeSumRec(t, right_child(root), mid, end);
  }
}

SegNode *SegmentTreeNew(int s[MAX], int beg, int end) {
  SegNode *t = new SegNode();
  SegmentTreeNewRec(t, s, 0, beg, end);
  return t;
}

void SegmentTreeFree(SegNode *t) { delete t; }

void SegmentTreeAdd(SegNode *t, int i, int value) {
  SegmentTreeAddRec(t, 0, i, value);
}

int SegmentTreeSum(SegNode *t, int beg, int end) {
  return SegmentTreeSumRec(t, 0, beg, end);
}

