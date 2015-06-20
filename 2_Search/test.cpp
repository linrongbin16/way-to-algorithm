//test

#include "1_brute_force.h"
#include "2_depth_first_search.h"
#include "3_breadth_first_search.h"
#include "4_bidirection_breadth_search.h"
#include "5_a_heuristic_search.h"
#include "6_dancing_links.h"
#include <algorithm>
using std::make_pair;

int main()
{
	int u[4] = {0, 0, 0, 0};
	cout  << endl << "brute force: " << endl;
	brute_force(u, 4, 3);	//1

	int v[3] = {0, 0, 0};
	cout << endl << "depth first search: " << endl;
	depth_first_search(v, 3, 5, 0);	//2

	cout << endl << "breadth first search: " << endl;
	breadth_first_search(4, 5, make_pair(1, 2));	//3

	bbs_node **s2 = new bbs_node*[20];
	for(int i = 0; i < 20; ++ i){
		s2[i] = new bbs_node[17];
		for(int j = 0; j < 17; ++ j) {
			s2[i][j].m_row = i;
			s2[i][j].m_col = j;
			s2[i][j].m_father_row = -1;
			s2[i][j].m_father_col = -1;
		}
	}
	cout << endl << "bidirection breadth search: " << endl;
	bidirection_breadth_search(s2, 20, 17, s2[0][0], s2[19][16]);	//4

	hs_node beg, end;
	beg.m_status = "4132x6758";
	end.m_status = "12345678x";
	cout << endl << "A* heuristic search:" << endl;
	a_heuristic_search(beg, end);	//5
    /*
	beg.m_status = "41732x568";
	end.m_status = "12345678x";
	cout << endl << "A* heuristic search:" << endl;
	a_heuristic_search(beg, end);
    */
	return(0);
}
