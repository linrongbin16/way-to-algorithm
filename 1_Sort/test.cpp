//test
#include <stdio.h>
#include "1_binary_search.h"
#include "3_insert_sort.h"
#include "2_bubble_sort.h"
#include "4_quick_sort.h"
#include "5_merge_sort.h"


void search_part(void (*func)(int*, int, int), const char* msg,
        int beg, int end)
{
    int s[30] = {4, 3, 9, -1, 0, 4, 123, 25, -923, 8234, 
        2384, 34, 235, 17, 34, 35, 6, 3, 95, 3, 
        46, 4, 10, -4, -935, 54, 245, 23, 18, 19};
    int j;
    func(s, beg, end);
    printf("%s:\n", msg);
    for(j = 0; j < 30; ++ j)
        printf("%d ", s[j]);
    printf("\n");
    int idx, x = 123;
    if(binary_search(s, beg, end, x, idx))
        printf("binary search: %d, yes: %d\n", x, idx);
    else
        printf("binary search: %d, no: %d\n", x, idx);
    printf("\n\n");
}

int main()
{
    search_part(insert_sort, "insert_sort", 0, 30);
    search_part(bubble_sort, "bubble_sort", 0, 30);
    search_part(quick_sort1, "quick_sort1", 0, 29);
    search_part(quick_sort2, "quick_sort2", 0, 29);
    search_part(division, "division", 0, 29);
    return(0);
}
