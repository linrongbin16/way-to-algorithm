//test

#include "general_head.h"
#include "tree_dynamic.h"
extern int binary_tree1(tree_node *r, int resv);	//1
extern int binary_tree2(tree_node *r, int **f, int resv);	//2
extern int multi_tree(tree_node *r, int **f, int resv);	//3
extern void multi_tree_path(tree_node *r, int **f, int resv);	//4
extern int traverse_tree(tree_node *r, int **fdown, int **fup, int level);	//5
void init_2f(int f[MAX][MAX])
{
	for(int i = 0; i < MAX; ++ i)
		for(int j = 0; j < MAX; ++ j)
			f[i][j] = 0;
}
void init_3f(int f[MAX][MAX][MAX])
{
	for(int i = 0; i < MAX; ++ i)
		for(int j = 0; j < MAX; ++ j)
			for(int k = 0; k < MAX; ++ k)
				f[i][j][k] = 0;
}
int main()
{
	//construct a tree, 46 nodes, 45 branches
	tree_node t[60];
	for(int i = 0; i < 60; ++ i)
		t[i].t_idx = i, t[i].t_value = i;
	t[1].t_lc = &t[2]; t[1].t_rc = &t[3]; t[1].t_cnt = 3;
	t[1].t_child[0] = &t[2]; t[1].t_child[1] = &t[3]; t[1].t_child[2] = &t[4];
	t[2].t_fa = &t[1]; t[3].t_fa = &t[1]; t[4].t_fa = &t[1];
	t[2].t_lc = &t[5]; t[2].t_rc = &t[6];; t[2].t_cnt = 3;
	t[2].t_child[0] = &t[5]; t[2].t_child[1] = &t[6]; t[2].t_child[2] = &t[7];
	t[5].t_fa = &t[2]; t[6].t_fa = &t[2]; t[7].t_fa = &t[2];
	t[3].t_lc = &t[8]; t[3].t_rc = &t[9]; t[3].t_cnt = 2;
	t[3].t_child[0] = &t[8]; t[3].t_child[1] = &t[9];
	t[8].t_fa = &t[3]; t[9].t_fa = &t[2];
	t[4].t_lc = &t[10]; t[4].t_rc = &t[11]; t[4].t_cnt = 3;
	t[4].t_child[0] = &t[10]; t[4].t_child[1] = &t[11]; t[4].t_child[2] = &t[12];
	t[10].t_fa = &t[4]; t[11].t_fa = &t[4]; t[12].t_fa = &t[4];
	t[6].t_lc = &t[13]; t[6].t_rc = &t[14]; t[6].t_cnt = 3;
	t[6].t_child[0] = &t[13]; t[6].t_child[1] = &t[14]; t[6].t_child[2] = &t[15];
	t[13].t_fa = &t[6]; t[14].t_fa = &t[6]; t[15].t_fa = &t[6];
	t[9].t_lc = &t[16]; t[9].t_rc = &t[17]; t[9].t_cnt = 5;
	t[9].t_child[0] = &t[16]; t[9].t_child[1] = &t[17]; t[9].t_child[2] = &t[18];
	t[9].t_child[3] = &t[19]; t[9].t_child[4] = &t[20];
	t[16].t_fa = &t[9]; t[17].t_fa = &t[9]; t[18].t_fa = &t[8]; t[19].t_fa = &t[9]; t[20].t_fa = &t[9];
	t[15].t_lc = &t[22]; t[15].t_rc = &t[23]; t[15].t_cnt = 2;
	t[15].t_child[0] = &t[22]; t[15].t_child[1] = &t[23];
	t[22].t_fa = &t[15]; t[23].t_fa = &t[15];
	t[20].t_lc = &t[24]; t[20].t_rc = &t[25]; t[20].t_cnt = 4;
	t[20].t_child[0] = &t[24]; t[20].t_child[1] = &t[25];
	t[20].t_child[2] = &t[26]; t[20].t_child[3] = &t[27];
	t[24].t_fa = &t[20]; t[25].t_fa = &t[20]; t[26].t_fa = &t[20]; t[27].t_fa = &t[20];
	t[22].t_lc = &t[28]; t[22].t_rc = &t[29]; t[22].t_cnt = 3;
	t[22].t_child[0] = &t[28]; t[22].t_child[1] = &t[29]; t[22].t_child[2] = &t[30];
	t[28].t_fa = &t[22]; t[29].t_fa = &t[22]; t[30].t_fa = &t[22];
	t[25].t_lc = &t[31]; t[25].t_rc = &t[32]; t[25].t_cnt = 3;
	t[25].t_child[0] = &t[31]; t[25].t_child[1] = &t[32]; t[25].t_child[2] = &t[33];
	t[31].t_fa = &t[25]; t[32].t_fa = &t[25]; t[33].t_fa = &t[25];
	t[30].t_lc = &t[34]; t[30].t_rc = &t[35]; t[30].t_cnt = 2;
	t[30].t_child[0] = &t[34]; t[30].t_child[1] = &t[35];
	t[34].t_fa = &t[30]; t[35].t_fa = &t[30];
	t[31].t_lc = &t[36]; t[31].t_rc = &t[37]; t[31].t_cnt = 2;
	t[31].t_child[0] = &t[36]; t[31].t_child[1] = &t[37];
	t[36].t_fa = &t[31]; t[37].t_fa = &t[31];
	t[33].t_lc = &t[38]; t[33].t_rc = &t[39]; t[33].t_cnt = 2;
	t[33].t_child[0] = &t[38]; t[33].t_child[1] = &t[39];
	t[38].t_fa = &t[33]; t[39].t_fa  = &t[33];
	t[34].t_lc = &t[40]; t[34].t_rc = &t[41]; t[34].t_cnt = 3;
	t[34].t_child[0] = &t[40]; t[34].t_child[1] = &t[41]; t[34].t_child[2] = &t[42];
	t[40].t_fa = &t[34]; t[41].t_fa = &t[34]; t[42].t_fa = &t[34];
	t[37].t_lc = &t[43]; t[37].t_rc = &t[44]; t[37].t_cnt = 4;
	t[37].t_child[0] = &t[43]; t[37].t_child[1] = &t[44];
	t[37].t_child[2] = &t[45]; t[37].t_child[3] = &t[46];
	t[43].t_fa = &t[37]; t[44].t_fa = &t[37]; t[45].t_fa = &t[37]; t[46].t_fa = &t[37];
	t[43].t_lc = &t[47]; t[43].t_rc = &t[48]; t[43].t_cnt = 2;
	t[43].t_child[0] = &t[47]; t[43].t_child[1] = &t[48];
	t[47].t_fa = &t[43]; t[48].t_fa = &t[43];
	t[44].t_lc = &t[49]; t[44].t_rc = &t[50]; t[44].t_cnt = 2;
	t[44].t_child[0] = &t[49]; t[44].t_child[1] = &t[50];
	t[49].t_fa = &t[44]; t[50].t_fa = &t[44];
	t[47].t_lc = &t[51]; t[47].t_rc = &t[52]; t[47].t_cnt = 2;
	t[47].t_child[0] = &t[51]; t[47].t_child[1] = &t[52];
	t[51].t_fa = &t[47]; t[48].t_fa = &t[47];
	t[49].t_lc = &t[53]; t[49].t_rc = &t[54]; t[49].t_cnt = 2;
	t[49].t_child[0] = &t[53]; t[49].t_child[1] = &t[54];
	t[53].t_fa = &t[49]; t[54].t_fa = &t[49];
	t[50].t_lc = &t[55]; t[50].t_rc = &t[56]; t[50].t_cnt = 2;
	t[50].t_child[0] = &t[55]; t[50].t_child[1] = &t[56];
	t[55].t_fa = &t[50]; t[56].t_fa = &t[50];
	t[53].t_lc = &t[57]; t[53].t_rc = &t[58]; t[53].t_cnt = 2;
	t[53].t_child[0] = &t[57]; t[53].t_child[1] = &t[58];
	t[57].t_fa = &t[53]; t[58].t_fa = &t[53];
	int f2[MAX][MAX];
	init_2f(f2);
	cout << endl << "binary dynamic 1: ";
	cout << binary_tree1(&t[44], 5) <<  endl;	//1
	cout << endl << "binary dynamic 2: ";
	cout << binary_tree2(&t[44], f2, 5) << endl;	//2
	init_2f(f2);
	cout << "multi dynamic:";
	cout << multi_tree(&t[22], f2, 5) << endl;	//3

	cout << "multi dynamic path:" << endl;
	multi_tree_path(&t[22], f2, 5);	//4
	cout << endl;
	int f3[MAX][MAX];
	init_2f(f3);
	init_2f(f2);
	cout << "traverse tree: " << traverse_tree(&t[1], f2, f3, 4) << endl;	//5
	return(0);
}
