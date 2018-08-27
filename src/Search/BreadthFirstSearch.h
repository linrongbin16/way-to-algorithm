#pragma once
#include <vector>

struct Node {
    int col;
    int row;

    Node();
    explicit Node(int c, int r);
    friend bool operator==(const Node &a, const Node &b);
    friend bool operator!=(const Node &a, const Node &b);
};

std::vector<Node> BreadthFirstSearch(int m, int n, Node beg, Node end);
