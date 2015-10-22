#include <iostream>
#include "4_bidirection_breadth_search.h"
#include <algorithm>
using namespace std;

int main()
{
	bbs_node s2[MAX][MAX];
	for(int i = 0; i < 20; ++ i){
		for(int j = 0; j < 17; ++ j) {
			s2[i][j].m_row = i;
			s2[i][j].m_col = j;
			s2[i][j].m_father_row = -1;
			s2[i][j].m_father_col = -1;
		}
	}
	cout << endl << "bidirection breadth search: " << endl;
	bidirection_breadth_search(s2, 20, 17, s2[0][0], s2[19][16]);	//4

	return(0);
}
