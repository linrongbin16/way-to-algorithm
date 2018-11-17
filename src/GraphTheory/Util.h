#pragma once
#include <vector>

struct Vertex {
  int index;
  int value;

  Vertex();
  Vertex(int index, int value);
  Vertex(const Vertex &other);
  Vertex &operator=(const Vertex &other);
};

struct Edge {
  int u;
  int v;
  int value;

  Edge();
  Edge(int u, int v);
  Edge(int u, int v, int value);
  Edge(const Edge &e);
  Edge &operator=(const Edge &e);
};

template <class T> std::vector<T> ArrayToVector(T *a, int n) {
  std::vector<T> vec;
  for (int i = 0; i < n; i++) {
    vec.push_back(a[i]);
  }
  return vec;
}

