#pragma once
#include <climits>
#include <string>
#include <vector>
#ifndef MAX
#define MAX 9
#endif
#ifndef INF
#define INF INT_MAX
#endif

extern int a_star_dir[4];
std::vector<const char *> AStarSearch(const char *beg, const char *end);

