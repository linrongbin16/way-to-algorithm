#include "Sweeping.h"
#include <algorithm>
#include <map>
#include <multimap>
#include <utility>

static bool Compare(const Node& a, const Node& b) {
    //两点x坐标不一致时，取x坐标较小者为先
    if (a.x != b.x) return a.x < b.x;
    //若两点不都是线段左端点或右端点，取左端点者为先
    if (a.left != b.right) return a.left == 1 ? true : false;
    //两点y坐标不一致时，最后取y坐标较小者为先
    if (a.y != b.y) return a.y < b.y;
    //以上三种情况皆不成立
    //即x坐标与y坐标都相同，且都是所在线段的左端点或右端点，可以判断存在相交
    return false;
}

std::multimap<double, Node, std::less<double>>::iterator FindNode(
    std::multimap<double, Node, std::less<double>>& t, const Node& p) {
    //找出扫除线的节点p的迭代器
    for (std::multimap<double, Node, std::less<double>>::iterator i = t.begin();
         i != t.end(); i++)
        if (i->first == p.n_y && i->second == p)
            //迭代器的键值y坐标相等，所映射的点的xy坐标也相等
            return i;
    return t.end();
}

bool Sweeping(Segment* l, int n) {
    //线段集l有n条线段，下标从0到n-1，判断线段集中是否存在相交线段
    //键值double指代点的y坐标
    //映射Node指代y坐标所在点
    std::multimap<double, Node, std::less<double>> T;
    //以键值从小到大排序
    // T维护垂直扫除线当前穿过的线段
    // T按照扫除线与线段的交点的y坐标从小到大排列
    //因为需要查找扫除线某个交点的上下距离最近的交点

    Node s[MAX];  // s是线段集l的点集
    for (int i = 0; i < 2 * n; i += 2) {
        s[i] = l[i / 2].left;
        s[i + 1] = l[i / 2].right;
    }
    //将所有端点按照x坐标从小到大，是否左端点，y坐标从小到大进行排序
    std::sort(s, s + 2 * n, Compare);
    //从左至右进行扫除
    for (int i = 0; i < 2 * n; i++) {
        //扫除线从左向右依次经过
        Node p = s[i];
        if (p.left) {
            //如果p点是其所在线段的左端点，将p点插入T中
            T.insert(std::make_pair(p.n_y, p));
            // above指代T中pos之上距离最近的点
            std::multimap<double, Node, std::less<double>>::iterator above =
                T.end();
            // below指代T中pos之下距离最近的点
            std::multimap<double, Node, std::less<double>>::iterator below =
                T.end();

            // pos指代T中刚刚插入的左端点p
            std::multimap<double, Node, std::less<double>>::iterator pos =
                FindNode(T, p);
            //考虑左端点p和它之上的点above
            if (pos != T.begin()) above = --pos;
            if (above != T.end() &&
                SegmentIntersection(l[(above->second).index],
                                    l[((++pos)->second).index]))
                //若T中pos所在的线段上有线段，并且pos和above所在的两线段相交
                return true;

            //考虑左端点p和它之下的点below
            pos = FindNode(T, p);
            if (pos != T.end() && pos != (--T.end())) below = ++pos;
            if (below != T.end() &&
                SegmentIntersection(l[(below->second).index],
                                    l[((--pos)->second).index]))
                //若T中pos所在的线段下有线段，并且pos与below所在的两线段相交
                return true;
        } else {
            //如果p点是线段右端点，找出p点所在线段
            std::map<double, Node, std::less<double>>::iterator above = T.end();
            std::map<double, Node, std::less<double>>::iterator below = T.end();

            //找出这个右端点p所在线段的左端点，这个左端点已经属于T
            std::map<double, Node, std::less<double>>::iterator pos =
                FindNode(T, l[p.index].left);
            //若p所在线段的左端点pos之上有线段above
            if (pos != T.begin()) above = --pos;

            pos = FindNode(T, l[p.index].left);
            //若p所在线段的左端点pos之下有线段below
            if (pos != T.end() && pos != (--T.end())) below = ++pos;

            if ((above != T.end() && below != T.end()) &&
                SegmentIntersection(l[(above->second).index],
                                    l[(below->second).index]))
                //若pos上下都有线段，且above与below两线段相交
                return true;
            //删除左端点pos
            T.erase(pos);
        }
    }
    return false;
}
