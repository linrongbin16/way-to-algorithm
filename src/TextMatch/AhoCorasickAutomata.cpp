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

AcNode::AcNode() {
  ch = INVALID_CHAR;
  is_leaf = false;
  father = NULL;
  std::memset(child, 0, sizeof(AcNode *) * CHILD_MAX);
  fail = NULL;
  output = NULL;
}

AcNode::AcNode(const AcNode &other) {
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
  ch = other.ch;
  is_leaf = other.is_leaf;
  father = other.father;
  std::memcpy(child, other.child, sizeof(AcNode *) * CHILD_MAX);
  fail = other.fail;
  output = other.output;
  return *this;
}

static std::string GetString(AcNode *node) {
  std::string str;
  for (AcNode *i = node; i; i = i->father) {
    str = std::string() + i->ch + str;
  }
  return str;
}

static void Insert(AcNode *root, const std::string &pattern) {
  AcNode *p = root;
  for (int i = 0; i < pattern.length(); i++) {
    char ch = pattern[i];
    int pos = child_position(ch);
    if (!p->child[pos]) {
      p->child[pos] = new AcNode();
      p->child[pos]->ch = ch;
      if (i == pattern.length() - 1) {
        p->child[pos]->is_leaf = true;
      }
      p->child[pos]->father = p;
    }
    p = p->child[pos];
  }
}

static AcNode *BuildPrefixTree(const std::vector<std::string> &pattern) {
  AcNode *root = new AcNode();
  for (int i = 0; i < pattern.size(); i++) {
    Insert(root, pattern[i]);
  }
  return root;
}

static void BuildFailPointer(AcNode *root) {
  std::queue<AcNode *> q;
  root->fail = NULL;
  q.push(root);

  while (!q.empty()) {
    AcNode *p = q.front();
    q.pop();

    for (int i = 0; i < CHILD_MAX; i++) {
      AcNode *target = p->child[i];
      if (target) {
        AcNode *fail = p->fail;
        while (fail) {
          if (fail->child[i]) {
            // father->child[i]->ch == target->ch
            target->fail = fail->child[i];
            break;
          }
          fail = fail->fail;
        }
        if (!fail) {
          target->fail = root;
        }
        q.push(target);
      } // if
    }   // for
  }     // while
}

static bool HasPattern(const std::vector<std::string> &pattern,
                       const std::string &target) {
  for (int i = 0; i < pattern.size(); i++) {
    if (pattern[i] == target) {
      return true;
    }
  }
  return false;
}

static void BuildOutputPointer(AcNode *root,
                               const std::vector<std::string> &pattern) {
  std::queue<AcNode *> q;
  root->output = NULL;
  q.push(root);

  while (!q.empty()) {
    AcNode *p = q.front();
    q.pop();

    for (int i = 0; i < CHILD_MAX; i++) {
      AcNode *target = p->child[i];
      if (target) {
        AcNode *fail = target->fail;
        std::string str = "";
        if (fail) {
          str = GetString(fail);
        }
        if (HasPattern(pattern, str)) {
          target->output = fail;
        } else {
          target->output = fail->output;
        }
        q.push(target);
      } // if
    }   // for
  }     // while
}

AcNode *AhoCorasickAutomataNew(const std::vector<std::string> &pattern) {
  AcNode *root = BuildPrefixTree(pattern);
  BuildFailPointer(root);
  BuildOutputPointer(root, pattern);
  return root;
}

std::unordered_map<std::string, std::vector<int>>
AhoCorasickAutomataMatch(AcNode *root, const std::string &text) {
  std::unordered_map<std::string, std::vector<int>> match;
  int i = 0;
  AcNode *p = root;

  while (i < text.length()) {
    int pos = child_position(text[i]);
    while (!p->child[pos] && p != root) {
      p = p->fail;
    }

    if (!p->child[pos]) {
      p = root;
    } else {
      p = p->child[pos];
      AcNode *node = p;

      while (node != root) {
        if (node->is_leaf) {
          std::string str = GetString(node);
          std::vector<int> match_pos;
          if (match.find(str) != match.end()) {
            match_pos = match[str];
          }
          match_pos.push_back(i - str.length() + 1);
          match.insert(std::make_pair(str, match_pos));
        }
        node = node->fail;
        break;
      }
    }
    i++;
  }
  return match;
}

// not implement
void AhoCorasickAutomataFree(AcNode *root) { (void)root; }

