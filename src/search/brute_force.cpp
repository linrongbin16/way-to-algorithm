// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "brute_force.h"
#include <iostream>

std::vector<int> int_array_to_vector(int *s, int n) {
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(s[i]);
    }
    return result;
}

std::vector<std::vector<int>> brute_force(int *s, int n, int m) {
    std::vector<std::vector<int>> result;
    for (int i_0 = 0; i_0 < m; i_0++)
        for (int i_1 = 0; i_1 < m; i_1++)
            for (int i_2 = 0; i_2 < m; i_2++)
                /* ... */
                for (int i_n_1 = 0; i_n_1 < m; i_n_1++) {
                    s[0] = i_0;
                    s[1] = i_1;
                    s[2] = i_2;
                    /* ... */
                    s[n - 1] = i_n_1;
                    result.push_back(int_array_to_vector(s, n));
                }
    return result;
}
