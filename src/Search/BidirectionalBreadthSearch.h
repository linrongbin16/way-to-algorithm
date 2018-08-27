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
    friend bool operator==(const Node& a, const Node& b);
    friend bool operator!=(const Node& a, const Node& b);
};

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
 */
std::deque<Node> BidirectionalBreadthSearch(int m, int n, Node beg, Node end);
