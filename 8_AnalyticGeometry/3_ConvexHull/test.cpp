//test

#include "general_head.h"
#include "geometry.h"
extern double nearest_neighbor(node *p, int n);	//1
extern void graham_scan(vector<node> s, stack<node>& stk);	//2
extern void quick_convex_hull(vector<node> s, vector<node>& con);	//3
void print_p(node *s, int n, string info);
int main()
{
	node s[26];
	s[0].n_x = 10; s[0].n_y = 1;
	s[1].n_x = 12; s[1].n_y = 1;
	s[2].n_x = 17; s[2].n_y = 2;
	s[3].n_x = 19; s[3].n_y = 4;
	s[4].n_x = 22; s[4].n_y = 10;
	s[5].n_x = 22; s[5].n_y = 11;
	s[6].n_x = 20; s[6].n_y = 13;
	s[7].n_x = 15; s[7].n_y = 15;
	s[8].n_x = 7; s[8].n_y = 15;
	s[9].n_x = 2; s[9].n_y = 9;
	s[10].n_x = 2; s[10].n_y = 7;
	s[11].n_x = 3; s[11].n_y = 4;
	s[12].n_x = 18; s[12].n_y = 3;
	s[13].n_x = 20; s[13].n_y = 6;
	s[14].n_x = 21; s[14].n_y = 8;
	s[15].n_x = 12; s[15].n_y = 15;
	s[16].n_x = 11; s[16].n_y = 15;
	s[17].n_x = 10; s[17].n_y = 15;
	s[18].n_x = 9; s[18].n_y = 15;
	s[19].n_x = 8; s[19].n_y = 15;
	s[20].n_x = 7; s[20].n_y = 13;
	s[21].n_x = 8; s[21].n_y = 11;
	s[22].n_x = 7; s[22].n_y = 6;
	s[23].n_x = 10; s[23].n_y = 6;
	s[24].n_x = 15; s[24].n_y = 2;
	s[25].n_x = 20; s[25].n_y = 11;
	print_p(s, 26, "node set s:");

	cout << endl << "nearest neighbor: " << nearest_neighbor(s, 26) << endl;	//1
	
	vector<node> s1;
	stack<node> stk;
	for(int i = 0; i < 26; ++ i)
		s1.push_back(s[i]);
	graham_scan(s1, stk);	//2
	cout << "graham scan:" << endl;
	cout << "the convex hull has " << (int)stk.size() << " nodes" << endl;
	while(!stk.empty()){
		node p = stk.top();
		p.n_print();
		cout << endl;
		stk.pop();
	}

	vector<node> c;
	quick_convex_hull(s1, c);	//3
	cout << endl << "quick convex hull:" << endl;
	cout << "the convex hull has " << (int)c.size() << " nodes" << endl;
	for(vector<node>::iterator it = c.begin(); it != c.end(); ++ it){
		it->n_print();
		cout << endl;
	}

	return(0);
}
void print_p(node *s, int n, string info)
{
	cout << info << endl;
	for(int i = 0; i < n; ++ i){
		cout << i << ' ';
		s[i].n_print();
		cout << endl;
	}
	cout << endl;
}
