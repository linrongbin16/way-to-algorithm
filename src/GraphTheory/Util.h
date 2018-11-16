#pragma once
#include <vector>

struct Edge {
  int u;
  int v;
  int value;
};

template <class T> std::vector<T> ArrayToVector(T *a, int n) {
  std::vector<T> vec;
  for (int i = 0; i < n; i++) {
    vec.push_back(a[i]);
  }
  return vec;
}

