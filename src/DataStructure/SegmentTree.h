#pragma once
#ifndef MAX
#define MAX 1024
#endif

struct StNode {
  int left[MAX];
  int right[MAX];
  int sum[MAX];
};

// create s[beg, end)
StNode *SegmentTreeNew(int s[MAX], int beg, int end);

// free s[beg, end)
void SegmentTreeFree(StNode *t);

// modify s[i] += value
void SegmentTreeAdd(StNode *t, int i, int value);

// sum s[beg, end)
int SegmentTreeSum(StNode *t, int beg, int end);

