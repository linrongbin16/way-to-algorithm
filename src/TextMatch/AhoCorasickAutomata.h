#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#ifndef MAX
#define MAX 64
#endif

typedef std::unordered_map<std::string, std::vector<int>> ac_match;

struct TrieNode {
  int count;
  TrieNode *child[MAX];
  TrieNode *father;
  TrieNode *fail;

  TrieNode();
  TrieNode(const TrieNode &other);
  TrieNode &operator=(const TrieNode &other);
};

struct AhoCorasick {
  TrieNode root;
};

// create AC automation
AhoCorasick *AhoCorasickNew(const std::vector<std::string> &str);

// free AC automation
void AhoCorasickFree(AhoCorasick *ac);

// match text with AC automation
std::unordered_map<std::string, std::vector<int>>
AhoCorasickMatch(AhoCorasick *ac, const std::string &text);

