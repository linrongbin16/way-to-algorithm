#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H 1

#ifndef MAX
#define MAX 60
#endif
#include <algorithm>
using namespace std;


void BubbleSort(int s[MAX], int beg, int end)
{
    for (int i = end-1; i >= beg; --i)
        for (int j = beg; j < i; ++j)
            if (s[j] > s[j+1])
                swap(s[j], s[j+1]);
}


#endif
