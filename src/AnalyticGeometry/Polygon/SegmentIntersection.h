#pragma once
#include "../Util.h"

/**
 * @return 0 若两线段不相交
 * @return 1 若两线段相交，且不存在一个端点在另一个线段上的情况
 * @return 2 若两线段中一个端点在另一个线段上
 */
int SegmentIntersection(const Segment &s1, const Segment &s2);

