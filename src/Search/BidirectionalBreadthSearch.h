#pragma once
#include "Util.h"
#include <deque>
#ifndef MAX
#define MAX 128
#endif

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param n     行
 * @param m     列
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
 */
std::deque<BfsNode> BidirectionalBreadthSearch(int n, int m, const BfsNode &beg,
                                               const BfsNode &end);

