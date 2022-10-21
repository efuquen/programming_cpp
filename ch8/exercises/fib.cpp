//
// Created by efuquen on 10/20/22.
//

#include "fib.h"

#include <vector>

void fibonacci(int x, int y, std::vector<int> &v, int n) {
    v.push_back(x);
    v.push_back(y);
    for(int i = 0; i < n; i++) {
        v.push_back(v.at(i) + v.at(i + 1));
    }
}