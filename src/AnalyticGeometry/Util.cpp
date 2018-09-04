#include "Util.h"
#include <cmath>

Node::Node() {
  this->x = 0;
  this->y = 0;
}

Node::Node(const double &x, const double &y) {
  this->x = x;
  this->y = y;
}

Node::Node(const Node &n) {
  this->x = n.x;
  this->y = n.y;
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
}

Segment::Segment(const Segment &s) {
  this->left = s.left;
  this->right = s.right;
}

double NodeDistance(const Node &a, const Node &b) {
  return std::sqrt(std::pow<double>(b.x - a.x, 2.0f) +
                   std::pow<double>(b.y - a.y, 2.0f));
}

