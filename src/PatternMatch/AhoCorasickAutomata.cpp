#include "AhoCorasickAutomata.h"
#include <cassert>
#include <cctype>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define INVALID_CHAR '@'
#define child_position(c) ((assert(std::islower(c))), (int)(c) - (int)'a')

AcNode::AcNode(int code) : code(code) {
  ch = INVALID_CHAR;
  is_leaf = false;
  father = NULL;
  std::memset(child, 0, sizeof(AcNode *) * CHILD_MAX);
  fail = NULL;
  output = NULL;
}

AcNode::AcNode(const AcNode &other) {
  code = other.code;
  ch = other.ch;
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  output = other.output;
}

AcNode &AcNode::operator=(const AcNode &other) {
  if (this == &other)
    return *this;
  code = other.code;
  ch = other.ch;
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  output = other.output;
  return *this;
}

static std::string GetString(AcNode *node) {
  std::string s;
  for (AcNode *i = node; i && i->ch != INVALID_CHAR; i = i->father) {
    s = std::string() + i->ch + s;
  }
  return s;
}

static int code_count;

static void Insert(AcNode *root, const std::string &word) {
  AcNode *p = root;
  for (int i = 0; i < word.length(); i++) {
    char ch = word[i];
    int pos = child_position(ch);
    // 若p还没有ch这个孩子节点
    // 则新建该孩子节点
    if (!p->child[pos]) {
      p->child[pos] = new AcNode(code_count++);
      p->child[pos]->ch = ch;
      p->child[pos]->father = p;
      // 标记该节点为叶子节点
      // 表示前缀树中某字符串的末尾字符
      if (i == word.length() - 1) {
        p->child[pos]->is_leaf = true;
      }
    }
    p = p->child[pos];
  }
}

static AcNode *BuildPrefixTree(const std::vector<std::string> &pattern) {
  code_count = 0;
  AcNode *root = new AcNode(code_count++);
  for (int i = 0; i < pattern.size(); i++) {
    Insert(root, pattern[i]);
  }
  return root;
}

static void BuildFailPointer(AcNode *root) {
  std::queue<AcNode *> q;

  // root节点fail指针指向自己
  // root节点output指针为NULL
  root->fail = root;
  root->output = NULL;

  // root节点的孩子节点的fail指针指向root
  for (int i = 0; i < CHILD_MAX; i++) {
    AcNode *target = root->child[i];
    if (target) {
      target->fail = root;
      target->output = NULL;
      q.push(target);
    }
  }

  while (!q.empty()) {
    AcNode *p = q.front();
    q.pop();

    for (int i = 0; i < CHILD_MAX; i++) {
      AcNode *target = p->child[i];
      if (!target) {
        continue;
      }

      q.push(target);
      AcNode *fail = p->fail;
      AcNode *fail_child_i = fail->child[i];
      while (!fail_child_i && fail != root) {
        fail = fail->fail;
        fail_child_i = fail->child[i];
      }
      if (fail_child_i) {
        target->fail = fail_child_i;
      } else {
        target->fail = root;
      }
      if (target->fail->is_leaf) {
        target->output = target->fail;
      }
    } // for
  }   // while
}

AcNode *AhoCorasickAutomataNew(const std::vector<std::string> &pattern) {
  AcNode *root = BuildPrefixTree(pattern);
  BuildFailPointer(root);
  return root;
}

static void
AddMatchPosition(std::unordered_map<std::string, std::vector<int>> &match,
                 const std::string &key, int pos) {
  if (match.find(key) == match.end()) {
    std::vector<int> match_pos;
    match_pos.push_back(pos);
    match.insert(std::make_pair(key, match_pos));
    return;
  }
  match[key].push_back(pos);
}

std::unordered_map<std::string, std::vector<int>>
AhoCorasickAutomataMatch(AcNode *root, const std::string &text) {
  std::unordered_map<std::string, std::vector<int>> match;
  int i = 0;
  AcNode *p = root;

  while (i < text.length()) {
    char ch = text[i];
    AcNode *pc = p->child[child_position(ch)];

    // 当匹配失败时沿着失败指针跳转
    while (!pc) {
      p = p->fail;
      pc = p->child[child_position(ch)];
      // 当跳转回root节点时说明不存在匹配
      // 从text的下个位置重新匹配
      if (p == root && !pc) {
        i++;
        break;
      }
    } // while

    // 无论是正常的沿着前缀树到达pc
    // 还是沿着失败指针跳转到pc
    // 最终找到合适的匹配位置pc
    if (pc) {
      p = pc;
      i++;

      // 若p为叶子节点则将该位置加入成功匹配结果
      if (p->is_leaf) {
        std::string s = GetString(p);
        AddMatchPosition(match, s, i - s.length());
      }
      // 递归的沿着p的失败指针找到所有输出指针
      // 并将其都加入成功匹配结果
      for (AcNode *ptr = p; ptr && ptr != root; ptr = ptr->fail) {
        if (ptr->output) {
          std::string s = GetString(ptr->output);
          AddMatchPosition(match, s, i - s.length());
        }
      } // for
    }
  } // while
  return match;
}

// not implement
void AhoCorasickAutomataFree(AcNode *root) { (void)root; }

