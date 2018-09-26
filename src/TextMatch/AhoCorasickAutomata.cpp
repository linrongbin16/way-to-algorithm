#include "AhoCorasickAutomata.h"
#include <cassert>
#include <cctype>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define INVALID_CHAR '@'
#define add_output(acnode, outnode)                                            \
  do {                                                                         \
    (acnode)->output[(acnode)->output_cnt++] = outnode;                        \
  } while (0)

#define foreach_output(acnode, i)                                              \
  for (int(i) = 0; (i) < (acnode)->output_cnt; (i)++)

AcNode::AcNode() {
  ch = INVALID_CHAR;
  is_leaf = false;
  father = NULL;
  std::memset(child, 0, sizeof(AcNode *) * CHILD_MAX);
  fail = NULL;
  std::memset(output, 0, sizeof(AcNode *) * MAX);
  output_cnt = 0;
}

AcNode::AcNode(const AcNode &other) {
  ch = other.ch;
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
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  std::memcpy(output, other.output, sizeof(AcNode *) * MAX);
  output_cnt = other.output_cnt;
  return *this;
}

static AcNode *&AcChild(AcNode *node, char c) {
  assert(node);
  assert(std::islower(c));
  return node->child[(int)c - (int)'a'];
}

static AcNode *&AcChild(AcNode *node, int i) {
  assert(node);
  return node->child[i];
}

static bool &AcLeaf(AcNode *node) {
  assert(node);
  return node->is_leaf;
}

static AcNode *&AcFather(AcNode *node) {
  assert(node);
  return node->father;
}

static AcNode *&AcFail(AcNode *node) {
  assert(node);
  return node->fail;
}

static int &AcOutputCnt(AcNode *node) {
  assert(node);
  return node->output_cnt;
}

static AcNode *&AcOutput(AcNode *node, int i) {
  assert(node);
  return node->output[i];
}

static char &AcChar(AcNode *node) {
  assert(node);
  return node->ch;
}

static std::string AcString(AcNode *node) {
  std::string str;
  for (AcNode *i = node; i; i = AcFather(i)) {
    str = std::string() + AcChar(i) + str;
  }
  return str;
}

static void Insert(AcNode *root, const std::string &pattern) {
  AcNode *p = root;
  for (int i = 0; i < pattern.length(); i++) {
    char ch = pattern[i];
    if (AcChild(p, ch)) {
      AcChild(p, ch) = new AcNode();
      AcChar(p) = ch;
      if (i == pattern.length() - 1) {
        AcLeaf(AcChild(p, ch)) = true;
      }
      AcFather(AcChild(p, ch)) = p;
    }
    p = AcChild(p, ch);
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
      if (AcChild(p, i) != NULL) {
        AcNode *father = p->father;
        while (father) {
          if (AcChild(father, i) != NULL) {
            AcFail(AcChild(p, i)) = AcChild(father, i);
            break;
          }
          father = AcFail(father);
        }
        if (!father) {
          AcFail(AcChild(p, i)) = root;
        }
        q.push(AcChild(p, i));
      }
    } // for
  }   // while
}

static void BuildOutputPointer(AcNode *root) {}

AcNode *AhoCorasickAutomataNew(const std::vector<std::string> &pattern) {
  AcNode *root = new AcNode();
  for (int i = 0; i < pattern.size(); i++)
    Insert(root, pattern[i]);
  BuildFailPointer(root);
  BuildOutputPointer(root);
  return root;
}

std::unordered_map<std::string, std::vector<int>>
AhoCorasickAutomataMatch(AcNode *root, const std::string &text) {
  std::unordered_map<std::string, std::vector<int>> pos;
  int i = 0;
  AcNode *p = root;

  while (i < text.length()) {
    int index = (int)text[i] - (int)'a';
    while (!AcChild(p, text[i]) && p != root) {
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
void AhoCorasickAutomataFree(AcNode *root) { (void)root; }

