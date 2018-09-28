#include "SegmentTree.h"
#include <algorithm>
#include <assert.h>
#ifndef MAX
#define MAX 64
#endif

static int SegmentTreeInitRec(SegmentTree *t, int root, int s[MAX], int start,
                              int end) {
  if (start == end) {
    t->left[root] = start;
    t->right[root] = end;
    t->sum[root] = s[start];
    return t->sum[root];
  }

  int mid = (start + end) / 2;
  int left_sum = SegmentTreeInitRec(t, LEFT_CHILD(root), s, start, mid);
  int right_sum = SegmentTreeInitRec(t, RIGHT_CHILD(root), s, mid + 1, end);
  t->left[root] = start;
  t->right[root] = end;
  t->sum[root] = left_sum + right_sum;
  return t->sum[root];
}

static void SegmentTreeAddRec(SegmentTree *t, int root, int index, int v) {
  if (t->left[root] > index || t->right[root] < index) {
    return;
  }

  assert(t->left[root] <= index);
  assert(t->right[root] >= index);
  t->sum[root] += v;

  if (t->left[root] == t->right[root]) {
    return;
  }
  SegmentTreeAddRec(t, LEFT_CHILD(root), index, v);
  SegmentTreeAddRec(t, RIGHT_CHILD(root), index, v);
}

static int SegmentTreeQueryRec(SegmentTree *t, int root, int start, int end) {
  int mid = (t->left[root] + t->right[root]) / 2;
  if (t->left[root] >= start && t->right[root] <= end) {
    return t->sum[root];
  } else if (end <= mid) {
    return SegmentTreeQueryRec(t, LEFT_CHILD(root), start, end);
  } else if (start >= mid + 1) {
    return SegmentTreeQueryRec(t, RIGHT_CHILD(root), start, end);
  } else {
    return SegmentTreeQueryRec(t, LEFT_CHILD(root), start, mid) +
           SegmentTreeQueryRec(t, RIGHT_CHILD(root), mid + 1, end);
  }
}

SegmentTree *SegmentTreeNew(int s[MAX], int start, int end) {
  SegmentTree *t = new SegmentTree();
  if (!t) {
    return NULL;
  }
  SegmentTreeInitRec(t, 0, s, start, end);
  return t;
}

void SegmentTreeFree(SegmentTree *t) { delete t; }

void SegmentTreeAdd(SegmentTree *t, int index, int value) {
  SegmentTreeAddRec(t, 0, index, value);
}

int SegmentTreeQuery(SegmentTree *t, int start, int end) {
  return SegmentTreeQueryRec(t, 0, start, end);
}

