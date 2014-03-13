//最近公共祖先
//least_common_ancestors.cpp

//求有向无环图中两节点的最近公共祖先

//有向无环图其实是可以有任意数量孩子节点的树
//设该图中两节点u和v，若u和v属于同一颗树，它们有多个公共祖先
//但深度最深(树中)，或者到u和v距离之和最小的祖先是最近公共祖先
//
//原始的方法可以通过从根节点开始dfs遍历整个树，标记出每个节点的深度
//再通过dfs从节点u和v中一个遍历到另一个，从而找出u和v的最近公共祖先
//但每次查询一对这样的节点u和v就需要dfs遍历树，时间复杂度过高
//
//而Tarjan算法预先读取所有需要查询的节点对
//然后通过一次dfs遍历即可找出所有节点对的最近公共祖先
//也将遇到一次查询就dfs遍历一次的算法称为在线算法
//而将一次读取所有查询，遍历后一次返回所有结果的算法称为离线算法
//
//Tarjan算法的核心思路在于通过并查集在dfs遍历的过程中一次找出所有节点对的最近公共祖先
//dfs遍历树的过程也可以看作一次先序遍历
//对于每个节点都是先考查该节点然后考察其所有孩子节点
//初始时设置并查集中所有节点的父节点是它自己
//从根节点开始递归的遍历该树中的所有节点
//对于当前节点p，将p的所有孩子节点的父节点都设置为p节点的父节点
//再考察所有与节点p相关联的查询，若该查询的节点对除了p的中另一个节点v已被访问
//则将p和v的最近公共祖先设置为节点v在并查集中的父节点
//并查集的性质可以参考本书第2章并查集

#include "general_head.h"
#include "graph.h"
//strongest_connected_component.cpp
extern void set_value(graph_list& g);
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
	visited[p] = 1;
	//进行下一轮dfs遍历，并更新并查集
	for(int i = 1; i < (int)g.g_l[p].size(); ++ i){
		dfs_lca(g, g.g_l[p][i].g_idx, query, visited, tree);
		//将p节点和它的孩子节点i.g_idx合并
		tree_node *pf1 = find_father(&tree[p]);
		tree_node *pf2 = find_father(&tree[g.g_l[p][i].g_idx]);
		//将孩子节点i.g_idx的父节点指针设置为p节点
		pf2->t_fa = pf1;
	}
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



