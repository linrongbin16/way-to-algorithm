#ifndef SEARCH_DEPTH_FIRST_SEARCH_H
#define SEARCH_DEPTH_FIRST_SEARCH_H 1
//深度优先搜索
//depth first search

//使用深度优先搜索寻找序列s的所有组合

//深搜与暴力枚举都是解决排列组合问题的算法
//但是暴力枚举代码中循环的次数是固定的 扩展性差
//而深度搜索通过使用递归技术可以对此进行扩展
//深度优先搜索的递归式具有明显的结构特点
//1)一般参数中都有prev参数来指明当前递归式处理的成员号
//2)递归式中第一部分处理终止递归
//当所有成员都作出了一次选择 即得到一种当前排列组合
//也可以进行剪枝 提前结束当前节点的子空间的搜索
//3)递归式中第二部分中递归达到第prev个成员
//这时prev之前的成员已做出选择 而prev以及它之后的成员尚未选择
//prev作出它的其中一种选择并进入下一个成员的递归


#ifndef MAX
#define MAX 60
#endif
#include <iostream>
using namespace std;

void depth_print(int s[MAX], int beg, int end)
{
    for (int i = beg; i < end; ++i)
        cout << s[i] << " ";
    cout << endl;
}

void depth_first_search(int s[MAX], int n, int m, int prev/*default=0*/)
{
    //序列s拥有n个成员 下标从0到n-1 每个成员有m种选择
	//深度搜索一般都以prev=0开头 这是一个特点
	//prev指代当前正在做出选择的成员号
	//1)第一部分 递归终止条件
	if(prev == n){
		//从0到n-1的每个成员都做出了选择 组成一个排列组合
		//输出当前排列组合 结束递归返回上层
		depth_print(s, 0, n);
		//在多数题目中还需要对结果进行剪枝
        //即去除明显已经不需要继续递归搜索的情况
		return;
	}

	//2)第二部分 处理当前成员prev 他有m种选择
	//循环遍历prev的每一种选择
	for(int i = 0; i < m; ++ i){
		//s[prev]=i即为成员s[prev]的一种选择
		s[prev] = i;
		//当前成员prev做出选择后递归进入下一个成员
		depth_first_search(s, n, m, prev + 1);
	}
	//递归式实现的深搜中 每个递归式都是对一个成员的遍历
	//通过递归将n个成员连成链 每个递归式中都完成对当前成员的所有选择的遍历
	//在第n层递归 判断这n个成员作出的选择的组合是否满足所求
	//n个成员m种选择 所有排列组合的可能有m^n种
	//也可以将递归看做对一棵高度为n+1的m叉的完全树进行中序遍历的过程
}


#endif
