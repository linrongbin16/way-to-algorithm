//最近公共祖先
//least_common_ancestors.cpp

//求一棵树中两节点的最近公共祖先

//一棵有任意多孩子节点的树其实是一个有向无环图
//考虑一棵树中两节点u和v，假设它们有多个公共祖先
//但树中深度最深(即离根节点距离最远)，或者说到u和v距离之和最小的那个祖先节点
//称为u和v的最近公共祖先
//
//原始的方法可以通过从根节点开始dfs遍历整个树，标记出每个节点的深度
//再通过dfs从节点u和v中一个遍历到另一个，从而找出u和v的最近公共祖先
//但每次查询一对这样的节点u和v就需要dfs遍历树，时间复杂度过高
//将这样遇到一次查询就计算一次，然后返回结果的算法称为在线算法
//
//将Tarjan算法应用在树中可以解决最近公共祖先问题
//通过一次dfs遍历即可找出所有节点对的最近公共祖先
//将这样一次读取所有查询，计算一次后返回所有查询结果的算法称为离线算法
//涉及到在线算法和离线算法这两个概念的算法还有区域最值查询问题(RMQ问题详见第3章第1节)
//
//在最近公共祖先问题上，Tarjan算法与本节前几篇文档有些不同之处
//本问题中Tarjan算法不需要设置栈和dfn，low标号，而是设置了并查集
//该算法通过设置并查集(详见第2章数据结构)来求解所有查询节点对的最近公共祖先
//树的先序遍历也转变为图G中的dfs遍历
//并查集中所有节点的父节点初始化为它自己，即每个节点自己是一个单独的集合
//从树的根节点开始递归的dfs遍历树
//当遍历到节点p时，将p的所有孩子节点的父节点都设置为p节点的父节点
//再考察所有与节点p相关联的查询，若该查询的节点对中除了p的另一个节点v已被访问
//则将p和v的最近公共祖先设置为节点v在并查集中的父节点

#include "general_head.h"
#include "graph.h"
void dfs_lca(graph_list g, int p, map<pair<int, int>, int>& query,
		int *visited, tree_node *tree);
tree_node* make_disjoint();
tree_node* find_father(tree_node *p);

void least_common_ancestors(graph_list g, map<pair<int, int>, int>& query)
{//有向无环图G有g_l.size()个节点，下标从0到g_l.size()-1
 //返回query节点对的最近公共祖先，存储于pair对应的位置中
	int visited[MAX];
	memset(visited, 0, MAX * sizeof(int));
	//用树节点实作并查集
	tree_node* tree = make_disjoint();
	for(int i = 0; i < (int)g.g_l.size(); ++ i)
		if(!visited[i])
			dfs_lca(g, i, query, visited, tree);
}
void dfs_lca(graph_list g, int p, map<pair<int, int>, int>& query,
		int *visited, tree_node *tree)
{
	//进行下一轮dfs遍历，并更新并查集
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		dfs_lca(g, g.g_l[p][i].g_idx, query, visited, tree);
		//将p节点和它的孩子节点i.g_idx合并
		tree_node *pf1 = find_father(&tree[p]);
		tree_node *pf2 = find_father(&tree[g.g_l[p][i].g_idx]);
		//将孩子节点i.g_idx的父节点指针设置为p节点的父节点
		pf2->t_fa = pf1;
	}
	visited[p] = 1;
	//用并查集进行查询
	for(map<pair<int, int>, int>::iterator it = query.begin();
			it != query.end(); ++ it){
		//查询所有与节点p相关的节点对
		if(p == it->first.first && visited[it->first.second]){
			//若有与节点p相关的查询，且另一个节点second已被访问
			tree_node *fa = find_father(&tree[it->first.second]);
			//则节点p与另一个节点second的最近公共祖先是second的并查集父节点
			it->second = fa->t_idx;
		}
		if(p == it->first.second && visited[it->first.first]){
			tree_node *fa = find_father(&tree[it->first.first]);
			it->second = fa->t_idx;
		}
	}
}
tree_node* make_disjoint()
{//生成并查集，用树节点实作
	tree_node *tree = new tree_node[MAX];
	for(int i = 0; i < MAX; ++ i)
		//t_idx指代该节点的下标，所有节点的父节点初始化为自己
		tree[i].t_idx = i, tree[i].t_fa = &tree[i];
	return(tree);
}
tree_node* find_father(tree_node *p)
{
	if(p->t_fa != p)
		p->t_fa = find_father(p->t_fa);
	return(p->t_fa);
}
