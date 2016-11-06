#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP 1

#include <algorithm>
#ifndef MAX
#define MAX 64
#endif

int start_idx[MAX * 10];
int end_idx[MAX * 10];
int sum[MAX * 10];

#define LEFT_CHILD(x) (2 * (x) + 1)
#define RIGHT_CHILD(x) (2 * (x) + 2)
#define FATHER(x) (((x) - 1) / 2)

int SegmentTreeInit(int root, int s[MAX], int start, int end)
{
    if (start == end) {
        start_idx[root] = start;
        end_idx[root] = end;
        sum[root] = s[start];
        return sum[root];
    }

    int mid = (start + end) / 2;
    int left_sum = SegmentTreeInit( LEFT_CHILD(root), s, start, mid );
    int right_sum = SegmentTreeInit( RIGHT_CHILD(root), s, mid + 1, end );
    start_idx[root] = start;
    end_idx[root] = end;
    sum[root] = left_sum + right_sum;
    return sum[root];
}

void SegmentTreeAdd(int root, int index, int v)
{
    if (start_idx[root] <= index && end_idx[root] >= index) {
        sum[root] += v;
    }
    if (start_idx[root] > index 
        || end_idx[root] < index
        || start_idx[root] == end_idx[root]) {
        return;
    }

    SegmentTreeAdd( LEFT_CHILD(root), index, v );
    SegmentTreeAdd( RIGHT_CHILD(root), index, v );
}

int SegmentTreeQuery(int root, int start, int end)
{
    int mid = (start_idx[root] + end_idx[root]) / 2;
    if (start_idx[root] >= start && end_idx[root] <= end) {
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