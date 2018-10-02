#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct SegNode {
  int left[MAX];
  int right[MAX];
  int sum[MAX];
};

// create s[beg, end)
SegNode *SegmentTreeNew(int s[MAX], int beg, int end);

// free s[beg, end)
void SegmentTreeFree(SegNode *t);

// modify s[i] += value
void SegmentTreeModify(SegNode *t, int i, int value);

// query s[beg, end)
int SegmentTreeQuery(SegNode *t, int beg, int end);

