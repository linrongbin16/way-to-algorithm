#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#ifndef MAX
#define MAX 128
#endif
#ifndef CHILD_MAX
#define CHILD_MAX 26
#endif

struct AcNode {
  int code;
  // a-z
  char ch;
  bool is_leaf;
  AcNode *father;
  AcNode *child[CHILD_MAX];
  AcNode *fail;
  AcNode *output;

  AcNode(int tag);
  AcNode(const AcNode &other);
  AcNode &operator=(const AcNode &other);
};

// create AC automation
AcNode *AhoCorasickAutomataNew(const std::vector<std::string> &pattern);

// free AC automation
void AhoCorasickAutomataFree(AcNode *root);

// match text with AC automation
std::unordered_map<std::string, std::vector<int>>
AhoCorasickAutomataMatch(AcNode *root, const std::string &text);

