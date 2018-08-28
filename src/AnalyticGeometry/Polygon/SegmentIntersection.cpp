#include "SegmentIntersection.h"
#include "Cross.h"
#include <algorithm>

static bool OnSegment(Segment s, Node n) {
  //判断点n是否在线段s的x和y坐标区间内
  return n.x >= std::min(s.left.x, s.right.x) &&
         n.x <= std::max(s.left.x, s.right.x) &&
         n.y >= std::min(s.left.y, s.right.y) &&
         n.y <= std::max(s.left.y, s.right.y);
}

int SegmentIntersection(const Segment &s1, const Segment &s2) {
  //若s1和s2中不存在一端点在另一线段上的情况，且相交，返回1
  //若s1和s2中一端点在另一线段上，返回2
  //若s1和s2不相交返回0
  double d1 = Cross(Vec(s2.left, s2.right), Vec(s2.left, s1.left));
  double d2 = Cross(Vec(s2.left, s2.right), Vec(s2.left, s1.right));
  double d3 = Cross(Vec(s1.left, s1.right), Vec(s1.left, s2.left));
  double d4 = Cross(Vec(s1.left, s1.right), Vec(s1.left, s2.right));

  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
      ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    //若存在s1两端点在s2直线不同两侧，且s2两端点在s1直线不同两侧
    //即可判定s1，s2线段相交
    //该判断条件也可写作d1 * d2 < 0 && d3 * d4 < 0
    return 1;
  if (d1 == 0 && OnSegment(s2, s1.left))
    //若s1上左端点在s2所在直线上
    //判断该端点是否位于线段s2上，后面的判断类似
    return 2;
  if (d2 == 0 && OnSegment(s2, s1.right))
    return 2;
  if (d3 == 0 && OnSegment(s1, s2.left))
    return 2;
  if (d4 == 0 && OnSegment(s1, s2.right))
    return 2;
  //不属于上述情况的s1和s2不相交
  return 0;
}

