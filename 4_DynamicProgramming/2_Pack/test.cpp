//test

#include "general_head.h"
#include "pack.h"
extern int _01_pack1(object *t, int n, int w);
extern int _01_pack2(object *t, int n, int w);
extern int _01_pack_path(object *t, int n, int w, bool *choose);
extern int complete_pack(object *t, int n, int w);
extern int multiple_pack(object *t, int n, int w);
extern int two_dimension_pack(object *t, int n, int w1, int w2);
extern int packet_pack(packet_object t, int w);
int main()
{
	object *t = new object[25];
	int n = 24;
	t[1].o_value = 5, t[1].o_weigh = 4, t[1].o_weigh2 = 11, t[1].o_count = 5;
	t[2].o_value = 12, t[2].o_weigh = 21, t[2].o_weigh2 = 13, t[2].o_count = 2;
	t[3].o_value = 4, t[3].o_weigh = 13, t[3].o_weigh2 = 7, t[3].o_count = 5;
	t[4].o_value = 7, t[4].o_weigh = 15, t[4].o_weigh2 = 12, t[4].o_count = 6;
	t[5].o_value = 1, t[5].o_weigh = 3, t[5].o_weigh2 = 6, t[5].o_count = 6;
	t[6].o_value = 9, t[6].o_weigh = 13, t[6].o_weigh2 = 7, t[6].o_count = 9;
	t[7].o_value = 12, t[7].o_weigh = 7, t[7].o_weigh2 = 9, t[7].o_count = 10;
	t[8].o_value = 3, t[8].o_weigh = 9, t[8].o_weigh2 = 10, t[8].o_count = 3;
	t[9].o_value = 9, t[9].o_weigh = 10, t[9].o_weigh2 = 3, t[9].o_count = 6;
	t[10].o_value = 3, t[10].o_weigh = 17, t[10].o_weigh2 = 4, t[10].o_count = 5;
	t[11].o_value = 7, t[11].o_weigh = 13, t[11].o_weigh2 = 2, t[11].o_count = 3;
	t[12].o_value = 11, t[12].o_weigh = 19, t[12].o_weigh2 = 1, t[12].o_count = 1;
	t[13].o_value = 15, t[13].o_weigh = 8, t[13].o_weigh2 = 5, t[13].o_count = 1;
	t[14].o_value = 17, t[14].o_weigh = 7, t[14].o_weigh2 = 4, t[14].o_count = 2;
	t[15].o_value = 3, t[15].o_weigh = 4, t[15].o_weigh2 = 9, t[15].o_count = 7;
	t[16].o_value = 10, t[16].o_weigh = 3, t[16].o_weigh2 = 8, t[16].o_count = 4;
	t[17].o_value = 5, t[17].o_weigh = 11, t[17].o_weigh2 = 15, t[17].o_count = 9;
	t[18].o_value = 6, t[18].o_weigh = 7, t[18].o_weigh2 = 14, t[18].o_count = 5;
	t[19].o_value = 9, t[19].o_weigh = 20, t[19].o_weigh2 = 2, t[19].o_count = 4;
	t[20].o_value = 8, t[20].o_weigh = 22, t[20].o_weigh2 = 5, t[20].o_count = 7;
	t[21].o_value = 13, t[21].o_weigh = 16, t[21].o_weigh2 = 8, t[21].o_count = 8;
	t[22].o_value = 14, t[22].o_weigh = 6, t[22].o_weigh2 = 10, t[22].o_count = 3;
	t[23].o_value = 2, t[23].o_weigh = 10, t[23].o_weigh2 = 9, t[23].o_count = 3;
	t[24].o_value = 7, t[24].o_weigh = 4, t[24].o_weigh2 = 7, t[24].o_count = 10;

	cout << "01 pack: " << endl;
	cout << _01_pack1(t, n, 50) << endl;
	cout << _01_pack2(t, n, 50) << endl;
	bool choose[OMAX + 1];
	cout << "01 pack path: " << _01_pack_path(t, n, 50, choose) << endl;
	cout << "select object: ";
	for(int i = 1; i <= n; ++ i)
		if(choose[i])
			cout << i << ' ';
	cout << endl;

	cout << "complete pack: " << complete_pack(t, n, 80) << endl;
	cout << "multiple pack: " << multiple_pack(t, n, 80) << endl;
	cout << "two weight pack: " << two_dimension_pack(t, n, 50, 40) << endl;
	
	packet_object q;
	q.g_grpcnt = 5, q.g_objcnt = 4, q.g_totalcnt = 20;
	q.g[1][1] = t[1]; q.g[1][2] = t[2]; q.g[1][3] = t[3]; q.g[1][4] = t[4];
	q.g[2][1] = t[5], q.g[2][2] = t[6]; q.g[2][3] = t[7]; q.g[2][4] = t[8];
	q.g[3][1] = t[9]; q.g[3][2] = t[10]; q.g[3][3] = t[11]; q.g[3][4] = t[12];
	q.g[4][1] = t[13]; q.g[4][2] = t[14]; q.g[4][3] = t[15]; q.g[4][4] = t[16];
	q.g[5][1] = t[17]; q.g[5][2] = t[18]; q.g[5][3] = t[19]; q.g[5][4] = t[20];
	cout << "packet pack: " << packet_pack(q, 50) << endl;
	return(0);
}
