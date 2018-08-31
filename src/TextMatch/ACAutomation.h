#pragma once
#ifndef MAX
#define MAX 64
#endif
#include <cassert>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

struct Node {
  int count;
  Node *child[MAX];
  Node *father;
  Node *fail;

  Node();
  Node(const Node &other);
  Node &operator=(const Node &other);
};

struct ACAutomation {
  Node root;
};

// create AC automation
ACAutomation *ACAutomationNew(const std::vector<std::string> &str);

// free AC automation
void ACAutomationFree(ACAutomation *ac);

// match with AC automation
std::unordered_map<std::string, std::vector<int>>
ACAutomationMatch(ACAutomation *ac, const std::string &text);

