//test

#include "general_head.h"
#include "graph.h"
extern int edmonds_karp(graph_matrix residue, int beg, int end);	//1
extern int distance_label(graph_matrix residue, int beg, int end);	//2
extern int relabel_to_front(graph_list residue, int beg, int end);	//3
extern int distance_label_list(edge_list residue, int beg, int end, int n);	//4
extern pair<int, int> minimum_cost_max_flow(graph_matrix residue, graph_matrix cost,
		int beg, int end);	//5
extern bool no_source_sink_bounded_flow(graph_matrix upper, graph_matrix lower);//6
extern bool bounded_max_flow(graph_matrix upper, graph_matrix lower,
		int beg, int end, int& max_flow);	//7
extern bool bounded_min_flow(graph_matrix upper, graph_matrix lower,
		int beg, int end, int& min_flow);	//8
graph_list* create_list();
int main()
{
	graph_matrix g1;
	g1.g_cnt = 15;
	g1.g_m[0][1] = 30; g1.g_m[0][2] = 43;
	g1.g_m[1][3] = 18; g1.g_m[1][4] = 15;
	g1.g_m[2][4] = 25; g1.g_m[2][5] = 30;
	g1.g_m[3][4] = 10; g1.g_m[3][6] = 5;
	g1.g_m[4][5] = 6; g1.g_m[4][6] = 30;
	g1.g_m[5][7] = 27; g1.g_m[5][10] = 16;
	g1.g_m[6][7] = 21; g1.g_m[6][11] = 11;
	g1.g_m[7][8] = 9; g1.g_m[7][9] = 15; g1.g_m[7][10] = 35;
	g1.g_m[8][11] = 11;
	g1.g_m[9][12] = 7; g1.g_m[9][13] = 2;
	g1.g_m[10][13] = 20;
	g1.g_m[11][14] = 40; g1.g_m[11][12] = 30;
	g1.g_m[12][13] = 40;
	g1.g_m[13][14] = 13;
	
	cout << "edmonds karp: " << edmonds_karp(g1, 0, 14) << endl;	//1
	cout << "distance_label: " << distance_label(g1, 0, 14) << endl;	//2

	//g2和g1描绘相同的图
	graph_list *g2 = create_list();
	cout << "relabel to front: "  << relabel_to_front(*g2, 0, 14) << endl;	//3
	delete(g2);

	//g3->g1描绘相同的图
	//由于距离标号算法的邻接表优化形式的需要，每条边对应有一条反向边
	//并且这两条边第一个是偶数号，第二个是奇数号，反向边比原边大1
	edge_list *g3= new edge_list(50);
	g3->e_l[0].e_beg = 0; g3->e_l[0].e_end = 1; g3->e_l[0].e_value = 30;
	g3->e_l[1].e_beg = 1; g3->e_l[1].e_end = 0; g3->e_l[1].e_value = 0;

	g3->e_l[2].e_beg = 0; g3->e_l[2].e_end = 2; g3->e_l[2].e_value = 43;
	g3->e_l[3].e_beg = 2; g3->e_l[3].e_end = 0; g3->e_l[3].e_value = 0;

	g3->e_l[4].e_beg = 1; g3->e_l[4].e_end = 3; g3->e_l[4].e_value = 18;
	g3->e_l[5].e_beg = 3; g3->e_l[5].e_end = 1; g3->e_l[5].e_value = 0;

	g3->e_l[6].e_beg = 1; g3->e_l[6].e_end = 4; g3->e_l[6].e_value = 15;
	g3->e_l[7].e_beg = 4; g3->e_l[7].e_end = 1; g3->e_l[7].e_value = 0;

	g3->e_l[8].e_beg = 2; g3->e_l[8].e_end = 4; g3->e_l[8].e_value = 25;
	g3->e_l[9].e_beg = 4; g3->e_l[9].e_end = 2; g3->e_l[9].e_value = 0;

	g3->e_l[10].e_beg = 2; g3->e_l[10].e_end = 5; g3->e_l[10].e_value = 30;
	g3->e_l[11].e_beg = 5; g3->e_l[11].e_end = 2; g3->e_l[11].e_value = 0;

	g3->e_l[12].e_beg = 3; g3->e_l[12].e_end = 4; g3->e_l[12].e_value = 10;
	g3->e_l[13].e_beg = 4; g3->e_l[13].e_end = 3; g3->e_l[13].e_value = 0;

	g3->e_l[14].e_beg = 3; g3->e_l[14].e_end = 6; g3->e_l[14].e_value = 5;
	g3->e_l[15].e_beg = 6; g3->e_l[15].e_end = 3; g3->e_l[15].e_value = 0;

	g3->e_l[16].e_beg = 4; g3->e_l[16].e_end = 6; g3->e_l[16].e_value = 30;
	g3->e_l[17].e_beg = 6; g3->e_l[17].e_end = 4; g3->e_l[17].e_value = 0;

	g3->e_l[18].e_beg = 4; g3->e_l[18].e_end = 5; g3->e_l[18].e_value = 6;
	g3->e_l[19].e_beg = 5; g3->e_l[19].e_end = 4; g3->e_l[19].e_value = 0;

	g3->e_l[20].e_beg = 5; g3->e_l[20].e_end = 7; g3->e_l[20].e_value = 27;
	g3->e_l[21].e_beg = 7; g3->e_l[21].e_end = 5; g3->e_l[21].e_value = 0;

	g3->e_l[22].e_beg = 5; g3->e_l[22].e_end = 10; g3->e_l[22].e_value = 16;
	g3->e_l[23].e_beg = 10; g3->e_l[23].e_end = 5; g3->e_l[23].e_value = 0;

	g3->e_l[24].e_beg = 6; g3->e_l[24].e_end = 7; g3->e_l[24].e_value = 21;
	g3->e_l[25].e_beg = 7; g3->e_l[25].e_end = 6; g3->e_l[25].e_value = 0;

	g3->e_l[26].e_beg = 6; g3->e_l[26].e_end = 11; g3->e_l[26].e_value = 11;
	g3->e_l[27].e_beg = 11; g3->e_l[27].e_end = 6; g3->e_l[27].e_value = 0;

	g3->e_l[28].e_beg = 7; g3->e_l[28].e_end = 8; g3->e_l[28].e_value = 9;
	g3->e_l[29].e_beg = 8; g3->e_l[29].e_end = 7; g3->e_l[29].e_value = 0;

	g3->e_l[30].e_beg = 7; g3->e_l[30].e_end = 9; g3->e_l[30].e_value = 15;
	g3->e_l[31].e_beg = 9; g3->e_l[31].e_end = 7; g3->e_l[31].e_value = 0;

	g3->e_l[32].e_beg = 7; g3->e_l[32].e_end = 10; g3->e_l[32].e_value = 35;
	g3->e_l[33].e_beg = 10; g3->e_l[33].e_end = 7; g3->e_l[33].e_value = 0;

	g3->e_l[34].e_beg = 8; g3->e_l[34].e_end = 11; g3->e_l[34].e_value = 11;
	g3->e_l[35].e_beg = 11; g3->e_l[35].e_end = 8; g3->e_l[35].e_value = 0;

	g3->e_l[36].e_beg = 9; g3->e_l[36].e_end = 12; g3->e_l[36].e_value = 7;
	g3->e_l[37].e_beg = 12; g3->e_l[37].e_end = 9; g3->e_l[37].e_value = 0;

	g3->e_l[38].e_beg = 9; g3->e_l[38].e_end = 13; g3->e_l[38].e_value = 2;
	g3->e_l[39].e_beg = 13; g3->e_l[39].e_end = 9; g3->e_l[39].e_value = 0;

	g3->e_l[40].e_beg = 11; g3->e_l[40].e_end = 12; g3->e_l[40].e_value = 30;
	g3->e_l[41].e_beg = 12; g3->e_l[41].e_end = 11; g3->e_l[41].e_value = 0;

	g3->e_l[42].e_beg = 11; g3->e_l[42].e_end = 14; g3->e_l[42].e_value = 40;
	g3->e_l[43].e_beg = 14; g3->e_l[43].e_end = 11; g3->e_l[43].e_value = 0;

	g3->e_l[44].e_beg = 12; g3->e_l[44].e_end = 13; g3->e_l[44].e_value = 40;
	g3->e_l[45].e_beg = 13; g3->e_l[45].e_end = 12; g3->e_l[45].e_value = 0;

	g3->e_l[46].e_beg = 13; g3->e_l[46].e_end = 14; g3->e_l[46].e_value = 13;
	g3->e_l[47].e_beg = 14; g3->e_l[47].e_end = 13; g3->e_l[47].e_value = 0;

	g3->e_l[48].e_beg = 10; g3->e_l[48].e_end = 13; g3->e_l[48].e_value = 20;
	g3->e_l[49].e_beg = 13; g3->e_l[49].e_end = 10; g3->e_l[49].e_value = 0;
	
	cout << "distance label list: " << distance_label_list(*g3, 0, 14, 15) << endl;	//4
	delete(g3);

	graph_matrix c1;
	c1.g_cnt = 15;
	for(int i = 0; i < 15; ++ i)
		for(int j = 0; j < 15; ++ j)
			c1.g_m[i][j] = (i == j)? 0 : INF;
	c1.g_m[0][1] = 2; c1.g_m[0][2] = 3;
	c1.g_m[1][3] = 2; c1.g_m[1][4] = 5;
	c1.g_m[2][4] = 2; c1.g_m[2][5] = 2;
	c1.g_m[3][4] = 1; c1.g_m[3][6] = 2;
	c1.g_m[4][5] = 1; c1.g_m[4][6] = 3;
	c1.g_m[5][7] = 4; c1.g_m[5][10] = 3;
	c1.g_m[6][7] = 1; c1.g_m[6][11] = 2;
	c1.g_m[7][8] = 3; c1.g_m[7][9] = 2; c1.g_m[7][10] = 5;
	c1.g_m[8][11] = 3;
	c1.g_m[9][12] = 6; c1.g_m[9][13] = 5;
	c1.g_m[10][13] = 4;
	c1.g_m[11][12] = 4; c1.g_m[11][14] = 5;
	c1.g_m[12][13] = 2;
	c1.g_m[13][14] = 3;

	pair<int, int> mm =  minimum_cost_max_flow(g1, c1, 0, 14);	//5
	cout << "minimum cost max flow, max flow: " << mm.first << ", min cost: " << mm.second << endl;

	//graph_matrix是一个非常占用内存的数据结构，所以test中从头到尾只使用了两个
	//后面容量有上下界的代码中，g1为上界容量，c1为下界容量
	for(int i = 0; i < MAX; ++ i)
		for(int j = 0; j < MAX; ++ j)
			g1.g_m[i][j] = c1.g_m[i][j] = 0;
	g1.g_cnt = 4; c1.g_cnt = 4;
	g1.g_m[0][1] = 3; c1.g_m[0][1] = 1;
	g1.g_m[0][0] = 0; c1.g_m[0][0] = 0;
	g1.g_m[0][2] = 3; c1.g_m[0][2] = 1;
	g1.g_m[0][3] = 0; c1.g_m[0][3] = 0;

	g1.g_m[1][2] = 3; c1.g_m[1][2] = 1;
	g1.g_m[1][0] = 0; c1.g_m[1][0] = 0;
	g1.g_m[1][1] = 0; c1.g_m[1][1] = 0;
	g1.g_m[1][3] = 0; c1.g_m[1][3] = 0;

	g1.g_m[2][3] = 3; c1.g_m[2][3] = 1;
	g1.g_m[2][0] = 0; c1.g_m[2][0] = 0;
	g1.g_m[2][1] = 0; c1.g_m[2][1] = 0;
	g1.g_m[2][2] = 0; c1.g_m[2][2] = 0;

	g1.g_m[3][0] = 3; c1.g_m[3][0] = 1;
	g1.g_m[3][1] = 3; c1.g_m[3][1] = 1;
	g1.g_m[3][2] = 0; c1.g_m[3][2] = 0;
	g1.g_m[3][3] = 0; c1.g_m[3][3] = 0;

	cout << "no source sink bounded flow ";
	if(no_source_sink_bounded_flow(g1, c1))//6
		cout << "exist a flow" << endl;
	else
		cout << "`doesn't` exist a flow" << endl;
	
	//在no source sink bounded flow中g1，c1更改边，使0为源点，3为汇点
	g1.g_m[3][0] = 0; c1.g_m[3][0] = 0;
	g1.g_m[1][3] = 3; c1.g_m[1][3] = 1;

	int max_flow(0);
	cout << "bounded max flow ";
	if(bounded_max_flow(g1, c1, 0, 3, max_flow))	//7
		cout << "exist a flow, max flow: " << max_flow <<  endl;
	else
		cout << "`doesn't` exist a flow, no max flow" << endl;

	cout << "bounded min flow ";
	if(bounded_min_flow(g1, c1, 0, 3, max_flow))	//8
		cout << "exist a flow, min flow ... " << endl;
	else
		cout << "`doesn't` exist a flow, no min flow" << endl;

	return(0);
}
graph_list* create_list()
{
	graph_list *g2 = new graph_list;
	deque<graph_node> d[15];
	for(int i = 0; i < 15; ++ i)
		d[i].push_back(graph_node(i));

	d[0].push_back(graph_node(1, 30)); d[0].push_back(graph_node(2, 43));
	d[1].push_back(graph_node(3, 18)); d[1].push_back(graph_node(4, 15));
	d[2].push_back(graph_node(5, 30)); d[2].push_back(graph_node(4, 25));
	d[3].push_back(graph_node(4, 10)); d[3].push_back(graph_node(6, 5));
	d[4].push_back(graph_node(5, 6)); d[4].push_back(graph_node(6, 30));
	d[5].push_back(graph_node(7, 27)); d[5].push_back(graph_node(10, 16));
	d[6].push_back(graph_node(7, 21)); d[6].push_back(graph_node(11, 11));
	d[7].push_back(graph_node(8, 9)); d[7].push_back(graph_node(9, 15)); d[7].push_back(graph_node(10, 35));
	d[8].push_back(graph_node(11, 11));
	d[9].push_back(graph_node(12, 7)); d[9].push_back(graph_node(13, 2));
	d[10].push_back(graph_node(13, 20));
	d[11].push_back(graph_node(12, 30)); d[11].push_back(graph_node(14, 40));
	d[12].push_back(graph_node(13, 40));
	d[13].push_back(graph_node(14, 13));
	for(int i = 0; i < 15; ++ i)
		g2->g_l.push_back(d[i]);
	return(g2);
}
