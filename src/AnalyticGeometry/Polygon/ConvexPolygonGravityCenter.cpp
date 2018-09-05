#include "ConvexPolygonGravityCenter.h"
#include "../Util.h"
#include "ConvexPolygonArea.h"

Node TriangleGravityCenter(const Node &a, const Node &b, const Node &c) {
  return Node();
}

Node ConvexPolygonGravityCenter(Node *a, int n) {
  Node p(0, 0);

  //划分的三角形重心
  Node center[MAX];
  //划分的三角形面积
  double area[MAX];

  for (int i = 0; i < n; ++i) {
    if (i != n - 1) {
      center[i] = TriangleGravityCenter(p, a[i], a[i + 1]);
      area[i] = TriangleGravityCenter(p, a[i], a[i + 1]);
    }
  }
  double a_sum(0);
  pair<double, double> o_sum(0, 0);
  for (int i = 0; i < n; ++i)
    a_sum += area[i];
  for (int i = 0; i < n; ++i) {
    o_sum.first += o[i].first * area[i];
    o_sum.second += o[i].second * area[i];
  }
  return (make_pair(o_sum.first / a_sum, o_sum.second / a_sum));
}
pair<double, double>
triangle_gravity_center(node a, node b,
                        node c) { //三角形顶点是a，b，c三点，返回三角形重心
  return (make_pair((a.n_x + b.n_x + c.n_x) / 3, (a.n_y + b.n_y + c.n_y) / 3));
}

