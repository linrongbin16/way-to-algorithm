#pragma once

#include <algorithm>
#include <assert.h>
#ifndef MAX
#define MAX 64
#endif

#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x)-1) / 2)

struct SegNode {
  int left[MAX * 3];
  int right[MAX * 3];
  int sum[MAX * 3];
};

// create segment tree
SegNode *SegmentTreeNew(int s[MAX], int start, int end);

// free segment tree
void SegmentTreeFree(SegNode *t);

// add value to segment tree
void SegmentTreeAdd(SegNode *t, int index, int value);

// query segment tree
int SegmentTreeQuery(SegNode *t, int start, int end);

