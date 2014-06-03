#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <cstdio>
#include <stack>
#include <limits>
#include <climits>
#include <list>
using namespace std;
ifstream fin;

#define MAX 500
#define INF (1 << 30)
int n, m, k, name_cnt;
map<string, int> name;
int g[MAX][MAX], start, dest, ans;
int d[MAX], path[MAX], d_num[MAX];


int distance_label();
void bfs();
int relabel(int u);
int find_allow(int u);
int main()
{
	fin.open("main.in");
	cin.rdbuf(fin.rdbuf());


	string tmp1, tmp2;
	while(cin >> n){
		start = 0;
		name_cnt = 1;
		memset(g, 0, sizeof(g));
	for(int i = 0; i < n; ++ i){
		cin >> tmp1;
		if(name.find(tmp1) == name.end()){
			name[tmp1] = name_cnt ++;
		}
		g[start][name[tmp1]] = 1;
	}
	cin >> m;
	dest = n + m + 1;
	for(int i = 0; i < m; ++ i){
		cin >> tmp1 >> tmp2;
		if(name.find(tmp1) == name.end()){
			name[tmp1] = name_cnt ++;
		}
		if(name.find(tmp2) == name.end()){
			name[tmp2] = name_cnt ++;
		}
		g[name[tmp2]][name[tmp1]] = 1;
		g[name[tmp1]][dest] = 1;
	}
	cin >> k;
	for(int i = 0; i < k; ++ i){
		cin >> tmp1 >> tmp2;
		if(name.find(tmp1) == name.end()){
			name[tmp1] = name_cnt ++;
		}
		if(name.find(tmp2) == name.end()){
			name[tmp2] = name_cnt ++;
		}
		g[name[tmp2]][name[tmp1]] = INF;
	}

	name_cnt += 1;
	ans = distance_label();
	cout << m - ans << endl;
	}
    return 0;
}
int distance_label()
{
	memset(path, -1, sizeof(path));

	bfs();

	int max_flow(0), u(start);
	while(d[start] < name_cnt){
		if(u == dest){
			int v = INF;
			for(u = dest; u != start; u = path[u])
				v = min(v, g[path[u]][u]);
			for(u = dest; u != start; u = path[u]){
				g[path[u]][u] -= v;
				g[u][path[u]] += v;
			}
			max_flow += v;
		}
		int p = find_allow(u);
		if(p >= 0){
			path[p] = u;
			u = p;
		}
		else{
			if(-- d_num[d[u]] == 0)
				return(max_flow);

			int v = relabel(u);
			d[u] = v;
			++ d_num[d[u]];
			if(u != start)
				u = path[u];
		}
	}
	return(max_flow);
}
int find_allow(int u)
{
	for(int i = 0; i < name_cnt; ++ i)
		if(g[u][i] > 0 && d[u] == d[i] + 1)
			return(i);
	return(-1);
}
int relabel(int u)
{
	int d_tmp(INF);
	for(int i = 0; i < name_cnt; ++ i)
		if(g[u][i] > 0)
			d_tmp = min(d_tmp, d[i] + 1);
	return(d_tmp);
}
void bfs()
{
	for(int i = 0; i < MAX; ++ i)
		d[i] = INF;
	memset(d_num, 0, sizeof(d_num));

	queue<int> q;
	q.push(dest);
	d[dest] = 0;
	d_num[0] = 1;
	while(!q.empty()){
		int p = q.front(); q.pop();
		for(int i = 0; i < name_cnt; ++ i)
			if(d[i] >= name_cnt && g[i][p] > 0){
				d[i] = d[p] + 1;
				q.push(i);
				++ d_num[d[i]];
			}
	}
}
