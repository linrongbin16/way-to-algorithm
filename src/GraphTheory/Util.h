#pragma once
#include <vector>

struct Vertex {
  int index;
  int value;

  Vertex();
  Vertex(int index, int value);
  Vertex(const Vertex &other);
  Vertex &operator=(const Vertex &other);

  friend bool operator!=(const Vertex &a, const Vertex &b);
  friend bool operator==(const Vertex &a, const Vertex &b);
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

  friend bool operator!=(const Edge &a, const Edge &b);
  friend bool operator==(const Edge &a, const Edge &b);
};

