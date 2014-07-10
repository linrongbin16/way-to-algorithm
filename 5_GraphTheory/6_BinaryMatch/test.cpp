//test

#include "general_head.h"
#include "graph.h"
extern int hungarian1(bipartite b, int *xmatch, int *ymatch);	//1
extern int hungarian2(bipartite b, int *ymatch);	//2
extern int hopcroft_karp(bipartite b, int *xmatch, int *ymatch);	//3
extern int kuhn_munkres(bipartite b, int *ymatch);	//4
extern int minimum_disjoint_path_covering(graph_matrix g);	//5
extern int minimum_joint_path_covering(graph_matrix g);	//6 
void print_match(bipartite b, int *ymatch);
int main()
{
	int xmatch[MAX], ymatch[MAX];
	bipartite b1(4, 5);
	b1.b_g[0][0] = 1; b1.b_g[0][1] = 1; b1.b_g[0][2] = 1; b1.b_g[0][3] = 1;
	b1.b_g[1][0] = 1; b1.b_g[1][1] = 1; b1.b_g[1][3] = 1; b1.b_g[1][4] = 1;
	b1.b_g[2][1] = 1; b1.b_g[2][2] = 1; b1.b_g[2][3] = 1; b1.b_g[2][4] = 1;
	b1.b_g[3][0] = 1; b1.b_g[3][1] = 1; b1.b_g[3][2] = 1; b1.b_g[3][4] = 1;
	cout << "hungarian 1 max binary match: " << hungarian1(b1, xmatch, ymatch) << endl;	//1
	print_match(b1, ymatch);
	cout << "hungarian 2 max binary match: " << hungarian2(b1, ymatch) << endl;
	print_match(b1, ymatch);
	cout << "hopcroft karp max binary match: " << hopcroft_karp(b1, xmatch, ymatch) << endl;	//2
	print_match(b1, ymatch);

	bipartite b2(5, 5);
	b2.b_g[0][0] = 3; b2.b_g[0][1] = 5; b2.b_g[0][2] = 5; b2.b_g[0][3] = 4; b2.b_g[0][4] = 1;
	b2.b_g[1][0] = 2; b2.b_g[1][1] = 2; b2.b_g[1][2] = 0; b2.b_g[1][3] = 2; b2.b_g[1][4] = 2;
	b2.b_g[2][0] = 2; b2.b_g[2][1] = 4; b2.b_g[2][2] = 4; b2.b_g[2][3] = 1; b2.b_g[2][4] = 0;
	b2.b_g[3][0] = 0; b2.b_g[3][1] = 1; b2.b_g[3][2] = 1; b2.b_g[3][3] = 0; b2.b_g[3][4] = 0;
	b2.b_g[4][0] = 1; b2.b_g[4][1] = 2; b2.b_g[4][2] = 1; b2.b_g[4][3] = 3; b2.b_g[4][4] = 3;
	cout << "kuhn munkres: " << kuhn_munkres(b2, ymatch) << endl; //5
	print_match(b2, ymatch);

	graph_matrix g(6);
	g.g_m[0][0] = 0; g.g_m[0][1] = 1; g.g_m[0][2] = 1; g.g_m[0][3] = 1; g.g_m[0][4] = INF; g.g_m[0][5] = INF;
	g.g_m[1][0] = INF; g.g_m[1][1] = 0; g.g_m[1][2] = INF; g.g_m[1][3] = 1; g.g_m[1][4] = 1; g.g_m[1][5] = INF;
	g.g_m[2][0] = INF; g.g_m[2][1] = INF; g.g_m[2][2] = 0; g.g_m[2][3] = 1; g.g_m[2][4] = INF; g.g_m[2][5] = 1;
	g.g_m[3][0] = 0; g.g_m[3][1] = INF; g.g_m[3][2] = INF; g.g_m[3][3] = 0; g.g_m[3][4] = 1; g.g_m[3][5] = 1;
	g.g_m[4][0] = INF; g.g_m[4][1] = INF; g.g_m[4][2] = INF; g.g_m[4][3] = INF; g.g_m[4][4] = 0; g.g_m[4][5] = 1;
	g.g_m[5][0] = INF; g.g_m[5][1] = INF; g.g_m[5][2] = INF; g.g_m[5][3] = INF; g.g_m[5][4] = INF; g.g_m[5][5] = 0;
	cout << "disjoint path covering: " << minimum_disjoint_path_covering(g) << endl;//3
	cout << "joint path covering: " << minimum_joint_path_covering(g) << endl; //4
	return(0);
}
void print_match(bipartite b, int *ymatch)
{
	for(int i = 0; i < b.b_yn; ++ i)
		if(ymatch[i] != -1)
			cout << "(x node:" << ymatch[i] << ", y node: " << i << ", value: " << b.b_g[ymatch[i]][i] << ")"  <<  endl;
	cout << endl;
}
