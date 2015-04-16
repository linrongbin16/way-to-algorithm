//test

#include "general_head.h"
#include "graph.h"
extern void kruskal(edge_list& e);	//1
extern void prim(edge_list& e, int n, int beg);	//2
extern void clear_tree_status(edge_list& e);
extern int second_minimum_spanning_tree(edge_list e, int n);		//3
extern double optimal_ratio_spanning_tree(edge_list& e, double low, double high);//4
void print_edge(edge_list e);
int main()
{
	edge_list e(8);
	e.e_l[0].e_beg = 0, e.e_l[0].e_end = 1, e.e_l[0].e_value = 4; e.e_l[0].e_cost = 3;
	e.e_l[1].e_beg = 0, e.e_l[1].e_end = 2, e.e_l[1].e_value = 7; e.e_l[1].e_cost = 1;
	e.e_l[2].e_beg = 0, e.e_l[2].e_end = 3, e.e_l[2].e_value = 5; e.e_l[2].e_cost = 6;
	e.e_l[3].e_beg = 1, e.e_l[3].e_end = 3, e.e_l[3].e_value = 2; e.e_l[3].e_cost = 4;
	e.e_l[4].e_beg = 3, e.e_l[4].e_end = 5, e.e_l[4].e_value = 3; e.e_l[4].e_cost = 9;
	e.e_l[5].e_beg = 0, e.e_l[5].e_end = 5, e.e_l[5].e_value = 10; e.e_l[5].e_cost = 7;
	e.e_l[6].e_beg = 0, e.e_l[6].e_end = 4, e.e_l[6].e_value = 9; e.e_l[6].e_cost = 2;
	e.e_l[7].e_beg = 2, e.e_l[7].e_end = 4, e.e_l[7].e_value = 1; e.e_l[7].e_cost = 5;

	clear_tree_status(e);
	kruskal(e);	//1
	cout << "kruskal minimum spanning tree:" << endl;
	print_edge(e);
	cout << endl;

	clear_tree_status(e);
	prim(e, 6, 0);		//2
	cout << "prim minimum spanning tree:" << endl;
	print_edge(e);
	cout << endl;
	
	clear_tree_status(e);
	cout << "second minimum spanning tree's weight:" << endl;
	cout << second_minimum_spanning_tree(e, 6) << endl; //3

	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		e.e_l[i].e_dist = e.e_l[i].e_value;
	clear_tree_status(e);
	cout << "optimal ratio spanning tree's ratio:" << endl;
	cout << optimal_ratio_spanning_tree(e, 0.0, 100.0) << endl;		//4
	print_edge(e);

	return(0);
}
void print_edge(edge_list e)
{
	for(int i = 0; i < (int)e.e_l.size(); ++ i)
		if(e.e_l[i].e_join){
			cout << "(beg:" << e.e_l[i].e_beg << ",end:" << e.e_l[i].e_end;
			cout << ",edge value:" << e.e_l[i].e_value << ")" << endl;
		}
}
