//test

#include "general_head.h"
#include "search.h"
extern void brute_force(int *s, int n, int m);	//1
extern void depth_first_search(int *s, int n, int m, int prev = 0);	//2
extern void breadth_first_search(int m, int n, pair<int, int> beg);	//3
extern void bidirection_breadth_search(bi_node **s, int m, int n,
		bi_node beg, bi_node end);	//4
extern void a_heuristic_search(star_node beg, star_node end);	//5
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

	bi_node **s2 = new bi_node*[6];
	for(int i = 0; i < 6; ++ i){
		s2[i] = new bi_node[5];
		for(int j = 0; j < 5; ++ j)
			s2[i][j].b_row = i, s2[i][j].b_col = j;
	}
	cout << endl << "bidirection breadth search: " << endl;
	bidirection_breadth_search(s2, 6, 5, s2[0][0], s2[5][4]);	//4

	star_node beg, end;
	beg.s_status = "4132x6758", end.s_status = "12345678x";
	cout << endl << "A* heuristic search:" << endl;
	a_heuristic_search(beg, end);	//5
	return(0);
}
