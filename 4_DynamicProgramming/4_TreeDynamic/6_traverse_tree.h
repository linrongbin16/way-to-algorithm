#ifndef WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_TRAVERSE_TREE_H
#define WAY_TO_ALGORITHM_DYNAMICPROGRAMMING_TREEDYNAMIC_TRAVERSE_TREE_H 1
//树遍历动规
//traverse tree

//在多叉树上 每个节点都具有一个权值
//从一个节点到另一个节点 只存在唯一一条路线
//假设每个节点都是一个牧场 节点中有一只奶牛 这个权值就是奶牛的价值
//这些奶牛可能会离开自己的牧场 跑到其他节点
//奶牛离自己节点的距离有一个最大值level 它们不会走到离level更远的节点
//求出每个节点上可能拥有的最大权值(所有可能到这个节点的奶牛的价值之和)
//原题目是游荡的奶牛

//最直觉的方法是: 对于每个节点可以进行一次限制步数为level的bfs遍历
//并且累加访问到的所有节点的权值 其和即为该节点的最大权值
//但在题目中该方法只能通过一部分测试用例 它太慢了
//
//动态规划方法:
//1)我们现在考虑这样的树:            1
//                           /          \
//                     2                      3
//                  /     \                /     \
//               4           5          6           7
//             /   \       /   \       /   \      /   \
//            8     9    10    11    12    13    14    15
//           / \   / \   / \   / \   / \   / \   / \   / \
//          16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
//
//对于节点5 假设它的奶牛能游荡的最大距离level是2 那么节点5:
//向下游荡 可以访问10 11 20 21 22 23节点
//向上游荡 可以访问2 1 4节点
//则对于节点5的最大权值即为向上和向下能到达的节点的权值之和再加自己的权值
//
//通过这样直观的了解 我们可以得到结论: 
//对于多叉树树中某个节点i
//向下游荡 可以到达以自己为根节点的level层子树的所有节点
//向上游荡的情况比较复杂 下面单独考虑这个问题
//
//2)向上游荡:
//考虑对于一个多叉树某节点i 游荡距离为level
//节点i向上最远可以到达比它高level层的祖父节点
//假设节点i所在层为level层 它能到达的最高层祖父节点所在层为 0 层
//当节点i向上1层到达父节点 再向下1层可以到达它的兄弟节点
//这时它的剩余步数是level-2
//例如图中节点5向上1层到达2再向下1层到达它的兄弟节点4
//这时它的剩余步数是level-2它可以到达兄弟节点4 向下level-2层的所有子树节点
//则节点i向上k层 可以到达它的k祖父节点的level-k层所有子树节点
//其中0<=k<=level
//节点i的最大权值 就是向上 向下所能到达的所有节点的权值之和再加自己的权值
//
//3)通过上面的分析已经知道每个节点的权值如何计算
//那么现在来确定动态规划的实现方法
//
//(i)假设根节点为第0层 向下的层数每次增1
//对于每个节点i都可以得到它的孩子们的权值之和 即下1层的子树的权值之和
//想要得到节点i下level层子树的节点权值之和 可以从下向上动态规划: 
//设fdown[i][j]指代节点i向下j层所到达的所有节点的权值之和 不包括自己的权值
//fdown[i][1]指代节点i向下1层的权值之和
//即为节点i的所有孩子节点的权值之和(向下第1层子树节点)但不包括节点i自己的权值
//fdown[i][level]即为节点i向下所能到达的所有节点的权值之和
//即向下游荡的最大权值
//
//fdown的状态转移方程: 
//fdown[i][j] = sum(fdown[k][j-1] + v[k])
//节点i的向下j层的最大权值
//等于它的所有孩子节点k的向下j-1层的最大权值之和 再加k自己的权值v[k]
//其中k枚举节点i的所有孩子节点
//其中j枚举所有层数1<=j<=level
//
//(ii)再次遍历这棵树 对于每个节点 向上考虑它从第1层到第level层的祖父节点
//对于节点i向上第k层的祖父节点
//节点i可以到达这个祖父节点的向下level-k层所有子树节点
//对于每个祖父节点的向下的权值 之前第1遍的动态规划已经解决了
//节点i的向上所能到达的所有节点权值之和就是所有向上第k层祖父节点
//的向下level-k层的最大权值之和(从向上第1层累加到第level层)
//需要注意的问题是: 只选取这些祖父节点的兄弟分支 要除掉自己的分支
//设fup[i][j]指代节点i向上第j层的那个祖父节点的所有孩子节点(除过自己这一分支)
//的向下level-j-1层的权值之和(所有孩子节点的权值之和)
//它与fdown的意义是不同的 fdown[i][j]指代从第1层到第j层的向下权值之和
//
//(iii)最后我们再次遍历一次这棵树
//这时每个节点向上向下的所有节点的最大权值都已知
//每个节点的最大权值即为向上最大权值+向下最大权值+自己的权值
//选出最大权值的那个节点输出即可

#include "general_head.h"
#include "tree_dynamic.h"
void traverse_down(tree_node *r, int **fdown, int level);
void traverse_up(tree_node *r, int **fdown, int **fup, int level);
void get_father(tree_node *r, tree_node *p,
		int **fdown, int **fup, int level, int prev);
int traverse_max(tree_node *r, int **fdown, int **fup, int level);

int traverse_tree(tree_node *r, int **fdown, int **fup, int level)
{//fdown[i][j]指代从第1层到第j层的向下权值之和
 //fup[i][j]指代节点i向上第j层的最大权值 与fdown的意义是不同的
 //fup[i][j]只指代第j层的权值之和
 //fdown和fup初始化均为0
	traverse_down(r, fdown, level);
	traverse_up(r, fdown, fup, level);
	return(traverse_max(r, fdown, fup, level));
}
void traverse_down(tree_node *r, int **fdown, int level)
{//从底向上递归的寻找树中每个节点的向下最大权值
 //这个递归是向下level层的递归
	//递归终止条件
	//若当前节点r是叶子节点
	if(r->t_cnt == 0){
		//如果r节点的孩子节点数量t_cnt为0 它是叶子节点
		for(int i = 1; i <= level; ++i)
			//它的向下从第1层到第level层的最大权值都是0
			fdown[r->t_idx][i] = 0;
		return;
	}

	//如果r节点既不是叶子节点
	//它的孩子节点也没有得到各自的向下最大权值
	for(int i = 0; i < r->t_cnt; ++i)
		//继续遍历它的所有孩子节点i
		traverse_down(r->t_child[i], fdown, level);
	//遍历之后得到r的所有孩子节点的向下权值 再计算r的向下权值
	for(int i = 1; i <= level; ++i){
		fdown[r->t_idx][i] = 0;
		for(int j = 0; j < r->t_cnt; ++j)
			fdown[r->t_idx][i] += fdown[r->t_child[j]->t_idx][i - 1] +
				r->t_child[j]->t_value;
	}
}
void traverse_up(tree_node *r, int **fdown, int **fup, int level)
{//用先序遍历树的方法遍历每个节点找出其向上的最大权值
 //实际竞赛题目中 使用最简单的数组与下标来构建树 则也可以使用bfs
	if(r != NULL){
		get_father(r, r, fdown, fup, level, 1);
		for(int i = 0; i < r->t_cnt; ++i)
			traverse_up(r->t_child[i], fdown, fup, level);
	}
}
void get_father(tree_node *r, tree_node *p,
		int **fdown, int **fup, int level, int prev = 1)
{//递归的向上求出r到达 p 祖父节点那一层的最大权值
 //p指代r向上第 prev-1 层的祖父节点
 //prev == 1时 p即为r自己 p->t_fa为r的父节点
 //prev > level时 已经超越了向上的最大层数level
	//递归终止条件
	//若p的父节点为空指针 即p已经为根节点
	if(p->t_fa == NULL)
		return;
	//prev > level是递归结束条件
	if(prev > level)
		return;

	if(prev == level){
		//到达最高的祖父节点时 不访问孩子子树
		fup[r->t_idx][prev] = p->t_fa->t_value;
	}
	else{
		//其他祖父节点可以到达其孩子子树
		for(int i = 0; i < p->t_fa->t_cnt; ++i)
			//遍历p点的父节点的所有孩子节点 除过自己
			//即遍历p点的所有兄弟节点
			if(p->t_fa->t_child[i] != p){
				//累加父节点的向下权值时要除去p自己这一子树的分支
				//r节点向上prev层的最大权值等于
				//上面prev层的祖父节点的所有孩子节点的向下 level-prev-1 层的最大权值
				//再加上孩子节点自己的权值
				fup[r->t_idx][prev] +=
					fdown[p->t_fa->t_child[i]->t_idx][level - prev - 1];
				fup[r->t_idx][prev] += p->t_fa->t_child[i]->t_value;
			}
		//还要加上p的父节点的权值
		fup[r->t_idx][prev] += p->t_fa->t_value;
	}
	//递归上一层父节点
	get_father(r, p->t_fa, fdown, fup, level, prev + 1);
}
int traverse_max(tree_node *r, int **fdown, int **fup, int level)
{//第三次遍历寻找多叉树中最大权值的点 返回该点权值
	//递归终止条件 空节点的权值为0
	if(r == NULL)
		return(0);

	int fmax(0);
	//fup[i][j]指代节点i向上第j层的那个祖父节点的所有孩子节点(除过自己这一分支)
	//的向下 level-j-1 层的权值之和(所有孩子节点的权值之和)
	//与fdown的意义是不同的 fdown[i][j]指代从第1层到第j层的向下权值之和
	//r点的最大权值等于所有向下节点的权值之和
	fmax += fdown[r->t_idx][level];
	//再加所有向上节点的权值之和
	for(int i = 1; i <= level; ++i)
		fmax += fup[r->t_idx][i];
	//再加自己的权值
	fmax += r->t_value;

	//再和所有其他的节点进行比较 选出最大的返回
	for (int i = 0; i < r->t_cnt; ++i)
		fmax = max(fmax, traverse_max(r->t_child[i], fdown, fup, level));
	return(fmax);
}


#endif
