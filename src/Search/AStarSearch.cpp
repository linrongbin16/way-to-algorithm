// MIT License
// Copyright 2018 linrongbin16@gmail.com

#include "AStarSearch.h"

#ifndef MAX
#define MAX 1024
#endif
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <string>
#include <utility>
#include <map>
#include <unordered_map>
#include <cassert>


namespace std {
  template <> struct hash<Node> {
    typedef Node argument_type;
    typedef std::size_t result_type;
    result_type operator()(argument_type const &other) const {
      return std::hash<std::string>{}(std::string(other.number));
    }
  };
}

Node::Node() {
  memcpy(number, invalid.number, sizeof(number));
}

Node::Node(const char *number1) {
  memcpy(number, number1, sizeof(number));
}

Node::Node(const Node &other) {
  memcpy(number, other.number, sizeof(number));
}

Node& Node::operator=(const Node &other) {
  if (this == &other)
    return *this;
  memcpy(number, other.number, sizeof(number));
  return *this;
}

bool operator==(const Node &a, const Node &b) {
  if (&a == &b)
    return true;
  return memcmp(a.number, b.number, sizeof(a.number)) == 0;
}

bool operator!=(const Node &a, const Node &b) {
  if (&a == &b)
    return false;
  return memcmp(a.number, b.number, sizeof(a.number)) != 0;
}

int operator-(const Node &a, const Node &b) {
  int diff = 0;
  for (int i = 0; i < 9; ++i)
    if (a.number[i] != b.number[i])
      ++diff;
  return diff;
}

Node Node::Neighbor(int direction) const {
  int xpos;
  for (xpos = 0; xpos < 9; xpos++)
    if (number[xpos] == 'x')
      break;
  int npos = xpos + direction;
  if (npos < 0 || npos >= 9) {
    return invalid;
  }

  Node ret = *this;
  std::swap(ret.number[xpos], ret.number[npos]);
  return ret;
}

int direction[4] = { -3, 3, -1, 1 };
Node invalid = Node("---------");

Node OpenPop(std::vector<Node> &open, Node end, std::unordered_map<Node, int> &score_g) {
    Node ret = invalid;
    int f = INT_MAX;
    std::vector<Node>::iterator i = open.begin();
    for (; i != open.end(); i++) {
        int h = *i - end;
        assert(score_g.find(*i) != score_g.end());
        if (f > h + score_g[*i]) {
            f = h + score_g[*i];
            ret = *i;
        }
    }
    open.erase(i);
    return ret;
}

std::vector<Node> FindPath(const std::unordered_map<Node, Node> &close, Node e) {
    std::vector<Node> path;
    path.push_back(e);

    while (true) {
        std::unordered_map<Node, Node>::iterator from = close.find(e);
        if (from == close.end() || from->second == invalid)
            break;
        path.push_back(from->second);
        e = from->second;
    }
    return path;
}

std::vector<Node> AStarSearch(Node beg, Node end) {
    std::unordered_map<Node, int> score_g;
    std::vector<Node> open;
    std::unordered_map<Node, Node> close;

    open.push_back(beg);
    close.insert(std::make_pair(beg, invalid));

    while (!open.empty()) {
        Node node = OpenPop(open, end, score_g);
        if (node == end) {
            return FindPath(close, end);
        }

        /* node中'x'与上下左右4个方向的数字交换位置 */
        for (int i = 0; i < 4; i++) {
            Node neighbor = node.Neighbor(i);
            if (neighbor == invalid) {
                continue;
            }
            // 邻节点的g(x)加1
            score_g[neighbor] = score_g[node] + 1;

            // 若close中已经存在neighbor_node则跳过该点
            if (close.find(neighbor) != close.end())
                continue;
            open.push_back(neighbor);
            close.insert(std::make_pair(neighbor, node));
        }
    }
    return {};
}
