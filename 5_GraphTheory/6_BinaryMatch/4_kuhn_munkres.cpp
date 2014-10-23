//Kuhn-Munkres算法
//kuhn_munkres.cpp

//二分图B中的每条边都拥有一个正权值，为了方便该权值为正整数
//求二分带权图的具有最大权的完备匹配(也称最优匹配，最佳匹配)

//1)基础概念
//二分带权图的最大权完备匹配问题是应用Kuhn-Munkres(简称KM)算法的典型场景
//顶点标号技术：
//对于二分图B=<X,Y,E>的X集合中节点设置顶点标号A，Y集合中节点设置顶点标号B
//即设置数组a_label和b_label，a_label[i](b_label[i])指代X(Y)集合中节点i的标号
//可行顶点标号：
//对于二分图B中的每条边e，一个端点i属于X集合，另一个端点j属于Y集合
//标号都满足a_label[i] + b_label[j] >= value(e)
//保证可行顶点标号总是存在的，设置一种平凡可行标号：
//即设置X集合中每个节点i，其标号a_label[i]是节点i的所有邻边中权值最大的边的权值
//而Y集合中所有节点的标号b_label值都设置为0
//等价子图，相等子图：
//二分图B的顶点标号中满足a_label[i]+b_label[j]=value(e)的边所组成的边集
//该边集的生成子图即为图B的相等子图
//需要注意：相等子图的节点集与原图B的节点集是相同的，即相等子图没有比原图B减少节点
//相等子图定理：
//若二分图B的相等子图有完备匹配M，则M是二分图B的最大全完备匹配
//
//由相等子图定理可知，欲求二分图的最大权完备匹配，只需求某个相等子图的完备匹配即可
//而完备匹配可以使用匈牙利算法求得
//Kuhn-Munkres算法使用一个方法对标号进行修改，使得新的相等子图的最大匹配逐渐扩大
//最终得到有完备匹配的相等子图，即求得最大全完备匹配
//当二分带权图中所有边的权值都是1时，该问题退化为二分完备匹配问题
//
//2)具体实现
//设置数组a_label为X集合中的节点标号，数组b_label为Y集合中的节点标号
//初始时设置X中节点标号a_laebl为其所有邻边中最大的权值，Y中标号都为0
//对X中每个节点i重复以下步骤：
//用匈牙利算法中dfs遍历的方法求当前标号下的等价子图B'的最大匹配
//在遍历过程中，如果从节点i出发的dfs找不到增广轨
//则从该节点出发的增广轨不存在完备匹配，按照以下方法对节点i出发的增广轨进行修改：
//找到改进量d=min(A[i]+B[j]-value(e))，其中节点i属于a_label，节点j不属于b_label
//然后改进节点的标号：A[i]=A[i]-d，B[j]=B[j]-d，其中i属于a_label，j属于b_label
//然后继续进行匈牙利算法，直到求出完备匹配为止
//
//该算法是二分图中最为难懂的算法，网上主要有两篇文档即本文最后列出的两篇
//
//3)补注
//本文的代码中有一处判断条件与文档“带权二分图的最优匹配 Kuhn-Munkres算法(转)”不一致
//我在实际测试时发现原文档的代码由于缺少一处判断条件而得到错误答案
//在本文的代码中进行了修正
//
//本文引用了“带权二分图的最优匹配 Kuhn-Munkres算法(转)”，作者“yulin11”
//“Kuhn-Munkres算法(NOCOW)”，作者“Maigo”
//“图论讲义 第3章(匹配问题)”，作者“高随祥”

#include "general_head.h"
#include "graph.h"
void construct_s(bipartite b, int *a_label, int *b_label);
int dfs_path(bipartite b, int *visit_x, int *visit_y, int p,
		int *ymatch, int *a_label, int *b_label);

int kuhn_munkres(bipartite b, int *ymatch)
{//二分图B存在完备匹配，故它的X和Y集合节点数量相同
 //X集合有b_xn个节点，下标从0到b_xn-1，Y集合有b_yn个节点，下标从0到b_yn-1
 //b_g[i][j]指代节点i和节点j之间的边的权值，其中节点i属于X集合，节点j属于Y集合
	memset(ymatch, -1, MAX * sizeof(int));
	//数组a_label和b_label为节点标号
	//数组visit_x(visit_y)标记X(Y)集合中节点是否被访问过
	int a_label[MAX], b_label[MAX], visit_x[MAX], visit_y[MAX];
	//初始化节点标号数组a_label和b_label
	//X集合中每个节点i的标号初始化为其所有邻边中最大的权值，Y集合中所有节点i标号为0
	//从而保证对于每条边e都有A[i]+B[i]>=value(e)
	construct_s(b, a_label, b_label);
	for(int i = 0; i < b.b_xn; ++ i)
		while(1){
			memset(visit_x, 0, MAX * sizeof(int));
			memset(visit_y, 0, MAX * sizeof(int));
			if(dfs_path(b, visit_x, visit_y, i, ymatch, a_label, b_label))
				break;

			int tmp_label(INF);
			for(int j = 0; j < b.b_xn; ++ j)
				if(visit_x[j])
					for(int k = 0; k < b.b_yn; ++ k)
						if(!visit_y[k])
							tmp_label = min(tmp_label,
									a_label[j] + b_label[k] - b.b_g[j][k]);
			for(int j = 0; j < b.b_xn; ++ j){
				if(visit_x[j])
					a_label[j] -= tmp_label;
				if(visit_y[j])
					b_label[j] += tmp_label;
			}
		}
	int max_match(0);
	for(int i = 0; i < b.b_yn; ++ i)
		max_match += b.b_g[ymatch[i]][i];
	return(max_match);
}
void construct_s(bipartite b, int *a_label, int *b_label)
{
	memset(a_label, 0, MAX * sizeof(int));
	memset(b_label, 0, MAX * sizeof(int));
	for(int i = 0; i < b.b_xn; ++ i)
		for(int j = 0; j < b.b_yn; ++ j)
			a_label[i] = max(a_label[i], b.b_g[i][j]);
}
int dfs_path(bipartite b, int *visit_x, int *visit_y, int p,
		int *ymatch, int *a_label, int *b_label)
{
	visit_x[p] = 1;
	for(int i = 0; i < b.b_yn; ++ i)
		if(!visit_y[i] && b.b_g[p][i] &&
				a_label[p] + b_label[i] == b.b_g[p][i]){
			//“带权二分图的最优匹配 Kuhn-Munkres算法(转)”中缺少的判断条件是
			//b.b_g[p][i]这一句，即判断节点p与节点i之间存在边
			//本文之前的若干二分图算法的代码中都有这个判断，此处应该是原作者的失误
			visit_y[i] = 1;
			if(ymatch[i] == -1 ||
					dfs_path(b, visit_x, visit_y, ymatch[i],
						ymatch, a_label, b_label)){
				ymatch[i] = p;
				return(1);
			}
		}
	return(0);
}
