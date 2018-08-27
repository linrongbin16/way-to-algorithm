#include "general_head.h"
#include "geometry.h"
// cross.cpp
extern double cross(vec v1, vec v2);
bool on_segment(segment l, node p);

int segments_intersection(
    segment l1,
    segment l2) {  //若l1和l2中不存在一端点在另一线段上的情况，且相交，返回1
                   //若l1和l2中一端点在另一线段上，返回2
                   //若l1和l2不相交返回0
    double d1 = cross(vec(l2.s_lt, l2.s_rt), vec(l2.s_lt, l1.s_lt));
    double d2 = cross(vec(l2.s_lt, l2.s_rt), vec(l2.s_lt, l1.s_rt));
    double d3 = cross(vec(l1.s_lt, l1.s_rt), vec(l1.s_lt, l2.s_lt));
    double d4 = cross(vec(l1.s_lt, l1.s_rt), vec(l1.s_lt, l2.s_rt));

    if (((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and
        ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)))
        //若存在l1两端点在l2直线不同两侧，且l2两端点在l1直线不同两侧
        //即可判定l1，l2线段相交
        //该判断条件也可写作d1 * d2 < 0 and d3 * d4 < 0
        return (1);
    if (d1 == 0 and on_segment(l2, l1.s_lt))
        //若l1上左端点在l2所在直线上
        //判断该端点是否位于线段l2上，后面的判断类似
        return (2);
    if (d2 == 0 and on_segment(l2, l1.s_rt)) return (2);
    if (d3 == 0 and on_segment(l1, l2.s_lt)) return (2);
    if (d4 == 0 and on_segment(l1, l2.s_rt)) return (2);
    //不属于上述情况的l1和l2不相交
    return (0);
}
bool on_segment(segment l, node p) {  //判断点p是否在线段l的x和y坐标区间内
    return (p.n_x >= min(l.s_lt.n_x, l.s_rt.n_x) and
            p.n_x <= max(l.s_lt.n_x, l.s_rt.n_x) and
            p.n_y >= min(l.s_lt.n_y, l.s_rt.n_y) and
            p.n_y <= max(l.s_lt.n_y, l.s_rt.n_y));
}
