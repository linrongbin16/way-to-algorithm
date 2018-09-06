#include "ConvexPolygonGravityCenter.h"
#include "../Util.h"
#include "ConvexPolygonArea.h"
#include <utility>

Node TriangleGravityCenter(const Node &a, const Node &b, const Node &c) {
  double x = (a.x + b.x + c.x) / (double)3.0f;
  double y = (a.y + b.y + c.y) / (double)3.0f;
  return Node(x, y);
}

Node ConvexPolygonGravityCenter(Node *a, int n) {
  Node p(0, 0);

  //划分的三角形重心
  Node center[MAX];
  //划分的三角形面积
  double area[MAX];

  for (int i = 0; i < n; i++) {
    if (i != n - 1) {
      center[i] = TriangleGravityCenter(p, a[i], a[i + 1]);
      area[i] = TriangleArea(p, a[i], a[i + 1]);
    }
  }

  double sum_area = 0.0f;
  Node sum_center(0.0f, 0.0f);
  for (int i = 0; i < n; i++)
    sum_area += area[i];
  for (int i = 0; i < n; i++) {
    sum_center.x += center[i].x * area[i];
    sum_center.y += center[i].y * area[i];
  }
  return Node(sum_center.x / sum_area, sum_center.y / sum_area);
}

