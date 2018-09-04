#pragma once
#include "../Util.h"
#ifndef MAX
#define MAX 1024
#endif

/**
 * @param s   一组线段
 * @param n   线段数量
 * @return    true存在相交 false不存在
 */
bool Sweeping(Segment *s, int n);

