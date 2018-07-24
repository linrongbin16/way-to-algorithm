// MIT License
// Copyright 2018 linrongbin16@gmail.com

#pragma once
#include <vector>

struct Node {
  char number[9];
};

std::vector<Node> AStarSearch(Node beg, Node end);
