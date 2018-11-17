#include "Util.h"

Vertex::Vertex() {}

Vertex::Vertex(int index, int value) : index(index), value(value) {}

Vertex::Vertex(const Vertex &other) : index(other.index), value(other.value) {}

Vertex &Vertex::operator=(const Vertex &other) {
  if (&other == this) {
    return *this;
  }
  index = other.index;
  value = other.value;
  return *this;
}

Edge::Edge() {}

Edge::Edge(int u, int v) : u(u), v(v) {}

Edge::Edge(int u, int v, int value) : u(u), v(v), value(value) {}

Edge::Edge(const Edge &e) : u(e.u), v(e.v), value(e.value) {}

Edge &Edge::operator=(const Edge &e) {
  if (&e == this) {
    return *this;
  }
  u = e.u;
  v = e.v;
  value = e.value;
  return *this;
}

