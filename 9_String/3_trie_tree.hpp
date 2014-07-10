//字典树
//trie_tree.hpp

//统计一本书中的单词和单词出现的次数

//原始的方法是用一个表格存储这本书中的所有单词
//插入一个单词之前需要遍历表格来查找这个单词是否已经存在，但时间复杂度显然过高了
//
//查找单词或前缀是字典树的典型应用场景，字典树是一个用空间换时间的数据结构
//字典树的根节点是空节点，树中每个节点最多有26个孩子节点，分别指向26个字母
//当向字典树中插入一个单词，第一个字母存入字典树的根节点的对应的孩子节点
//第二个字母存入第一个字母的对应孩子节点中，依次类推
//在最后一个字母的节点中进行标记，说明从第一层节点到当前节点是一个单词
//没有标记的节点只说明存在该字母，但不是一个单词
//比如字典树中存入big和boy两个单词时是这样的：
//						root
//					/			\
//					b			  g
//				/		\			\
//			   i		 o			  o
//			 /		   /				\
//			g		  y					  d
//并且g和y节点被标记，说明该节点和之前遍历的节点组成一个单词
//这样的存储方式不是很方便于查询整个字符串
//在标记的节点中增加一个字符串成员，将以该节点为最后一个字符的字符串存储起来更直观
//因此字典树也可以实作为这样的形式：
//						root
//					/			\
//				   b:b			  g:g
//				/		\			\
//			   i:bi		 o:bo		  o:go
//			 /		   /				\
//		    g:big	  y:boy				d:god
//其中单词big和boy的前缀b是相同的，所以它们都是节点b:b的子节点
//因此字典树也可以快速处理字符串的前缀

#include "general_head.h"

struct trie_node{
	int t_cnt;
	trie_node* t_ch[MAX];
	trie_node()
		: t_cnt(0){
			for(int i = 0; i < MAX; ++ i)
				t_ch[i] = NULL;
	}
}; 
struct trie_tree{
private:
	trie_node t_root;
public:
	trie_tree(){
	}
	void t_insert(string r){
		trie_node *p(&t_root);
		for(int i = 0; i < (int)r.length(); ++ i){
			//为了方便只插入小写字母a-z
			//在指针数组中的下标从0到25，也可以动态分配指针空间
			int index = r[i] - 'a';
			if(p->t_ch[index] == NULL)
				p->t_ch[index] = new trie_node();
			p = p->t_ch[index];
		}
		//标记单词中最后一个字母所在的节点
		++ p->t_cnt;
	}
	int t_search(string r){
		trie_node *p(&t_root);
		for(int i = 0; i < (int)r.length(); ++ i){
			int index = r[i] - 'a';
			if(p->t_ch[index] == NULL)
				//若中途出现空指针说明该单词未被插入字典树中
				return(0);
			p = p->t_ch[index];
		}
		//返回该字母所在单词的次数
		return(p->t_cnt);
	}
};
