#pragma once
#ifndef MAX
#define MAX 1024
#endif
#include <string>
#include <vector>

std::vector<int> KnuthMorrisPratt(const std::string &text,
                                  const std::string &pattern);
