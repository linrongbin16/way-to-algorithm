#include "Util.h"
#include <algorithm>
#include <cmath>

bool FloatEq(const double &a, const double &b) {
  return std::abs(a - b) <= (double)0.000001f;
}

bool FloatEq(const float &a, const float &b) {
  return std::abs(a - b) <= (float)0.000001f;
}

Node::Node() {
  this->x = 0;
  this->y = 0;
  this->index = 0;
}

Node::Node(const double &x, const double &y) {
  this->x = x;
  this->y = y;
  this->index = 0;
}

Node::Node(const double &x, const double &y, const int &index) {
  this->x = x;
  this->y = y;
  this->index = index;
}

Node::Node(const Node &n) {
  this->x = n.x;
  this->y = n.y;
  this->index = n.index;
}

Node::Node(const Node &n, const int &index) {
  this->x = n.x;
  this->y = n.y;
  this->index = index;
}

bool NodeEq(const Node &a, const Node &b) {
  if (&a == &b) {
    return true;
  }
  return FloatEq(a.x, b.x) && FloatEq(a.y, b.y) && a.index == b.index;
}

Vec::Vec(const double &x, const double &y) {
  this->x = x;
  this->y = y;
}

Vec::Vec(const Node &begin, const Node &end) {
  this->x = end.x - begin.x;
  this->y = end.y - begin.y;
}

Vec::Vec(const Vec &v) {
  this->x = v.x;
  this->y = v.y;
}

Segment::Segment() {}

Segment::Segment(const Node &left, const Node &right) {
  this->left = left;
  this->right = right;
  this->index = 0;
}

Segment::Segment(const Node &left, const Node &right, const int &index) {
  this->left = left;
  this->right = right;
  this->index = index;
}

Segment::Segment(const Segment &s) {
  this->left = s.left;
  this->right = s.right;
  this->index = s.index;
}

Segment::Segment(const Segment &s, const int &index) {
  this->left = s.left;
  this->right = s.right;
  this->index = index;
}

double NodeDistance(const Node &a, const Node &b) {
  return std::sqrt(std::pow<double>(b.x - a.x, 2.0f) +
                   std::pow<double>(b.y - a.y, 2.0f));
}

