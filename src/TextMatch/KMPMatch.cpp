#include "KMPMatch.h"
#ifndef MAX
#define MAX 1024
#endif
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

std::vector<int> KMPMatch(const std::string& text, const std::string& str)
{
    std::vector<int> pos;
    for (int i = 0; i < text.length(); i++) {
        bool match = true;
        for (int j = 0; j < str.length(); j++) {
            if (text[i + j] != str[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            pos.push_back(i);
        }
    }
    return pos;
}

