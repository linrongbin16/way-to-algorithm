//test
#include <stdio.h>
#include "1_insert_sort.h"
#include "2_bubble_sort.h"
#include "3_quick_sort.h"
#include "4_binary_search.h"

int main()
{
	void (*p[3])(int*, int, int);
	int i;
	p[0] = insert_sort;
	p[1] = bubble_sort;
	p[2] = quick_sort;
	for(i = 0; i < 3; ++ i){
		int s[6] = {4, 3, 9, -1, 0, 4};
		int beg = 0, end = 6;
		int j;
		p[i](s, beg, end);
		printf("after seach:\n");
		for(j = 0; j < 6; ++ j)
			printf("%d ", s[j]);
		printf("\n");
		int idx, x = 3, y = 2;
		if(binary_search(s, beg, end, x, idx))
			printf("binary search: %d, yes: %d\n", x, idx);
		else
			printf("binary search: %d, no: %d\n", x, idx);
	}
	return(0);
}
