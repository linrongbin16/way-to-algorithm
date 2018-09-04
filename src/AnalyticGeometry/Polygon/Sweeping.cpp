#include "Sweeping.h"
#include "../Util.h"
#include "SegmentIntersection.h"
#include <algorithm>
#include <map>
#include <utility>

// key为端点y坐标 value为端点
typedef std::multimap<double, Node, std::less<double>> T;
typedef std::multimap<double, Node, std::less<double>>::iterator TIter;
#define TKey(iter) ((iter)->first)
#define TValue(iter) ((iter)->second)

int is_left_node[MAX];

//端点排序
static bool Compare(const Node &a, const Node &b) {
  // x坐标不同 x坐标较小的优先
  if (!FloatEq(a.x, b.x))
    return a.x < b.x;

  // 若两点一个是左端点一个是右端点 左端点优先
  if (is_left_node[a.index] != is_left_node[b.index])
    return (is_left_node[a.index]) ? true : false;

  // y坐标不同 y坐标较小的优先
  if (!FloatEq(a.y, b.y))
    return a.y < b.y;

  return false;
}

static TIter Find(T &t, const Node &p) {
  std::pair<TIter, TIter> range = t.equal_range(p.y);
  for (TIter i = range.first; i != range.second; i++) {
    if (NodeEq(TValue(i), p)) {
      return i;
    }
  }
  return t.end();
}

static void Insert(T &t, const Node &p) { t.insert(std::make_pair(p.y, p)); }

static void Erase(T &t, const Node &p) {
  TIter i = Find(t, p);
  if (i != t.end()) {
    t.erase(i);
  }
}

static TIter Above(T &t, const Node &p) {
  TIter i = Find(t, p);
  if (i == t.end()) {
    return t.end();
  }
  if (i == t.begin()) {
    return t.end();
  }
  return --i;
}

static TIter Below(T &t, const Node &p) {
  TIter i = Find(t, p);
  if (i == t.end()) {
    return t.end();
  }
  if (i == t.begin()) {
    return t.end();
  }
  return ++i;
}

bool Sweeping(Segment *l, int n) {
  // 键值double指代点的y坐标
  // 映射Node指代y坐标所在点
  T t;
  std::memset(is_left_node, 0, MAX * sizeof(int));

  // s是线段集l的端点集
  Node s[MAX];
  for (int i = 0; i < n; i++) {
    s[l[i].left.index] = l[i].left;
    s[l[i].right.index] = l[i].right;
    // 标记某点为左端点/右端点
    is_left_node[l[i].left.index] = 1;
    is_left_node[l[i].right.index] = 0;
  }
  std::sort(s, s + 2 * n, Compare);

  // 从左至右
  for (int i = 0; i < 2 * n; i++) {
    Node p = s[i];
    // 若p为左端点
    if (is_left_node[p.index]) {
      Insert(t, p);
      TIter above_p = Above(t, p);
      TIter below_p = Below(t, p);

      if (above_p != t.end() &&
          SegmentIntersection(l[TValue(above_p).index], l[p.index]))
        return true;

      if (below_p != t.end() &&
          SegmentIntersection(l[TValue(below_p).index], l[p.index]))
        return true;

    } else {
      // 若p为右端点
      TIter above_p = Above(t, p);
      TIter below_p = Below(t, p);

      if (above_p != t.end() && below_p != t.end() &&
          SegmentIntersection(l[TValue(above_p).index],
                              l[TValue(below_p).index]))
        return true;

      Erase(t, p);
    }
  }
  return false;
}

