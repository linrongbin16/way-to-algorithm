#include "SegmentIntersection.h"
#include <cassert>
using namespace std;

int main() {
  Segment s1(Node(0.0f, 0.0f), Node(1.0f, 0.0f));
  Segment s2(Node(0.0f, 0.0f), Node(0.0f, 1.0f));
  Segment s3(Node(0.0f, 0.0f), Node(1.0f, 1.0f));
  Segment s4(Node(0.0f, 0.0f), Node(2.0f, 0.5f));
  Segment s5(Node(1.0f, 0.0f), Node(1.0f, 1.5f));
  Segment s6(Node(0.0f, 2.0f), Node(1.0f, 0.5f));

  assert(SegmentIntersection(s1, s2));
  assert(SegmentIntersection(s3, s4));
  assert(SegmentIntersection(s4, s5));
  assert(!SegmentIntersection(s2, s5));
  assert(!SegmentIntersection(s1, s6));
  assert(!SegmentIntersection(s2, s6));
  return 0;
}
