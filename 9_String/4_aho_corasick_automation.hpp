//AC自动机
//aho corasick automation

//在一个文本中搜索多个字符串出现的位置和次数

//1)原始方法
//当在一个文本中匹配多个字符串时
//若使用本章前面的字符串匹配算法则需要对每个字符串都遍历一次文本
//或者对文本中每个字符 都要遍历所有字符串 时间复杂度较高
//2)AC自动机
//AC自动机可以遍历一遍文本就匹配所有的字符串
//AC自动机是建立在字典树和有限自动机基础上的字符串匹配算法
//该算法的核心思路是初始时将所有待匹配的字符串模式存入字典树
//然后在扫面文本时不断的查找该字典树 从而得到所有字符串出现的次数和位置
//与原始字典树不同的是节点中增加了失败路径指针和父节点指针 用于处理不匹配的情况
//2)使用失败指针进行匹配
//设文本下标从0开始 将文本第0个字符与AC自动机中字典树开始匹配
//字典树中指针从根节点开始(根节点是空节点)
//若指针的孩子节点中有与第0个字符相同的节点
//则指针递归的进入该孩子节点 下标也移动一个位置到达第1个字符
//若这样一直匹配到字典树中的一个标记的节点
//则该标记节点与之前遍历过的节点组成一个匹配到的字符串
//则在文本下标从0到目前的位置上有一个匹配的字符串 记录位置0和该字符串
//然后如果文本的下一个位置的字符还和指针的孩子节点中字符相匹配
//可以继续像这样递归向下匹配
//直到再没有指针的孩子节点中的字符与文本当前位置的字符相匹配
//
//若当文本到达第j个字符处 当前指针的孩子节点中没有匹配的节点
//则这时指针沿着失败指针移动到下一个节点
//考察该节点的字符与文本当前位置的字符是否匹配
//若不匹配则继续递归的移动到下一个失败指针所指的节点
//若出现某个节点匹配 则可以按照上文所述的方式继续
//若一直到节点为根节点时也不匹配 则将指针归位为字典树的根节点指针
//文本移动到下一位置 重新开始新一轮匹配
//说明文本从0到当前位置的字符没有与字典树中的字符串相匹配的
//
//3)构造失败指针
//对字典树中每个指针构造失败指针
//从字典树中的空根节点开始 对于每个节点i
//若i是根节点 则它的所有孩子节点的失败指针指向根节点它自己
//若i不是根节点 若它有孩子节点child
//则考察节点i的失败指针所指向的那个节点fail
//若fail有一个与i的孩子节点child的字符相同的孩子节点child2
//则child的失败指针直接指向fail的这个孩子节点child2
//若fail没有这样一个与child字符相同的节点
//则再像这样递归的考察fail的失败指针指向的节点 即fail的fail
//直到fail节点为NULL 节点i的child的失败指针指向根节点
//
//本文引用了"AC自动机算法详解" 作者"极限定律"
//该文档中有一处错误 在本文的代码中进行了改正 在代码中会有说明


#include "general_head.h"

struct ac_node{
	int a_cnt;
	ac_node* a_ch[MAX];
	ac_node *a_fa;
	ac_node *a_fail;
	ac_node()
		: a_cnt(0), a_fa(NULL), a_fail(NULL){
			for(int i = 0; i < MAX; ++ i)
				a_ch[i] = NULL;
	}
};

struct aho_corasick_automation{
private:
	ac_node a_root;
	void a_insert(string r){
		 ac_node *p(&a_root);
		for(int i = 0; i < (int)r.length(); ++ i){
			int index = r[i] - 'a';
			if(p->a_ch[index] == NULL){
				p->a_ch[index] = new ac_node();
				//将孩子节点成员中的父节点指针指向自己
				//加入父节点成员完全是为了输出当前节点所在的字符串
				p->a_ch[index]->a_fa = p;
			}
			p = p->a_ch[index];
		}
		++ p->a_cnt;
	}
	char a_getchar(ac_node *p){
		//返回节点p的字母 若为根节点则输出@
		if(p->a_fa == NULL)
			return('@');

		ac_node *fa(p->a_fa);
		for(int i = 0; i < MAX; ++ i)
			if(fa->a_ch[i] == p)
				return('a' + i);
		return('@');
	}
	string a_getstring(ac_node *p, string r = ""){
		//返回以节点p为最后一个字母的字符串
		//若节点增加字母和字符串成员
		//插入字符串时在相应节点中进行标记
		//则可不需要a_getstring和a_getchar函数

		//递归终止条件 当节点p是根节点时返回字符串
		if(p->a_fa == NULL)
			return(r);

		char ch = a_getchar(p);
		//继续向上递归求字符串
		return(a_getstring(p->a_fa, ch + r));
	}
	void a_failpath(){
		//通过bfs给字典树中所有节点建立失败指针
		queue<ac_node*>	q;
		//根节点的失败指针为NULL
		a_root.a_fail = NULL;
		//根节点的所有孩子节点的失败指针指向根节点
		for(int i = 0; i < MAX; ++ i)
			if(a_root.a_ch[i] != NULL){
				a_root.a_ch[i]->a_fail = &a_root;
				q.push(a_root.a_ch[i]);
			}

		while(!q.empty()){
			ac_node *p = q.front(); q.pop();
	
			for(int i = 0; i < MAX; ++ i)
				if(p->a_ch[i] != NULL){
					//设置节点p的孩子节点i的失败节点
					ac_node *f = p->a_fail;
					//f是节点i的父节点p的失败指针
					while(f != NULL){
						if(f->a_ch[i] != NULL){
							//若f有与节点i字符相同的孩子节点
							//则节点i的失败指针指向f的这个孩子节点
							p->a_ch[i]->a_fail = f->a_ch[i];
							break;
						}
						//若f没有这样的孩子节点
						//递归考察f的失败指针指向的节点
						f = f->a_fail;
					}
					if(f == NULL)
						//若f为空则节点i的失败指针指向根节点
						p->a_ch[i]->a_fail = &a_root;
					q.push(p->a_ch[i]);
				}
		}
	}
public:
	aho_corasick_automation(){
	}
	void a_build(vector<string> r){
		//建立AC自动机 插入待查寻字符串 建立失败路径
		for(int i = 0; i < (int)r.size(); ++ i)
			a_insert(r[i]);
		a_failpath();
	}
	void a_search(string t, multimap<string, int>& pos){
		//扫描文本t
		//返回其中出现的字典树中的字符串及其位置 存储于映射表pos中
		pos.clear();
		int i(0);
		ac_node *p(&a_root);
		while(i < (int)t.length()){
			int index = t[i] - 'a';
			while(p->a_ch[index] == NULL && p != &a_root)
				//若字典树中该节点不存在
				//则沿着fail指针递归 直到回到根节点
				p = p->a_fail;
			if(p->a_ch[index] == NULL)
				p = &a_root;
			else{
				//若点p的孩子节点index存在
				//即该孩子节点与文本下标i处字符匹配
				p = p->a_ch[index];
				ac_node *tmp(p);
				while(tmp != &a_root){
					//通过指针tmp找出所有可能与文本下标i处匹配的字符串
					//因为除了p的孩子节点index 还可能存在其他字符串此时也与i处匹配
					//
					//在文档"AC自动机算法详解" 作者"极限定律"中
					//第一个有问题的地方是: 
					//原文中该处的判断条件是: 
					//while(tmp != root && tmp->a_cnt == 0)
					//(原文与本文中的变量名不一样 但代码的含义没有曲解)
					//但是经过测试这里tmp->a_cnt == 0的条件恰好应该是相反的
					//即tmp->a_cnt != 0 也可写作tmp->a_cnt(该值为正时即true)
					if(tmp->a_cnt){
						string s(a_getstring(tmp));
						pos.insert(make_pair(s, i - (int)s.length() + 1));
						//文档"AC自动机算法详解" 作者"极限定律"中
						//第二个有问题的地方则是: 
						//原文中该处有一处操作: 
						//tmp->a_cnt = 0;
						//(原文与本文中的变量名不一样 但代码的含义没有曲解)
						//但我不太明白为何要将字典树中该字符串删除
						//也可能只求字符串第一次出现的位置
						//本文的代码中没有删除字符串
						//测试用例中可以看出本文的代码找出了所有匹配到的字符串位置
					}
					tmp = tmp->a_fail;
				}
			}
			++ i;
		}
	}
};
