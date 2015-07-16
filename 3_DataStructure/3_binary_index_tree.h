#ifndef DATASTRUCTURE_BINARY_INDEX_TREE_H
#define DATASTRUCTURE_BINARY_INDEX_TREE_H 1
//树状数组
//binary index tree

//求数组s的所有成员的和

//求数组s的所有成员之和的原始方法是累加该范围中的每个成员
//有n个成员的数组s的时间复杂度是O(N)
//也可以使用线段树来解决该问题，但更适合的是树状数组，可以将时间复杂度降到O(lgN)
//
//设置辅助数组c来实现树状数组数据结构
//应用树状数组的特殊条件是数组s和c的下标必须从1开始
//树状数组中每个节点为c[i]
//并且满足c[i]=s[i-2^k+1]+s[i-2^k+2]+...+s[i]
//其中k是i在二进制形式下末尾的0的个数且i>=1
//用二进制的位运算可以轻松的得到2^k=i&(-i)
//
//比如i=0010,1100,1000末尾有3个0 则k=3
//比如i从1到8时
//i=1 k=0 2^k=1
//i=2 k=1 2^k=2
//i=3 k=0 2^k=1
//i=4 k=2 2^k=4
//i=5 k=0 2^k=1
//i=6 k=1 2^k=2
//i=7 k=0 2^k=1
//i=8 k=3 2^k=8
//i=9 k=0 2^k=1
//i=10 k=1 2^k=2
//i=11 k=0 2^k=1
//i=12 k=2 2^k=4
//i=13 k=0 2^k=1
//i=14 k=1 2^k=2
//i=15 k=0 2^k=1
//i=16 k=4 2^k=16
//则树状数组中的数组c和s有如下的对应关系
//c[1]=s[1]
//c[2]=s[1]+s[2]
//c[3]=s[3]
//c[4]=s[1]+s[2]+s[3]+s[4]
//c[5]=s[5]
//c[6]=s[5]+s[6]
//c[7]=s[7]
//c[8]=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]
//c[9]=s[9]
//c[10]=s[9]+ s[10]
//c[11]=s[11]
//c[12]=s[9]+s[10]+s[11]+s[12]
//c[13]=s[13]
//c[14]=s[13]+s[14]
//c[15]=s[15]
//c[16]=s[1]+s[2]+s[3]+s[4]+s[5]+s[6]+s[7]+s[8]+s[9]+s[10]+s[11]+s[12]+s[13]+s[14]+s[15]+s[16]
//
//计算数组s中从1到n所有成员之和或者改变某个成员的值时
//利用数组c和s在i和k上的对应关系可以很快的计算


#include <cstring>
#ifndef MAX
#define MAX 60
#endif
struct binary_index_tree
{
	//数组c下标从1开始
	int m_table[MAX];
};

int binary_index_tree_lowbit(int i)
{
	//计算2^k = i & (-i)
	return(i & (-i));
}
void binary_index_tree_init(binary_index_tree *tree)
{
	memset(tree->m_table, 0, MAX * sizeof(int));
}
void binary_index_tree_add(binary_index_tree *tree, int i, int value)
{//s[i]加value，其中下标i从1开始
	while(i < MAX){
		//比如当i=1时，因为c[1]=s[1]故c[1]加value
		//lowbit(1)=1 i=2 又c[2]=s[1]+s[2] c[2]中包含s[1]，因此c[2]加value
		//lowbit(2)=2 i=4 又c[4]=s[1]+s[2]+s[3]+s[4] 因此c[4]加value
		//lowbit(4)=4 i=8 又c[8]中包含s[1] 因此c[8]加value 以此类推
        //可以看出数组c用于快速记录数组s中某一段的和
        //最终计算数组s中从1到x的和时利用数组c中的值可以进行快速计算
		tree->m_table[i] += value;
		i += binary_index_tree_lowbit(i);
	}
}
int binary_index_tree_sum(binary_index_tree *tree, int x)
{//计算数组s中从1到x的和
	//与加操作类似，避免了遍历从1到x的累加，从而降低时间复杂度
	int sum(0);
	while(x > 0){
		sum += tree->m_table[x];
		x -= binary_index_tree_lowbit(x);
	}
	return(sum);
}

#endif
