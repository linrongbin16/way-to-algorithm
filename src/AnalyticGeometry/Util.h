// Util.h
#pragma once

/**
 * 二维坐标系节点
 */
struct Node {
  double x;
  double y;

  Node();
  Node(const double &x, const double &y);
  Node(const Node &n);
};

/**
 * 二维坐标系向量
 */
struct Vec {
  double x;
  double y;

  Vec(const double &x, const double &y);
  Vec(const Node &begin, const Node &end);
  Vec(const Vec &v);
};

/**
 * 二维坐标系线段
 */
struct Segment {
  Node left;  // left指代当前线段的左端点 即x坐标较小的点
  Node right; // right指代当前线段的右端点 即x坐标较大的点

  Segment();
  Segment(const Node &left, const Node &right);
  Segment(const Segment &s);
};

double NodeDistance(const Node &a, const Node &b);

// ==
bool FloatEq(const double &a, const double &b);

bool FloatEq(const float &a, const float &b);

