//test

#include "general_head.h"
#include "knapsack.h"
extern int _01_knapsack1(object *t, int n, int w);
extern int _01_knapsack2(object *t, int n, int w);
extern int complete_knapsack(object *t, int n, int w);
extern int multiple_knapsack(object *t, int n, int w);
extern int two_dimension_knapsack(object *t, int n, int w1, int w2);
extern int group_knapsack(group_object t, int w);
int main()
{
	object *t = new object[5];
	int n = 4;
	t[1].o_value = 5, t[1].o_weigh = 4, t[1].o_weigh2 = 1, t[1].o_count = 3;
	t[2].o_value = 2, t[2].o_weigh = 1, t[2].o_weigh2 = 3, t[2].o_count = 2;
	t[3].o_value = 4, t[3].o_weigh = 2, t[3].o_weigh2 = 4, t[3].o_count = 5;
	t[4].o_value = 7, t[4].o_weigh = 5, t[4].o_weigh2 = 3, t[4].o_count = 6;
	cout << "01 knapsack: " << endl;
	cout << _01_knapsack1(t, n, 10) << endl;
	cout << _01_knapsack2(t, n, 10) << endl;
	cout << "complete knapsack: ";
	cout << complete_knapsack(t, n, 18) << endl;
	cout << "multiple knapsack: ";
	cout << multiple_knapsack(t, n, 18) << endl;
	cout << "two weight knapsack: ";
	cout << two_dimension_knapsack(t, n, 10, 8) << endl;
	group_object q;
	q.g_grpcnt = 2, q.g_objcnt = 2, q.g_totalcnt = 4;
	q.g[1][1] = t[1], q.g[1][2] = t[2], q.g[2][1] = t[3], q.g[2][2] = t[4];
	cout << "graph knapsack: ";
	cout << group_knapsack(q, 8) << endl;
	return(0);
}



