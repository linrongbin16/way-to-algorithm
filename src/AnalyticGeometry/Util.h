// Util.h
#pragma once

/**
 * 二维坐标系节点
 */
struct Node {
  double x;  // x轴坐标
  double y;  // y轴坐标
  int index; // 节点标号

  Node();
  Node(const double &x, const double &y);
  Node(const double &x, const double &y, const int &index);
  Node(const Node &n);
  Node(const Node &n, const int &index);
};

/**
 * 二维坐标系向量
 */
struct Vec {
  double x; // x轴长度
  double y; // y轴长度

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
  int index;  // 线段标号

  Segment();
  Segment(const Node &left, const Node &right);
  Segment(const Node &left, const Node &right, const int &index);
  Segment(const Segment &s);
  Segment(const Segment &s, const int &index);
};

double NodeDistance(const Node &a, const Node &b);

// double eq
bool FloatEq(const double &a, const double &b);

// float eq
bool FloatEq(const float &a, const float &b);

// Node eq
bool NodeEq(const Node &a, const Node &b);

