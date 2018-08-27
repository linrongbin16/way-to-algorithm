#pragma once
#include <cassert>
#include <cstring>
#include <deque>
#include <utility>
#include <vector>

struct Node {
    int col;
    int row;

    Node();
    explicit Node(int c, int r);
    friend bool operator==(const Node &a, const Node &b);
    friend bool operator!=(const Node &a, const Node &b);
};

std::deque<Node> BidirectionalBreadthSearch(int m, int n, Node beg, Node end);
