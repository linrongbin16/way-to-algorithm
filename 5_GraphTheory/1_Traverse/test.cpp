//test

#include "general_head.h"
#include "graph.h"
extern void preorder_traverse(tree_node *root);	//1
extern void inorder_traverse(tree_node *root);	//2
extern void postorder_traverse(tree_node *root);	//3
extern void depth_first_search_adjlist(graph_list g);	//4
extern void breadth_first_search_adjlist(graph_list g, int beg);	//5
extern void topological_sort1(graph_list g, deque<graph_node>& topo);	//6
extern void topological_sort2(graph_list g, deque<graph_node>& topo);	//7
extern bool euler_loop(graph_matrix g, stack<int>& path);	//8
extern void kosaraju(graph_list& g);	//9
void print_component(graph_list g);
int main()
{
	tree_node t1, t2, t3, t4;
	t1.t_idx = 1, t2.t_idx = 2, t3.t_idx = 3, t4.t_idx = 4;
	t1.t_lc = &t2, t1.t_rc = &t3, t2.t_rc = &t4;
	cout << "preorder:" << endl;
	preorder_traverse(&t1); //1
	cout << endl << "inorder:" << endl;
	inorder_traverse(&t1);	//2
	cout << endl << "postorder:" << endl;
	postorder_traverse(&t1);	//3

	graph_list g(9);
	graph_node gn[9];
	for(int i = 0; i < 9; ++ i)
		gn[i].g_idx = i;
	for(int i = 0; i < 9; ++ i)
		g.g_l[i].push_back(gn[i]);
	g.g_l[0].push_back(gn[1]); g.g_l[0].push_back(gn[3]);
	g.g_l[1].push_back(gn[2]);
	g.g_l[2].push_back(gn[6]); g.g_l[2].push_back(gn[3]);
	g.g_l[3].push_back(gn[4]);
	g.g_l[4].push_back(gn[5]); g.g_l[4].push_back(gn[6]);
	g.g_l[5].push_back(gn[7]);
	g.g_l[6].push_back(gn[7]); g.g_l[6].push_back(gn[8]);
	g.g_l[7].push_back(gn[8]);
	
	cout << endl << "dfs:" << endl;
	depth_first_search_adjlist(g);	//4
	cout << endl << "bfs:" << endl;
	breadth_first_search_adjlist(g, 0);	//5
	cout << endl << "topological sort 1:" << endl;
	deque<graph_node> p1;
	topological_sort1(g, p1);	//6
	for(int i = 0; i < (int)p1.size(); ++ i)
		cout << p1[i].g_idx << ' ';

	cout << endl << "topological sort 2:" << endl;
	deque<graph_node> p2;
	topological_sort2(g, p2);	//7
	for(int i = 0; i < (int)p2.size(); ++ i)
		cout << p2[i].g_idx << ' ';

	cout << endl << "euler loop:" << endl;
	graph_matrix m;
	m.g_cnt = 5;
	m.g_m[0][1] = 1, m.g_m[0][2] = 1; m.g_m[0][3] = 1, m.g_m[0][4] = 1;
	m.g_m[1][0] = 1, m.g_m[1][2] = 1, m.g_m[1][3] = 1, m.g_m[1][4] = 1;
	m.g_m[2][0] = 1, m.g_m[2][1] = 1, m.g_m[2][3] = 1, m.g_m[2][4] = 1;
	m.g_m[3][0] = 1, m.g_m[3][1] = 1, m.g_m[3][2] = 1, m.g_m[3][4] = 1;
	m.g_m[4][0] = 1, m.g_m[4][1] = 1, m.g_m[4][2] = 1, m.g_m[4][3] = 1;
	stack<int> ans;
	if(euler_loop(m, ans)){	//8
		while(!ans.empty()){
			cout << ans.top() << ' ';
			ans.pop();
		}
		cout << endl;
	}

	
	graph_list gl(6);
	graph_node no[6];
	for(int i = 0; i < 6; ++ i)
		no[i].g_idx = i;
	for(int i = 0; i < 6; ++ i)
		gl.g_l[i].push_back(no[i]);
	gl.g_l[0].push_back(no[1]); gl.g_l[0].push_back(no[2]);
	gl.g_l[1].push_back(no[3]);
	gl.g_l[2].push_back(no[3]); gl.g_l[2].push_back(no[4]);
	gl.g_l[3].push_back(no[5]); gl.g_l[3].push_back(no[0]);
	gl.g_l[4].push_back(no[5]);

	cout << "kosaraju:" << endl;
	kosaraju(gl);	//9
	print_component(gl);

	return(0);
}
void print_component(graph_list g)
{
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		cout << "(node:" << i << ",component:" << g.g_l[i][0].g_value << ")" << endl;
}
