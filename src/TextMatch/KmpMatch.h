#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <string>
#include <vector>

std::vector<int> KmpMatch(const std::string &text, const std::string &str);
