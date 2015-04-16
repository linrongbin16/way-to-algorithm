//test

#include "general_head.h"
#include "graph.h"
extern void strongest_connected_component(graph_list& g);	//1
extern void gabow(graph_list& g);	//2
extern void cut(graph_list& g, vector<pair<int, int> >& cut_edge);	//3
extern void double_connected_component(graph_list g, deque<deque<pair<int, int> > >& com);	//4
extern void least_common_ancestors(graph_list g, map<pair<int, int>, int>& query);	//5
extern void range_most_query(int *s, int n,
		map<pair<int, int>, pair<int, int> >& query);
void print_value(graph_list g);
int main()
{
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

	cout << "strongest_connected_component:" << endl;
	strongest_connected_component(gl);	//1
	print_value(gl);

	for(int i = 0; i < 6; ++ i)
		gl.g_l[i][0].g_value = 0;
	cout << endl << "gabow:" << endl;
	gabow(gl);	//2
	print_value(gl);

	graph_list g2(15);
	graph_node gn2[15];
	for(int i = 0; i < 15; ++ i)
		gn2[i].g_idx = i;
	for(int i = 0; i < 15; ++ i)
		g2.g_l[i].push_back(gn2[i]);
	g2.g_l[0].push_back(gn2[1]); g2.g_l[0].push_back(gn2[2]);
	g2.g_l[1].push_back(gn2[0]); g2.g_l[1].push_back(gn2[3]);
	g2.g_l[2].push_back(gn2[0]); g2.g_l[2].push_back(gn2[5]);
	g2.g_l[2].push_back(gn2[6]); g2.g_l[2].push_back(gn2[9]);
	g2.g_l[3].push_back(gn2[1]); g2.g_l[3].push_back(gn2[4]); g2.g_l[3].push_back(gn2[7]); 
	g2.g_l[4].push_back(gn2[3]); g2.g_l[4].push_back(gn2[7]); g2.g_l[4].push_back(gn2[8]); 
	g2.g_l[5].push_back(gn2[2]); g2.g_l[5].push_back(gn2[6]); 
	g2.g_l[6].push_back(gn2[2]); g2.g_l[6].push_back(gn2[5]); 
	g2.g_l[6].push_back(gn2[9]); g2.g_l[6].push_back(gn2[10]); 
	g2.g_l[7].push_back(gn2[3]); g2.g_l[7].push_back(gn2[4]); g2.g_l[7].push_back(gn2[8]); 
	g2.g_l[8].push_back(gn2[4]); g2.g_l[8].push_back(gn2[7]); g2.g_l[8].push_back(gn2[11]);
	g2.g_l[9].push_back(gn2[6]); g2.g_l[9].push_back(gn2[10]); g2.g_l[9].push_back(gn2[2]);
	g2.g_l[10].push_back(gn2[6]); g2.g_l[10].push_back(gn2[9]);  
	g2.g_l[11].push_back(gn2[8]); g2.g_l[11].push_back(gn2[12]); g2.g_l[11].push_back(gn2[13]);
	g2.g_l[12].push_back(gn2[11]); g2.g_l[12].push_back(gn2[14]);
	g2.g_l[13].push_back(gn2[11]); g2.g_l[13].push_back(gn2[14]);
	g2.g_l[14].push_back(gn2[12]); g2.g_l[14].push_back(gn2[13]);

	vector<pair<int, int> > edge;
	cout << endl << "cut:" << endl;
	cut(g2, edge);	//3
	cout << "cut node: "; 
	for(int i = 0; i < (int)g2.g_l.size(); ++ i)
		if(g2.g_l[i][0].g_value == 1)
			cout << "(node:" << i << ") ";
	cout << endl << "cut edge: ";
	for(int i = 0; i < (int)edge.size(); ++ i)
		cout << "(edge:" << edge[i].first << "," << edge[i].second << ") ";
	cout << endl;

	cout << endl << "double connected component:" << endl;
	deque<deque<pair<int, int> > > comp;
	double_connected_component(g2, comp);	//4

	int visit[MAX];
	for(int i = 0; i < (int)comp.size(); ++ i){
		memset(visit, 0, MAX * sizeof(int));
		cout << "the " << i+1 << " double connected component:" << endl;
		for(int j = 0; j < (int)comp[i].size(); ++ j){
			if(!visit[comp[i][j].first])
				cout << "(node:" << comp[i][j].first << ") ";
			if(!visit[comp[i][j].second])
				cout << "(node:" << comp[i][j].second << ") ";
			visit[comp[i][j].first] = visit[comp[i][j].second] = 1;
		}
		cout << endl;
	}

	graph_list g3(11);
	graph_node n3[11];
	for(int i = 0; i < 11; ++ i)
		n3[i].g_idx = i;
	for(int i = 0; i < 11; ++ i)
		g3.g_l[i].push_back(n3[i]);
	g3.g_l[0].push_back(n3[1]);	g3.g_l[0].push_back(n3[2]); g3.g_l[0].push_back(n3[5]);
	g3.g_l[1].push_back(n3[3]);	g3.g_l[1].push_back(n3[4]); 
	g3.g_l[5].push_back(n3[7]);	g3.g_l[5].push_back(n3[8]); g3.g_l[5].push_back(n3[6]);

	g3.g_l[8].push_back(n3[10]); g3.g_l[8].push_back(n3[9]); 

	cout << endl << "least common ancestors:" << endl;
	map<pair<int, int>, int> query;
	query.insert(make_pair(make_pair(3, 4), 0));
	query.insert(make_pair(make_pair(3, 5), 0));
	query.insert(make_pair(make_pair(10, 7), 0));
	least_common_ancestors(g3, query);	//5
	for(map<pair<int, int>, int>::iterator it = query.begin(); it != query.end(); ++ it)
		cout << "query:(" << it->first.first << "," << it->first.second << "): " << it->second << endl;

	cout << endl << "range most query" << endl;
	cout << "sequence: ";
	int q[15] ={0, 3, 4, 12, 34, -5, 3, 45, 12, 22, 9, 7, 56, 27, 11};
	for(int i = 1; i < 15; ++ i)
		cout << q[i] << ' ';
	cout << endl;
	map<pair<int, int>, pair<int, int> > query1;
	query1.insert(make_pair(make_pair(1, 14), make_pair(0, 0)));
	query1.insert(make_pair(make_pair(1, 1), make_pair(0, 0)));
	query1.insert(make_pair(make_pair(11, 14), make_pair(0, 0)));
	range_most_query(q, 14, query1);
	for(map<pair<int, int>, pair<int, int> >::iterator it = query1.begin(); 
			it != query1.end(); ++ it)
		cout << "query1:(" << it->first.first << "," << it->first.second << "), max: " << it->second.first << ", min: " << it->second.second << endl;
	return(0);
}
void print_value(graph_list g)
{
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		cout << "(node:" << i << ",value:" << g.g_l[i][0].g_value << ")" << endl;
}
