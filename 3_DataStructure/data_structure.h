//数据结构头文件
//data_structure.h

//支持数据结构一章的自定义数据结构
#ifndef NULL
#define NULL 0
#endif

struct hash_node{
	//哈希表节点
	int h_value;		//节点值
	hash_node *h_next;	//节点邻节点指针
	hash_node(int cvalue = 0)
		: h_value(cvalue), h_next(NULL){
	}
};
struct seg_node{
	//线段树节点
	int s_beg;			//节点左边界
	int s_end;			//节点右边界
	int s_cover;		//节点是否被覆盖标记
	seg_node *s_lc;		//节点左孩子节点指针
	seg_node *s_rc;		//节点右孩子节点指针
	seg_node(int cbeg = 0, int cend = 0)
		: s_beg(cbeg), s_end(cend), s_cover(0), s_lc(NULL), s_rc(NULL){
	}
};
struct dis_node{
	//并查集节点
	int d_idx;			//节点下标号
	dis_node *d_fa;		//节点父节点指针
	dis_node(int cidx = 0)
		: d_idx(cidx), d_fa(NULL){
	}
};
struct left_node{
	//左偏树节点
	int l_idx;			//节点下标号
	int l_dist;			//节点深度
	left_node *l_lc;	//节点左孩子节点指针
	left_node *l_rc;	//节点右孩子节点指针
	left_node(int cidx = 0, int cdist = 0)
		: l_idx(cidx), l_dist(cdist), l_lc(NULL), l_rc(NULL){
	}
};
