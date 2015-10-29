#ifndef WAY_TO_ALGORIHTM_DYNAMICPROGRAMMING_REGIONDYNAMIC_MAXIMUM_BINARY_TREE_MERGE_H
#define WAY_TO_ALGORIHTM_DYNAMICPROGRAMMING_REGIONDYNAMIC_MAXIMUM_BINARY_TREE_MERGE_H 1
//最大二叉树合并
//maximum binary tree merge

//一个n个节点的二叉树中序遍历为1 2 3 ... n 其中1到n为节点编号
//每个节点都有一个分数 而每个树有一个加分
//根结点分数 = 左子树分数 * 右子树分数 + 根节点自身分数
//若子树为空则规定其加分为1 以叶子节点为根节点的子树的加分等于其叶子节点的分数
//求二叉树的最高加分
//题目原型是加分二叉树

//本文将区域动规与二叉树两个问题结合起来
//设置数组s s[i]指代节点i的分数 若将节点i作为整个树的根节点
//则其左边的所有节点1到i-1 都是其左子树的节点 右边i+1到n都是右子树的节点
//这是中序遍历的特性 根节点总在所在的左右子树中间
//则对于最后一次选择根节点 需要遍历1到n所有节点 则可以做最后一次选择
//使得 树加分=左子树加分*右子树加分+根节点分数 最大
//设f[i][j]指代从i到j的节点组成的子树的最高加分
//状态转移方程: 
//f[i][j] = max(f[i][k-1] * f[k+1][j], f[i][j]) + s[k]
//其中k为该树的根节点 i到k-1是树的左子树 k+1到j是右子树根节点
//i <= k <= j k从i到j枚举所有情况 s[k]为k节点的分数
//数组s[i]指代节点i的分数 将节点i作为整个树的根节点
//则其左边的所有节点1到i-1 都是其左子树的节点 右边i+1到n都是右子树的节点
//这是中序遍历的特性 根节点总在所在的左右子树中间
//则对于最后一次选择根节点 需要遍历1到n所有节点 则可以做最后一次选择
//使得 树分数=左子树分数*右子树分数+根节点自身分数 最大
//设f[i][j]指代从i到j的节点组成的子树的最高加分
//状态转移方程:
//f[i][j] = max( f[i][k-1] * f[k+1][j]  f[i][j] ) + s[k]
//其中k为该树的根节点 i到k-1是树的左子树 k+1到j是右子树根节点
//i<=k<=j k从i到j枚举所有情况 s[k]为k节点的分数
//初始条件: f[i][j]所有子树加分初始化为1 f[i][i]为节点i的分数


#include <algorithm>
using std::max;
#ifndef MAX
#define MAX 60
#endif

int maximum_binary_tree_merge(int *s, int n)
{//序列s的数量为n 下标从1到n s[i]指代节点i的分数 返回最大加分
	int f[MAX + 1][MAX + 1];
	//初始化
	//循环时 选择1和n作为根节点时 1的左子树为0 n的右子树为n+1
	//这两个空子树的加分均为1
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			f[i][j] = 1;
	for (int i = 1; i <= n; ++i)
		f[i][i] = s[i];
	for (int len = 1; len <= n; ++len)
		//特别之处在于最外面一层循环
		//len指代i到j之间的距离
		for (int i = 1; i < n; ++i) {
			//i为遍历f的左边界
			int j = i + len;
			//j为遍历f的右边界
			if (j <= n)
				//当j>n以后就可以break跳过了
				for (int k = i; k <= j; ++k)
					f[i][j] = max(f[i][j],
							f[i][k - 1] * f[k + 1][j] + s[k]);
		}
	return(f[1][n]);
}

#endif
