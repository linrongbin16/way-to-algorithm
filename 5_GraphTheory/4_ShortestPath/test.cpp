//test

#include "general_head.h"
#include "graph.h"
extern bool bellman_ford(graph_matrix g, edge_list e,
		int beg, int *distance, int *path);	//1
extern bool spfa(graph_matrix g, int beg, int *distance, int *path);		//2
extern void dijkstra(graph_matrix g, int beg, int *distance, int *path);	//3
extern void floyd(graph_matrix &g);	//4
extern bool difference_constraints(int **s, int m, int n, int *b, int *distance);//5
void print_dp(int *dist, int *path, int n)
{
	cout << "distance: ";
	for(int i = 0; i < n; ++ i)
		cout << dist[i] << ' ';
	cout << endl << "path: " << endl;
	for(int i = 0; i < n; ++ i)
		cout << "node " << i << "'s father: " << path[i] << endl;
	cout << endl;
}
int main()
{
	graph_matrix g1;
	g1.g_cnt = 4;
	g1.g_m[0][1] = INF, g1.g_m[0][2] = 1, g1.g_m[0][3] = -5;
	g1.g_m[1][0] = INF, g1.g_m[1][2] = INF, g1.g_m[1][3] = 4;
	g1.g_m[2][0] = 1, g1.g_m[2][1] = INF, g1.g_m[2][3] = 2;
	g1.g_m[3][0] = -5, g1.g_m[3][1] = 4, g1.g_m[3][2] = 2;
	
	//这里的e1和g1描绘同一个图g1，8条边重复表示无向图，g1中存在负权值环
	edge_list e1(8);
	e1.e_l[0].e_beg = 0, e1.e_l[0].e_end = 2, e1.e_l[0].e_value = 1;
	e1.e_l[1].e_beg = 2, e1.e_l[1].e_end = 0, e1.e_l[1].e_value = 1;
	e1.e_l[2].e_beg = 2, e1.e_l[2].e_end = 3, e1.e_l[2].e_value = 2;
	e1.e_l[3].e_beg = 3, e1.e_l[3].e_end = 2, e1.e_l[3].e_value = 2;
	e1.e_l[4].e_beg = 0, e1.e_l[4].e_end = 3, e1.e_l[4].e_value = -5;
	e1.e_l[5].e_beg = 3, e1.e_l[5].e_end = 0, e1.e_l[5].e_value = -5;
	e1.e_l[6].e_beg = 1, e1.e_l[6].e_end = 3, e1.e_l[6].e_value = 4;
	e1.e_l[7].e_beg = 3, e1.e_l[7].e_end = 1, e1.e_l[7].e_value = 4;

	//g2中不存在负权环,g2和e2描绘同一个图g2
	graph_matrix g2;
	g2.g_cnt = 8;
	for(int i = 0; i < 8; ++ i)
		for(int j = 0; j < 8; ++ j)
			g2.g_m[i][j] = (i == j)? 0 : INF;
	g2.g_m[0][1] = 3; g2.g_m[0][2] = 9; g2.g_m[0][3] = 12;
	g2.g_m[1][0] = 3; g2.g_m[1][2] = 5; g2.g_m[1][5] = 9; g2.g_m[1][7] = 30;
	g2.g_m[2][0] = 9; g2.g_m[2][1] = 5; g2.g_m[2][7] = 26;
	g2.g_m[3][0] = 12; g2.g_m[3][4] = 3; g2.g_m[3][5] = 7; g2.g_m[3][6] = 20;
	g2.g_m[4][3] = 3; g2.g_m[4][5] = 11; g2.g_m[4][7] = 20;
	g2.g_m[5][1] = 9; g2.g_m[5][3] = 7; g2.g_m[5][4] = 11; g2.g_m[5][6] = 16;
	g2.g_m[6][3] = 20; g2.g_m[6][5] = 16; g2.g_m[6][7] = 9;
	g2.g_m[7][2] = 26; g2.g_m[7][1] = 30; g2.g_m[7][4] = 20; g2.g_m[7][6] = 9;
	edge_list e2(28);
	e2.e_l[0].e_beg = 0, e2.e_l[0].e_end = 1, e2.e_l[0].e_value = 3;
	e2.e_l[1].e_beg = 1, e2.e_l[1].e_end = 0, e2.e_l[1].e_value = 3;
	e2.e_l[2].e_beg = 0, e2.e_l[2].e_end = 2, e2.e_l[2].e_value = 9;
	e2.e_l[3].e_beg = 2, e2.e_l[3].e_end = 0, e2.e_l[3].e_value = 9;
	e2.e_l[4].e_beg = 1, e2.e_l[4].e_end = 2, e2.e_l[4].e_value = 5;
	e2.e_l[5].e_beg = 2, e2.e_l[5].e_end = 1, e2.e_l[5].e_value = 5;
	e2.e_l[6].e_beg = 0, e2.e_l[6].e_end = 3, e2.e_l[6].e_value = 12;
	e2.e_l[7].e_beg = 3, e2.e_l[7].e_end = 0, e2.e_l[7].e_value = 12;
	e2.e_l[8].e_beg = 1, e2.e_l[8].e_end = 5, e2.e_l[8].e_value = 9;
	e2.e_l[9].e_beg = 5, e2.e_l[9].e_end = 1, e2.e_l[9].e_value = 9;
	e2.e_l[10].e_beg = 1, e2.e_l[10].e_end = 7, e2.e_l[10].e_value = 30;
	e2.e_l[11].e_beg = 7, e2.e_l[11].e_end = 1, e2.e_l[11].e_value = 30;
	e2.e_l[12].e_beg = 3, e2.e_l[12].e_end = 4, e2.e_l[12].e_value = 3;
	e2.e_l[13].e_beg = 4, e2.e_l[13].e_end = 3, e2.e_l[13].e_value = 3;
	e2.e_l[14].e_beg = 3, e2.e_l[14].e_end = 5, e2.e_l[14].e_value = 7;
	e2.e_l[15].e_beg = 5, e2.e_l[15].e_end = 3, e2.e_l[15].e_value = 7;
	e2.e_l[16].e_beg = 3, e2.e_l[16].e_end = 6, e2.e_l[16].e_value = 20;
	e2.e_l[17].e_beg = 6, e2.e_l[17].e_end = 3, e2.e_l[17].e_value = 20;
	e2.e_l[18].e_beg = 2, e2.e_l[18].e_end = 7, e2.e_l[18].e_value = 26;
	e2.e_l[19].e_beg = 7, e2.e_l[19].e_end = 2, e2.e_l[19].e_value = 26;
	e2.e_l[20].e_beg = 4, e2.e_l[20].e_end = 5, e2.e_l[20].e_value = 11;
	e2.e_l[21].e_beg = 5, e2.e_l[21].e_end = 4, e2.e_l[21].e_value = 11;
	e2.e_l[22].e_beg = 5, e2.e_l[22].e_end = 6, e2.e_l[22].e_value = 16;
	e2.e_l[23].e_beg = 6, e2.e_l[23].e_end = 5, e2.e_l[23].e_value = 16;
	e2.e_l[24].e_beg = 6, e2.e_l[24].e_end = 7, e2.e_l[24].e_value = 9;
	e2.e_l[25].e_beg = 7, e2.e_l[25].e_end = 6, e2.e_l[25].e_value = 9;
	e2.e_l[26].e_beg = 4, e2.e_l[26].e_end = 7, e2.e_l[26].e_value = 20;
	e2.e_l[27].e_beg = 7, e2.e_l[27].e_end = 4, e2.e_l[27].e_value = 20;



	int dist[MAX], path[MAX];
	cout << "bellman ford on g1:" << endl;
	if(bellman_ford(g1, e1, 0, dist, path))	//1
		print_dp(dist, path, g1.g_cnt);
	else
		cout << "g1 doesn't exist shortest path" << endl;
	cout << "bellman ford on g2:" << endl;
	if(bellman_ford(g2, e2, 0, dist, path))	//1
		print_dp(dist, path, g2.g_cnt);
	else
		cout << "g2 doestn't exist shortest path" << endl;

	cout << "spfa on g1:" << endl;
	if(spfa(g1, 0, dist, path))	//2
		print_dp(dist, path, g1.g_cnt);
	else
		cout << "g1 doestn't exist shortest path" << endl;
	cout << "spfa on g2:" << endl;
	if(spfa(g2, 0, dist, path))	//2
		print_dp(dist, path, g2.g_cnt);
	else
		cout << "g2 doesn't exist shortest path" << endl;

	cout << "dijkstra on g2:";
	dijkstra(g2, 0, dist, path);	//3
	print_dp(dist, path, g2.g_cnt);

	cout << "floyd warshall on g2:" << endl;
	floyd(g2);	//4
	for(int i = 0; i < g2.g_cnt; ++ i){
		for(int j = 0; j < g2.g_cnt; ++ j)
			cout << g2.g_m[i][j] << ' ';
		cout << endl;
	}

	cout << endl << "difference constraints: ";
	int **ss = new int*[8];
	for(int i = 0; i < 8; ++ i)
		ss[i] = new int[5];
	ss[0][0] = 1, ss[0][1] = -1, ss[0][2] = 0, ss[0][3] = 0, ss[0][4] = 0;
	ss[1][0] = 1, ss[1][1] = 0, ss[1][2] = 0, ss[1][3] = 0, ss[1][4] = -1;
	ss[2][0] = 0, ss[2][1] = 1, ss[2][2] = 0, ss[2][3] = 0, ss[2][4] = -1;
	ss[3][0] = -1, ss[3][1] = 0, ss[3][2] = 1, ss[3][3] = 0, ss[3][4] = 0;
	ss[4][0] = -1, ss[4][1] = 0, ss[4][2] = 0, ss[4][3] = 1, ss[4][4] = 0;
	ss[5][0] = 0, ss[5][1] = 0, ss[5][2] = -1, ss[5][3] = 1, ss[5][4] = 0;
	ss[6][0] = 0, ss[6][1] = 0, ss[6][2] = -1, ss[6][3] = 0, ss[6][4] = 1;
	ss[7][0] = 0, ss[7][1] = 0, ss[7][2] = 0, ss[7][3] = -1, ss[7][4] = 1;
	int b[8] = {0, -1, 1, 5, 4, -1, -3, -3};
	int *dis = new int[MAX];
	if(difference_constraints(ss, 8, 5, b, dis)){	//5
		for(int i = 1; i <= 5; ++ i)
			cout  << dis[i] << ' ';
		cout << endl;
	}
	else
		cout << "no ans" << endl;
	return(0);
}
