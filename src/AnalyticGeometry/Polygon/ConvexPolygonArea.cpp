#include "ConvexPolygonArea.h"
#include "Cross.h"
#include <cmath>

//三角形面积
double TriangleArea(const Node &a, const Node &b, const Node &c) {
  Vec v1 = Vec(a, b);
  Vec v2 = Vec(a, c);
  return std::abs(Cross(v1, v2) / 2.0f);
}

//凸多边形面积
double ConvexPolygonArea(Node *a, int n) {
  double area = 0.0f;
  Node p = a[0];
  for (int i = 1; i < n; i++) {
    double tmp_area = 0.0f;
    if (i != n - 1) {
      tmp_area = TriangleArea(p, a[i], a[i + 1]);
    }
    area += tmp_area;
  }

  return area;
}

