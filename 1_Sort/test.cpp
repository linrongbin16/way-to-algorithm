//test
#include <stdio.h>
#include "1_insert_sort.h"
#include "2_bubble_sort.h"
#include "3_quick_sort.h"
#include "4_binary_search.h"
//#include "5_merge_sort.h"

int main()
{
    void (*p[4])(int*, int, int);
    int i;
    p[0] = insert_sort;
    p[1] = bubble_sort;
    p[2] = quick_sort1;
    p[3] = quick_sort2;
    //p[3] = division;
    for(i = 0; i < 4; ++ i)
    {
        int s[30] = {4, 3, 9, -1, 0, 4, 123, 25, -923, 8234, 
            2384, 34, 235, 17, 34, 35, 6, 3, 95, 3, 
            46, 4, 10, -4, -935, 54, 245, 23, 18, 19};
        int beg = 0, end = 30;
        int j;
        p[i](s, beg, end);
        printf("after seach:\n");
        for(j = 0; j < 30; ++ j)
            printf("%d ", s[j]);
        printf("\n");
        int idx, x = 123;
        if(binary_search(s, beg, end, x, idx))
            printf("binary search: %d, yes: %d\n", x, idx);
        else
            printf("binary search: %d, no: %d\n", x, idx);
    }
    return(0);
}
