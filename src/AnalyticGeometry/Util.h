#pragma once

/**
 * 二维坐标系节点
 */
struct Node {
    double x;
    double y;
};

/**
 * 二维坐标系向量
 */
struct Vec {
    double x;
    double y;

    Vec(const Node& begin, const Node& end);
};

/**
 * 二维坐标系线段
 */
struct Segment {
    Node left;   // left指代当前线段的左端点 即x坐标较小的点
    Node right;  // right指代当前线段的右端点 即x坐标较大的点
};
