#pragma once
#include "../Util.h"
#ifndef MAX
#define MAX 128
#endif

/**
 * @param a     三角形端点数组
 * @param n     三角形端点数量
 * @return      三角形重心坐标点
 */
Node TriangleGravityCenter(const Node &a, const Node &b, const Node &c);

/**
 * @param a     凸多边形端点数组
 * @param n     凸多边形端点数量
 * @return      凸多边形重心坐标点
 */
Node ConvexPolygonGravityCenter(Node *a, int n);

