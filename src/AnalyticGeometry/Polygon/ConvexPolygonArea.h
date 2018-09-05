#pragma once
#include "../Util.h"

/**
 * @param a     三角形端点数组
 * @param n     三角形端点数量
 * @return      三角形面积
 */
double TriangleArea(const Node &a, const Node &b, const Node &c);

/**
 * @param a     凸多边形端点数组
 * @param n     凸多边形端点数量
 * @return      凸多边形面积
 */
double ConvexPolygonArea(Node *a, int n);

