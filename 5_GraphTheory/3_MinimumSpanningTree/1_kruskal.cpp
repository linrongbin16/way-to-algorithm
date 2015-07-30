//Kruskal算法
//kruskal

//用Kruskal算法求连通图的最小生成树

//最小生成树是图G的一条无回路 使所有顶点连接且边的权值之和最小的路径
//该算法是贪心算法的应用
//将图G中的边集按照权值由小到大依次遍历
//对于每条边 若加入生成树中不会使树出现回路 则加入 否则跳过
//该算法中应用了并查集的思路(详见本书第3章数据结构中并查集)
//判断一条边加入生成树中是否会使生成树出现回路 并不是在已选的边中判断回路
//而是判断边的两节点是否已经属于同一个集合
//即生成树的节点属于一个家族 而不是生成树的节点属于另一个家族


#include "general_head.h"
#include "graph.h"
//tarjan_least_common_ancestors.cpp
extern tree_node* make_disjoint();
//tarjan_least_common_ancestors.cpp
extern tree_node* find_father(tree_node *p);
bool compare(edge a, edge b);

void kruskal(edge_list& e)
{//边集e有e_l.size()条边 下标从0到e_l.size()-1
 //直接操作edge中成员e_join来标记该边是否加入生成树
	tree_node* tree =  make_disjoint();
	//算法的关键在于并查集的应用: 
	//将图中的点列为一个tree_node序列 每个点初始时父节点都是自己
	//从已排序的边集中每次取出最小权值边 考察他的两端点
	//在tree_node序列中找出该节点的父节点 若两父节点不相同 即两点不在同一树中
	//则将两节点中一个的父节点改为另一节点的父节点 即把两个节点放在同一生成树中
	//并把此边加入edge中 最终可以返回edge指向的边集和tree指向的节点序列
	//tree已经是生成最小生成树
	sort(e.e_l.begin(), e.e_l.end(), compare);
	for(int i = 0; i < (int)e.e_l.size(); ++ i){
		//find_father是并查集中判断父节点的操作
		tree_node *pf1 = find_father(&tree[e.e_l[i].e_beg]);
		tree_node *pf2 = find_father(&tree[e.e_l[i].e_end]);
		if(pf1->t_idx != pf2->t_idx){
			//判断根节点是否一样 即判断是否属于同一集合
			//在e中标记该边 加入生成树中
			e.e_l[i].e_join = 1;
			for(int j = 0; j < (int)e.e_l.size(); ++ j)
				//检查所有节点 将属于pf2集合的节点改为pf1集合
				//即将节点加入生成树集合中
				if(tree[j].t_idx == pf2->t_idx)
					tree[j].t_fa = pf1;
		}
	}
}
bool compare(edge a, edge b)
{
	return(a.e_value < b.e_value);
}
