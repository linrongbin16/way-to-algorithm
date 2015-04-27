//test

#include <iostream>
using std::cout;
using std::endl;
#include "1_01_pack.h"
#include "2_01_pack_path.h"
#include "3_complete_pack.h"
#include "4_multiple_pack.h"
#include "5_two_dimension_pack.h"
#include "6_packet_pack.h"
#include "7_generic_item.h"
#include "8_dependent_pack.h"
int main()
{
	_01_pack_object *t = new _01_pack_object[25];
	int n = 24;
	t[1]._value = 5, t[1]._weight = 4, t[1]._count = 5;
	t[2]._value = 12, t[2]._weight = 21, t[2]._count = 2;
	t[3]._value = 4, t[3]._weight = 13, t[3]._count = 5;
	t[4]._value = 7, t[4]._weight = 15, t[4]._count = 6;
	t[5]._value = 1, t[5]._weight = 3, t[5]._count = 6;
	t[6]._value = 9, t[6]._weight = 13, t[6]._count = 9;
	t[7]._value = 12, t[7]._weight = 7, t[7]._count = 10;
	t[8]._value = 3, t[8]._weight = 9, t[8]._count = 3;
	t[9]._value = 9, t[9]._weight = 10, t[9]._count = 6;
	t[10]._value = 3, t[10]._weight = 17, t[10]._count = 5;
	t[11]._value = 7, t[11]._weight = 13, t[11]._count = 3;
	t[12]._value = 11, t[12]._weight = 19, t[12]._count = 1;
	t[13]._value = 15, t[13]._weight = 8, t[13]._count = 1;
	t[14]._value = 17, t[14]._weight = 7, t[14]._count = 2;
	t[15]._value = 3, t[15]._weight = 4, t[15]._count = 7;
	t[16]._value = 10, t[16]._weight = 3, t[16]._count = 4;
	t[17]._value = 5, t[17]._weight = 11, t[17]._count = 9;
	t[18]._value = 6, t[18]._weight = 7,  t[18]._count = 5;
	t[19]._value = 9, t[19]._weight = 20, t[19]._count = 4;
	t[20]._value = 8, t[20]._weight = 22, t[20]._count = 7;
	t[21]._value = 13, t[21]._weight = 16, t[21]._count = 8;
	t[22]._value = 14, t[22]._weight = 6, t[22]._count = 3;
	t[23]._value = 2, t[23]._weight = 10, t[23]._count = 3;
	t[24]._value = 7, t[24]._weight = 4, t[24]._count = 10;

	cout << "01 pack: " << endl;
	cout << _01_pack1(t, n, 50) << endl;
	cout << _01_pack2(t, n, 50) << endl;
	bool choose[OBJECT_MAX + 1];
	cout << "01 pack path: " << _01_pack_path(t, n, 50, choose) << endl;
	cout << "select object: ";
	for(int i = 1; i <= n; ++ i)
		if(choose[i])
			cout << i << ' ';
	cout << endl;

	cout << "complete pack: " << complete_pack(t, n, 80) << endl;
	cout << "multiple pack: " << multiple_pack(t, n, 80) << endl;


	two_dimension_pack_object *tw = new two_dimension_pack_object[25];
	n = 24;
	tw[1]._value = 5, tw[1]._weight = 4, tw[1]._weight2 = 11, tw[1]._count = 5;
	tw[2]._value = 12, tw[2]._weight = 21, tw[2]._weight2 = 13, tw[2]._count = 2;
	tw[3]._value = 4, tw[3]._weight = 13, tw[3]._weight2 = 7, tw[3]._count = 5;
	tw[4]._value = 7, tw[4]._weight = 15, tw[4]._weight2 = 12, tw[4]._count = 6;
	tw[5]._value = 1, tw[5]._weight = 3, tw[5]._weight2 = 6, tw[5]._count = 6;
	tw[6]._value = 9, tw[6]._weight = 13, tw[6]._weight2 = 7, tw[6]._count = 9;
	tw[7]._value = 12, tw[7]._weight = 7, tw[7]._weight2 = 9, tw[7]._count = 10;
	tw[8]._value = 3, tw[8]._weight = 9, tw[8]._weight2 = 10, tw[8]._count = 3;
	tw[9]._value = 9, tw[9]._weight = 10, tw[9]._weight2 = 3, tw[9]._count = 6;
	tw[10]._value = 3, tw[10]._weight = 17, tw[10]._weight2 = 4, tw[10]._count = 5;
	tw[11]._value = 7, tw[11]._weight = 13, tw[11]._weight2 = 2, tw[11]._count = 3;
	tw[12]._value = 11, tw[12]._weight = 19, tw[12]._weight2 = 1, tw[12]._count = 1;
	tw[13]._value = 15, tw[13]._weight = 8, tw[13]._weight2 = 5, tw[13]._count = 1;
	tw[14]._value = 17, tw[14]._weight = 7, tw[14]._weight2 = 4, tw[14]._count = 2;
	tw[15]._value = 3, tw[15]._weight = 4, tw[15]._weight2 = 9, tw[15]._count = 7;
	tw[16]._value = 10, tw[16]._weight = 3, tw[16]._weight2 = 8, tw[16]._count = 4;
	tw[17]._value = 5, tw[17]._weight = 11, tw[17]._weight2 = 15, tw[17]._count = 9;
	tw[18]._value = 6, tw[18]._weight = 7, tw[18]._weight2 = 14, tw[18]._count = 5;
	tw[19]._value = 9, tw[19]._weight = 20, tw[19]._weight2 = 2, tw[19]._count = 4;
	tw[20]._value = 8, tw[20]._weight = 22, tw[20]._weight2 = 5, tw[20]._count = 7;
	tw[21]._value = 13, tw[21]._weight = 16, tw[21]._weight2 = 8, tw[21]._count = 8;
	tw[22]._value = 14, tw[22]._weight = 6, tw[22]._weight2 = 10, tw[22]._count = 3;
	tw[23]._value = 2, tw[23]._weight = 10, tw[23]._weight2 = 9, tw[23]._count = 3;
	tw[24]._value = 7, tw[24]._weight = 4, tw[24]._weight2 = 7, tw[24]._count = 10;

	cout << "two weightw pack: " << two_dimension_pack(tw, n, 50, 40) << endl;
	
	packet_object q;
	q._group_number = 5, q._object_number = 4, q._total = 20;
	q._objects[1][1] = t[1]; q._objects[1][2] = t[2]; q._objects[1][3] = t[3]; q._objects[1][4] = t[4];
	q._objects[2][1] = t[5], q._objects[2][2] = t[6]; q._objects[2][3] = t[7]; q._objects[2][4] = t[8];
	q._objects[3][1] = t[9]; q._objects[3][2] = t[10]; q._objects[3][3] = t[11]; q._objects[3][4] = t[12];
	q._objects[4][1] = t[13]; q._objects[4][2] = t[14]; q._objects[4][3] = t[15]; q._objects[4][4] = t[16];
	q._objects[5][1] = t[17]; q._objects[5][2] = t[18]; q._objects[5][3] = t[19]; q._objects[5][4] = t[20];
	cout << "packet pack: " << packet_pack(q, 50) << endl;
	return(0);
}
