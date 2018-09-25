#include "AhoCorasickAutomata.h"
#include <cassert>
#include <cctype>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define INVALID_CHAR '@'

#define get_child(acnode, c)                                                   \
  ((acnode)->child[(int)(std::tolower(c)) - (int)('a')])
#define set_child(acnode, c, childnode)                                        \
  do {                                                                         \
    (acnode)->child[(int)(std::tolower(c)) - (int)('a')] = childnode;          \
  } while (0)

#define get_child_by_index(acnode, i) ((acnode)->child[i])
#define get_char(acnode) (((acnode) == NULL) ? INVALID_CHAR : (acnode)->ch)
#define get_string(acnode) (((acnode) == NULL) ? "" : (acnode)->value)
#define is_leaf(acnode) (((acnode) == NULL) ? false : (acnode)->is_leaf)
#define get_father(acnode) (((acnode) == NULL) ? NULL : (acnode)->father)
#define get_fail(acnode) (((acnode) == NULL) ? NULL : (acnode)->fail)
#define add_output(acnode) (((acnode) == NULL) ? NULL : (acnode)->fail)

AcNode::AcNode() {
  ch = INVALID_CHAR;
  value = "";
  is_leaf = false;
  father = NULL;
  std::memset(child, 0, sizeof(AcNode *) * CHILD_MAX);
  fail = NULL;
  std::memset(output, 0, sizeof(AcNode *) * MAX);
  output_cnt = 0;
}

AcNode::AcNode(const AcNode &other) {
  ch = other.ch;
  value = other.value;
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  std::memcpy(output, other.output, sizeof(AcNode *) * MAX);
  output_cnt = other.output_cnt;
}

AcNode &AcNode::operator=(const AcNode &other) {
  if (this == &other)
    return *this;
  ch = other.ch;
  value = other.value;
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  std::memcpy(output, other.output, sizeof(AcNode *) * MAX);
  output_cnt = other.output_cnt;
  return *this;
}

static void Insert(AcNode *root, const std::string &pattern) {
  AcNode *p = root;
  for (int i = 0; i < pattern.length(); i++) {
    char ch = pattern[i];
    if (get_child(p, ch)) {
      set_child(p, ch, new AcNode());
      get_child(p, ch)->ch = ch;
      get_child(p, ch)->value = p->value + ch;
      if (i == pattern.length() - 1) {
        get_child(p, ch)->is_leaf = true;
      }
      get_child(p, ch)->father = p;
    }
    p = get_child(p, pattern[i]);
  }
}

static void BuildFailPointer(AcNode *root) {
  std::queue<AcNode *> q;
  root->fail = NULL;
  q.push(root);

  while (!q.empty()) {
    AcNode *p = q.front();
    q.pop();

    for (int i = 0; i < CHILD_MAX; i++) {
      if (get_child_by_index(p, i) != NULL) {
        AcNode *father = p->father;
        while (father) {
          if (get_child_by_index(father, i) != NULL) {
            get_child_by_index(p, i)->fail = get_child_by_index(father, i);
            break;
          }
          father = father->fail;
        }
        if (!f) {
          //若f为空则节点i的失败指针指向根节点
          p->child[i]->fail = &ac->root;
        }
        q.push(p->child[i]);
      }
    } // for
  }   // while
}

ACAutomation *ACAutomationNew(const std::vector<std::string> &str) {
  ACAutomation *ac = new ACAutomation();
  // 建立AC自动机
  // 插入待查寻字符串
  // 建立失败路径
  for (int i = 0; i < str.size(); i++)
    Insert(ac, str[i]);
  FailPath(ac);
  return ac;
}

std::unordered_map<std::string, std::vector<int>>
ACAutomationMatch(ACAutomation *ac, const std::string &text) {
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
    } else {
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
          std::string s = GetString(tmp);
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

// not implement
void ACAutomationFree(ACAutomation *ac) { (void)ac; }

