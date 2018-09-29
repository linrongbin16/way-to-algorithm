#include "ConvexPolygonGravityCenter.h"
#include "../Util.h"
#include <cassert>

#define TEST_MAX 16

struct TriangleTest {
  Node a;
  Node b;
  Node c;
  Node result;
} triangle_tests[] = {
    {
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.0f, 1.0f},
        {0.5f, 0.333333f},
    },
    {
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {0.0f, 1.0f},
        {0.5f, 0.333333f},
    },
};

struct ConvexTest {
  Node a[TEST_MAX];
  int n;
  Node result;
} convex_tests[] = {
    {
        {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}},
        3,
        {0.5f, 0.333333f},
    },
    {
        {{0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}},
        4,
        {0.5f, 0.5f},
    },
    {
        {{0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.5f, 2.0f}, {0.0f, 1.0f}},
        5,
        {0.5f, 1.0f},
    },
};

int main() {
  for (int i = 0; i < sizeof(triangle_tests) / sizeof(TriangleTest); i++) {
    TriangleTest &t = triangle_tests[i];
    assert(NodeEq(TriangleGravityCenter(t.a, t.b, t.c), t.result));
  }
  for (int i = 0; i < sizeof(convex_tests) / sizeof(ConvexTest); i++) {
    TriangleTest &t = triangle_tests[i];
    assert(NodeEq(TriangleGravityCenter(t.a, t.b, t.c), t.result));
  }
  return 0;
}
