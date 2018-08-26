#include "Util.h"

std::vector<int> IntArrayToVector(const int *s, int n) {
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(s[i]);
    }
    return result;
}
