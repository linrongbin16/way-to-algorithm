#pragma once
#include <string>
#include <vector>

struct Node {
    char number[9];

    explicit Node(const std::string &s);
    friend bool operator==(const Node &a, const Node &b);
    friend int operator-(const Node &a, const Node &b);
};

std::vector<Node> AStarSearch(Node beg, Node end);
