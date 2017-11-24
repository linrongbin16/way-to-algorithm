// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

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


//
// interface
//

struct Node {
  char number[9];

  Node();
  explicit Node(const char *number1);
  Node(const Node &other);
  Node& operator=(const Node &other);
  friend bool operator==(const Node &a, const Node &b);
  friend bool operator!=(const Node &a, const Node &b);
  friend int operator-(const Node &a, const Node &b);
  Node Neighbor(int direction) const;
};

std::vector<Node> AStarSearch(Node beg, Node end);


//
// implement
//

namespace detail {

  int direction[4] = { -3, 3, -1, 1 };
  Node invalid = Node("---------");

  Node OpenPop(std::vector<Node> &open, Node end, std::unordered_map<Node, int> &score_g);
  void OpenErase(std::vector<Node> &open, Node e);
  std::vector<Node> FindPath(const std::unordered_map<Node, Node> &close, Node end);

}

namespace std {
  template <> struct hash<Node> {
    typedef Node argument_type;
    typedef std::size_t result_type;
    result_type operator()(argument_type const &other) const {
      return std::hash<std::string>{}(std::string(other.number));
    }
  };
}

std::vector<Node> AStarSearch(Node beg, Node end) {
  std::unordered_map<Node, int> score_g;
  std::vector<Node> open;
  std::unordered_map<Node, Node> close;

  open.push_back(beg);
  close.insert(std::make_pair(beg, detail::invalid));

  while (!open.empty()) {
    Node node = detail::OpenPop(open, end, score_g);
    if (node == end) {
      return detail::FindPath(close, end);
    }

    /* node中'x'与上下左右4个方向的数字交换位置 */
    for (int i = 0; i < 4; i++) {
      Node neighbor = node.Neighbor(i);
      if (neighbor == detail::invalid) {
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

Node::Node() {
  memcpy(number, detail::invalid.number, sizeof(number));
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
    return detail::invalid;
  }

  Node ret = *this;
  std::swap(ret.number[xpos], ret.number[npos]);
  return ret;
}


namespace detail {

  Node OpenPop(std::vector<Node> &open, Node end, std::unordered_map<Node, int> &score_g) {
    Node ret = detail::invalid;
    int f = INT_MAX;
    auto i = open.begin();
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

  void OpenErase(std::vector<Node> &open, Node e) {
    for (auto i = open.begin(); i != open.end(); i++) {
      if (e == *i) {
        open.erase(i);
        break;
      }
    }
  }

  std::vector<Node> FindPath(const std::unordered_map<Node, Node> &close, Node e) {
    std::vector<Node> path;
    path.push_back(e);

    while (true) {
      auto from = close.find(e);
      if (from == close.end() || from->second == detail::invalid)
        break;
      path.push_back(from->second);
      e = from->second;
    }
    return path;
  }

}  // namespace detail
