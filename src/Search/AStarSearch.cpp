#include "AStarSearch.h"
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int direction[4] = {-3, 3, -1, 1};
Node invalid_node = Node("---------");

// node hash
int HashNode(const Node &a) {
  return std::hash<std::string>{}(std::string(a.number));
}

// node constructor
Node::Node(const std::string &s) { std::strncpy(number, s.data(), 9); }

// node equal
bool operator==(const Node &a, const Node &b) {
  if (&a == &b)
    return true;
  return std::strncmp(a.number, b.number, 9) == 0;
}

// node difference
int operator-(const Node &a, const Node &b) {
  int diff = 0;
  for (int i = 0; i < 9; ++i)
    if (a.number[i] != b.number[i])
      diff++;
  return diff;
}

// node neighbor
Node Neighbor(const Node &a, int direction) {
  int xpos;
  for (xpos = 0; xpos < 9; xpos++)
    if (a.number[xpos] == 'x')
      break;
  int npos = xpos + direction;
  if (npos < 0 || npos >= 9) {
    return invalid_node;
  }

  Node ret = a;
  std::swap(ret.number[xpos], ret.number[npos]);
  return ret;
}

// get closest node
Node PopOpenTable(std::vector<Node> *open_table, Node end,
                  const std::unordered_map<int, int> &g_score) {
  Node ret = invalid_node;
  int f_score = INT_MAX;
  std::vector<Node>::iterator i = open_table->begin();
  for (; i != open_table->end(); i++) {
    Node &tmp = *i;
    int tmp_hash = HashNode(tmp);
    int h_score = tmp - end;
    assert(g_score.find(tmp_hash) != g_score.end());
    if (f_score > h_score + g_score[tmp_hash]) {
      f_score = h_score + g_score[tmp_hash];
      ret = tmp;
    }
  }
  open_table->erase(i);
  return ret;
}

std::vector<Node> Path(const std::unordered_map<Node, Node> &close_table,
                       Node e) {
  std::vector<Node> path;
  path.push_back(e);

  while (true) {
    std::unordered_map<Node, Node>::const_iterator from = close_table.find(e);
    if (from == close_table.end() || from->second == invalid_node)
      break;
    path.push_back(from->second);
    e = from->second;
  }
  return path;
}

std::vector<Node> AStarSearch(Node beg, Node end) {
  std::unordered_map<int, int> g_score;
  std::vector<Node> open_table;
  std::unordered_map<Node, Node> close_table;

  open_table.push_back(beg);
  close_table.insert(std::make_pair(beg, invalid_node));

  while (!open_table.empty()) {
    Node node = PopOpenTable(&open_table, end, g_score);
    int node_hash = HashNode(node);
    if (node == end) {
      return Path(close_table, end);
    }

    /* node中'x'与上下左右4个方向的数字交换位置 */
    for (int i = 0; i < 4; i++) {
      Node neighbor = Neighbor(node, i);
      int neighbor_hash = HashNode(neighbor);
      if (neighbor == invalid_node) {
        continue;
      }
      // 邻节点的g(x)加1
      g_score[neighbor_hash] = g_score[node_hash] + 1;

      // 若close_table中已经存在neighbor_node则跳过该点
      if (close_table.find(neighbor) != close_table.end())
        continue;
      open_table.push_back(neighbor);
      close_table.insert(std::make_pair(neighbor, node));
    }
  }
  return {};
}

