#pragma once
#include "Util.h"
#include <vector>
#ifndef MAX
#define MAX 128
#endif

/**
 * BreadthFirstSearch 广度优先搜索
 * @param m     列col
 * @param n     行row
 * @param beg   起点座标
 * @param end   终点座标
 * @return      从beg到end的搜索路径
 */
std::vector<BfsNode> BreadthFirstSearch(int m, int n, const BfsNode &beg,
                                        const BfsNode &end);

