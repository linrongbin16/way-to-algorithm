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
void SegmentTreeAdd(SegNode *t, int i, int value);

// sum s[beg, end)
int SegmentTreeSum(SegNode *t, int beg, int end);

