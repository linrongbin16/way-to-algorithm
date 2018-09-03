#include "SegmentIntersection.h"
#include "Cross.h"
#include <algorithm>

//判断点n是否在线段s的x和y坐标区间内
static bool OnSegment(const Segment &s, const Node &n) {
  return n.x >= std::min(s.left.x, s.right.x) &&
         n.x <= std::max(s.left.x, s.right.x) &&
         n.y >= std::min(s.left.y, s.right.y) &&
         n.y <= std::max(s.left.y, s.right.y);
}

bool SegmentIntersection(const Segment &s1, const Segment &s2) {
  Vec v1 = Vec(s2.left, s2.right);
  Vec v2 = Vec(s2.left, s1.left);
  Vec v3 = Vec(s2.left, s1.right);
  Vec v4 = Vec(s1.left, s1.right);
  Vec v5 = Vec(s1.left, s2.left);
  Vec v6 = Vec(s1.left, s2.right);
  double d1 = Cross(v1, v2);
  double d2 = Cross(v1, v3);
  double d3 = Cross(v4, v5);
  double d4 = Cross(v4, v6);

  //两线段相交
  // d1 d2一正一负
  // d3 d4一正一负
  if (d1 * d2 < 0.0f && d3 * d4 < 0.0f)
    return true;

  //一线段在另一线段上
  if (d1 == 0.0f && OnSegment(s2, s1.left))
    return true;
  if (d2 == 0.0f && OnSegment(s2, s1.right))
    return true;
  if (d3 == 0.0f && OnSegment(s1, s2.left))
    return true;
  if (d4 == 0.0f && OnSegment(s1, s2.right))
    return true;

  //不相交
  return false;
}

