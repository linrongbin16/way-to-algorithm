#include "5_two_dimension_pack.h"
#include <iostream>
using namespace std;

int main()
{
	two_dimension_pack_object tw[25];
	int n = 24;
	tw[1].m_value = 5, tw[1].m_weight = 4, tw[1].m_weight2 = 11, tw[1].m_count = 5;
	tw[2].m_value = 12, tw[2].m_weight = 21, tw[2].m_weight2 = 13, tw[2].m_count = 2;
	tw[3].m_value = 4, tw[3].m_weight = 13, tw[3].m_weight2 = 7, tw[3].m_count = 5;
	tw[4].m_value = 7, tw[4].m_weight = 15, tw[4].m_weight2 = 12, tw[4].m_count = 6;
	tw[5].m_value = 1, tw[5].m_weight = 3, tw[5].m_weight2 = 6, tw[5].m_count = 6;
	tw[6].m_value = 9, tw[6].m_weight = 13, tw[6].m_weight2 = 7, tw[6].m_count = 9;
	tw[7].m_value = 12, tw[7].m_weight = 7, tw[7].m_weight2 = 9, tw[7].m_count = 10;
	tw[8].m_value = 3, tw[8].m_weight = 9, tw[8].m_weight2 = 10, tw[8].m_count = 3;
	tw[9].m_value = 9, tw[9].m_weight = 10, tw[9].m_weight2 = 3, tw[9].m_count = 6;
	tw[10].m_value = 3, tw[10].m_weight = 17, tw[10].m_weight2 = 4, tw[10].m_count = 5;
	tw[11].m_value = 7, tw[11].m_weight = 13, tw[11].m_weight2 = 2, tw[11].m_count = 3;
	tw[12].m_value = 11, tw[12].m_weight = 19, tw[12].m_weight2 = 1, tw[12].m_count = 1;
	tw[13].m_value = 15, tw[13].m_weight = 8, tw[13].m_weight2 = 5, tw[13].m_count = 1;
	tw[14].m_value = 17, tw[14].m_weight = 7, tw[14].m_weight2 = 4, tw[14].m_count = 2;
	tw[15].m_value = 3, tw[15].m_weight = 4, tw[15].m_weight2 = 9, tw[15].m_count = 7;
	tw[16].m_value = 10, tw[16].m_weight = 3, tw[16].m_weight2 = 8, tw[16].m_count = 4;
	tw[17].m_value = 5, tw[17].m_weight = 11, tw[17].m_weight2 = 15, tw[17].m_count = 9;
	tw[18].m_value = 6, tw[18].m_weight = 7, tw[18].m_weight2 = 14, tw[18].m_count = 5;
	tw[19].m_value = 9, tw[19].m_weight = 20, tw[19].m_weight2 = 2, tw[19].m_count = 4;
	tw[20].m_value = 8, tw[20].m_weight = 22, tw[20].m_weight2 = 5, tw[20].m_count = 7;
	tw[21].m_value = 13, tw[21].m_weight = 16, tw[21].m_weight2 = 8, tw[21].m_count = 8;
	tw[22].m_value = 14, tw[22].m_weight = 6, tw[22].m_weight2 = 10, tw[22].m_count = 3;
	tw[23].m_value = 2, tw[23].m_weight = 10, tw[23].m_weight2 = 9, tw[23].m_count = 3;
	tw[24].m_value = 7, tw[24].m_weight = 4, tw[24].m_weight2 = 7, tw[24].m_count = 10;

	cout << "two weightw pack: " << two_dimension_pack(tw, n, 50, 40) << endl;
	
	return 0;
}
