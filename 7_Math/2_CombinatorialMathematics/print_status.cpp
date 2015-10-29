#include "general_head.h"
#include "com_local.h"

void print_status(int *s, int beg, int end)
{//[beg, end)是左闭右开区间，序列s下标从beg到end-1
	for(int i = beg; i < end; ++ i)
		cout << s[i] << ' ';
	cout << endl;
}
