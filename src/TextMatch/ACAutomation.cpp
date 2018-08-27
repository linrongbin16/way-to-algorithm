#include "ACAutomation.h"
#include <cassert>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// implement

#define INVALID_CHAR '@'

Node::Node()
{
    count = 0;
    father = NULL;
    fail = NULL;
    memset(child, 0, sizeof(child));
}

Node::Node(const Node &other)
{
    count = other.count;
    father = other.father;
    fail = other.fail;
    memcpy(child, other.child, sizeof(child));
}

Node &Node::operator=(const Node &other)
{
    if (this == &other) return *this;
    count = other.count;
    father = other.father;
    fail = other.fail;
    memcpy(child, other.child, sizeof(child));
    return *this;
}

void Insert(ACAutomation *ac, const std::string &str)
{
    Node *p = &ac->root;
    for (int i = 0; i < str.length(); i++) {
        int index = (int)str[i] - (int)'a';
        if (p->child[index] == NULL) {
            p->child[index] = new Node();
            //将孩子节点成员中的父节点指针指向自己
            //加入父节点成员完全是为了输出当前节点所在的字符串
            p->child[index]->father = p;
        }
        p = p->child[index];
    }
    ++p->count;
}

char GetChar(Node *p)
{
    //返回节点p的字母 若为根节点则输出@
    if (p->father == NULL) return INVALID_CHAR;

    Node *fa = p->father;
    for (int i = 0; i < MAX; ++i)
        if (fa->child[i] == p) return (char)((int)'a' + (int)i);
    return INVALID_CHAR;
}

std::string GetString(Node *p, const std::string &str)
{
    //返回以节点p为最后一个字母的字符串
    //若节点增加字母和字符串成员
    //插入字符串时在相应节点中进行标记
    //则可不需要a_getstring和a_getchar函数

    //递归终止条件 当节点p是根节点时返回字符串
    if (p->father == NULL) return str;

    char ch = GetChar(p);
    //继续向上递归求字符串
    return GetString(p->father, ch + str);
}

void FailPath(ACAutomation *ac)
{
    //通过bfs给字典树中所有节点建立失败指针
    std::queue<Node *> q;
    //根节点的失败指针为NULL
    ac->root.fail = NULL;
    //根节点的所有孩子节点的失败指针指向根节点
    for (int i = 0; i < MAX; ++i) {
        if (ac->root.child[i] != NULL) {
            ac->root.child[i]->fail = &ac->root;
            q.push(ac->root.child[i]);
        }
    }

    while (!q.empty()) {
        Node *p = q.front();
        q.pop();

        for (int i = 0; i < MAX; ++i) {
            if (p->child[i] != NULL) {
                //设置节点p的孩子节点i的失败节点
                Node *f = p->fail;
                // f是节点i的父节点p的失败指针
                while (f) {
                    if (f->child[i]) {
                        //若f有与节点i字符相同的孩子节点
                        //则节点i的失败指针指向f的这个孩子节点
                        p->child[i]->fail = f->child[i];
                        break;
                    }
                    //若f没有这样的孩子节点
                    //递归考察f的失败指针指向的节点
                    f = f->fail;
                }
                if (!f) {
                    //若f为空则节点i的失败指针指向根节点
                    p->child[i]->fail = &ac->root;
                }
                q.push(p->child[i]);
            }
        }  // for
    }      // while
}

ACAutomation *ACAutomationNew(const std::vector<std::string> &str)
{
    ACAutomation *ac = new ACAutomation();
    // 建立AC自动机
    // 插入待查寻字符串
    // 建立失败路径
    for (int i = 0; i < str.size(); i++) detail::Insert(ac, str[i]);
    detail::FailPath(ac);
    return ac;
}

std::unordered_map<std::string, std::vector<int>> ACAutomationMatch(
    ACAutomation *ac, const std::string &text)
{
    //扫描文本t
    //返回其中出现的字典树中的字符串及其位置 存储于映射表pos中
    std::unordered_map<std::string, std::vector<int>> pos;
    int i = 0;
    Node *p = &ac->root;

    while (i < text.length()) {
        int index = (int)text[i] - (int)'a';
        while (!p->child[index] && p != &ac->root) {
            //若字典树中该节点不存在
            //则沿着fail指针递归 直到回到根节点
            p = p->fail;
        }

        if (p->child[index] == NULL) {
            p = &ac->root;
        }
        else {
            //若点p的孩子节点index存在
            //即该孩子节点与文本下标i处字符匹配
            p = p->child[index];
            Node *tmp = p;

            // http://store.steampowered.com/app/252490/Rust/?snr=1_4_4__128

            while (tmp != &ac->root) {
                //通过指针tmp找出所有可能与文本下标i处匹配的字符串
                //因为除了p的孩子节点index 还可能存在其他字符串此时也与i处匹配
                //
                //在文档"AC自动机算法详解" 作者"极限定律"中
                //第一个有问题的地方是:
                //原文中该处的判断条件是:
                // while(tmp != root and tmp->a_cnt == 0)
                //(原文与本文中的变量名不一样 但代码的含义没有曲解)
                //但是经过测试这里tmp->a_cnt == 0的条件恰好应该是相反的
                //即tmp->a_cnt != 0 也可写作tmp->a_cnt(该值为正时即true)
                if (tmp->count) {
                    std::string s = detail::GetString(tmp);
                    pos.insert(std::make_pair(s, i - s.length() + 1));
                    //文档"AC自动机算法详解" 作者"极限定律"中
                    //第二个有问题的地方则是:
                    //原文中该处有一处操作:
                    // tmp->a_cnt = 0;
                    //(原文与本文中的变量名不一样 但代码的含义没有曲解)
                    //但我不太明白为何要将字典树中该字符串删除
                    //也可能只求字符串第一次出现的位置
                    //本文的代码中没有删除字符串
                    //测试用例中可以看出本文的代码找出了所有匹配到的字符串位置
                }
                tmp = tmp->fail;
            }
        }
        ++i;
    }
    return pos;
}

void ACAutomationFree(ACAutomation *ac) { (void)ac; }
