//test

#include "general_head.h"
#include "pack.h"
extern int _01_pack1(object *t, int n, int w);
extern int _01_pack2(object *t, int n, int w);
extern int complete_pack(object *t, int n, int w);
extern int multiple_pack(object *t, int n, int w);
extern int two_dimension_pack(object *t, int n, int w1, int w2);
extern int packet_pack(packet_object t, int w);
int main()
{
	object *t = new object[5];
	int n = 4;
	t[1].o_value = 5, t[1].o_weigh = 4, t[1].o_weigh2 = 1, t[1].o_count = 3;
	t[2].o_value = 2, t[2].o_weigh = 1, t[2].o_weigh2 = 3, t[2].o_count = 2;
	t[3].o_value = 4, t[3].o_weigh = 2, t[3].o_weigh2 = 4, t[3].o_count = 5;
	t[4].o_value = 7, t[4].o_weigh = 5, t[4].o_weigh2 = 3, t[4].o_count = 6;
	cout << "01 pack: " << endl;
	cout << _01_pack1(t, n, 10) << endl;
	cout << _01_pack2(t, n, 10) << endl;
	cout << "complete pack: ";
	cout << complete_pack(t, n, 18) << endl;
	cout << "multiple pack: ";
	cout << multiple_pack(t, n, 18) << endl;
	cout << "two weight pack: ";
	cout << two_dimension_pack(t, n, 10, 8) << endl;
	packet_object q;
	q.g_grpcnt = 2, q.g_objcnt = 2, q.g_totalcnt = 4;
	q.g[1][1] = t[1], q.g[1][2] = t[2], q.g[2][1] = t[3], q.g[2][2] = t[4];
	cout << "packet pack: ";
	cout << packet_pack(q, 8) << endl;
	return(0);
}
