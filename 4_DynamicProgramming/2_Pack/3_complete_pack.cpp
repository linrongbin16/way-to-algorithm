#include "3_complete_pack.h"
#include <iostream>
using namespace std;

int main()
{
	_01_pack_object t[25];
	int n = 24;
	t[1].m_value = 5, t[1].m_weight = 4, t[1].m_count = 5;
	t[2].m_value = 12, t[2].m_weight = 21, t[2].m_count = 2;
	t[3].m_value = 4, t[3].m_weight = 13, t[3].m_count = 5;
	t[4].m_value = 7, t[4].m_weight = 15, t[4].m_count = 6;
	t[5].m_value = 1, t[5].m_weight = 3, t[5].m_count = 6;
	t[6].m_value = 9, t[6].m_weight = 13, t[6].m_count = 9;
	t[7].m_value = 12, t[7].m_weight = 7, t[7].m_count = 10;
	t[8].m_value = 3, t[8].m_weight = 9, t[8].m_count = 3;
	t[9].m_value = 9, t[9].m_weight = 10, t[9].m_count = 6;
	t[10].m_value = 3, t[10].m_weight = 17, t[10].m_count = 5;
	t[11].m_value = 7, t[11].m_weight = 13, t[11].m_count = 3;
	t[12].m_value = 11, t[12].m_weight = 19, t[12].m_count = 1;
	t[13].m_value = 15, t[13].m_weight = 8, t[13].m_count = 1;
	t[14].m_value = 17, t[14].m_weight = 7, t[14].m_count = 2;
	t[15].m_value = 3, t[15].m_weight = 4, t[15].m_count = 7;
	t[16].m_value = 10, t[16].m_weight = 3, t[16].m_count = 4;
	t[17].m_value = 5, t[17].m_weight = 11, t[17].m_count = 9;
	t[18].m_value = 6, t[18].m_weight = 7,  t[18].m_count = 5;
	t[19].m_value = 9, t[19].m_weight = 20, t[19].m_count = 4;
	t[20].m_value = 8, t[20].m_weight = 22, t[20].m_count = 7;
	t[21].m_value = 13, t[21].m_weight = 16, t[21].m_count = 8;
	t[22].m_value = 14, t[22].m_weight = 6, t[22].m_count = 3;
	t[23].m_value = 2, t[23].m_weight = 10, t[23].m_count = 3;
	t[24].m_value = 7, t[24].m_weight = 4, t[24].m_count = 10;

	cout << "complete pack: " << complete_pack(t, n, 80) << endl;

	return 0;
}
