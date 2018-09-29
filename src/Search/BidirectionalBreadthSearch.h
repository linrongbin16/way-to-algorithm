#pragma once
#include "Util.h"
#include <cassert>
#include <cstring>
#include <deque>
#include <utility>
#include <vector>
#ifndef MAX
#define MAX 128
#endif

/**
 * BidirectionalBreadthSearch 双向广度搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从起点到终点的座标路径
 */
std::deque<BfsNode> BidirectionalBreadthSearch(int m, int n, const BfsNode &beg,
                                               const BfsNode &end);

