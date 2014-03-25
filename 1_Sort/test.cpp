//test

#include "general_head.h"
extern void insert_sort(int *s, int beg, int end);
extern void bubble_sort(int *s, int beg, int end);
extern void quick_sort(int *s, int beg, int end);
extern bool binary_search(int *s, int x, int beg, int end, int &idx);
int main()
{
	void (*p[3])(int*, int, int);
	p[0] = insert_sort, p[1] = bubble_sort, p[2] = quick_sort;
	for(int i = 0; i < 3; ++ i){
		int s[6] = {3, 4, 9, -1, 0, 4};
		int beg = 0, end = 6;
		p[i](s, beg, end);
		cout << "after seach: " << endl;
		for(int j = 0; j < 6; ++ j)
			cout << s[j] << ' ';
		cout << endl;
		int idx, x = 3, y = 2;
		if(binary_search(s, x, beg, end, idx))
			cout << "binary search: " << x << " ,yes: " << idx << endl; 
		if(!binary_search(s, y, beg, end, idx))
			cout << "binary search: " << y << " ,no: " << idx << endl;
	}
	return(0);
}






