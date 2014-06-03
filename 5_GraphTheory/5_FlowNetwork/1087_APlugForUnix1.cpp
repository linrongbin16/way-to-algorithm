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

const int maxn = 30000;
const int maxm = 50000;
const int INF=0x7fffffff;
int idx;
int cur[maxn], path[maxn];
int d[maxn], d_num[maxn];
int aug[maxn], head[maxn];
char name[3000][30];
int k;
struct Node
{
	int u, v, w;
	int next;
};
Node edge[maxm];
int relabel(int index);
int find_allow(int index);
void addEdge(int u, int v, int w)
{
    edge[idx].u = u;
    edge[idx].v = v;
    edge[idx].w = w;
    edge[idx].next = head[u];
    head[u] = idx++;
    edge[idx].u = v;
    edge[idx].v = u;
    edge[idx].w = 0;
    edge[idx].next = head[v];
    head[v] = idx++;
}
int sol(char *str)
{
	int i;
	if(k==0)
	{
		strcpy(name[1],str);
		k=1;
		return  1;
	}
	for(i=1;i<=k;i++)
		if(strcmp(name[i],str)==0)
			return i;
	k++;
	strcpy(name[k],str);
	return k;
}
int SAP(int s, int e, int n)
{
    int max_flow = 0, v, u = s;
    int id, min_dist;
    aug[s] = INF;
    path[s] = -1;
    memset(d, 0, sizeof(d));
    memset(d_num, 0, sizeof(d_num));
    d_num[0] = n; // 我觉得这一句要不要都行，因为d[e]始终为0
	copy(head, head + maxn, cur); // 初始化当前弧为第一条弧
    while (d[s] < n)
    {
        if (u == e)
        {
            max_flow += aug[e];
            for (v = path[e]; v != -1; v = path[v]) // 路径回溯更新残留网络
            {
                id = cur[v];
                edge[id].w -= aug[e];
                edge[id^1].w += aug[e];
                aug[v] -= aug[e]; // 修改可增广量，以后会用到
                if (edge[id].w == 0) u = v; // 不回退到源点，仅回退到容量为0的弧的弧尾
            }
        }
		int tmp = find_allow(u);
		if(tmp != -1)
			u = tmp;
		else{
            if (--d_num[d[u]] == 0)
				break; /* gap优化，层次树出现断层则结束算法 */
            min_dist = n;
            cur[u] = head[u];
            d[u] = relabel(u) + 1;
            ++ d_num[d[u]];
            if (u != s)
				u = path[u]; // 回溯继续寻找允许弧
        }
    }
    return max_flow;
}
int main()
{
	freopen("main.in", "r", stdin);

    int i,n1,n2,n3;
	int st,ed;
	int a,b;
	char str1[30],str2[30];
    while(scanf("%d",&n1)!=EOF)
    {
		idx = 0;
        memset(head, -1, sizeof(head));
        st=0;
		k=0;
        for(i=1;i<=n1;i++)
		{
			scanf("%s",str1);
			a=sol(str1);
			addEdge(st,a,1);  //源点向插座建边
		}
		scanf("%d",&n2);
		ed=n1+n2+1;
		for(i=1;i<=n2;i++)
		{
			scanf("%s %s",str1,str2);
			a=sol(str1);
			b=sol(str2);  
			addEdge(b,a,1);   //插座向电器建立边
			addEdge(a,ed,1);  //电器向汇点建边
		}
		scanf("%d",&n3);
		for(i=1;i<=n3;i++)
		{
			scanf("%s %s",str1,str2);
			a=sol(str1);
			b=sol(str2);
			addEdge(b,a,INF);
		}
        printf("%d\n",n2 - SAP(st, ed, k+2));
    }
    return 0;
}
int find_allow(int index)
{
	for(int i = cur[index]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if(edge[i].w > 0 && d[index] == d[v] + 1){
			path[v] = index;
			cur[index] = i;
			aug[v] = min(aug[index], edge[i].w);
			return(v);
		}
	}
	return(-1);
}
int relabel(int index)
{
	int min_dist(k + 2);
	for (int i = head[index]; i != -1; i = edge[i].next){
		int v = edge[i].v;
		if (edge[i].w > 0 && d[v] < min_dist)
		{
			min_dist = d[v];
			cur[index] = i; // 修改标号的同时修改当前弧
		}
	}
	return(min_dist);
}
