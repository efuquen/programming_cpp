//
// Created by efuquen on 10/20/22.
//

#include "print.h"
#include "fib.h"

#include <vector>

int main() {
    auto v = std::vector<int>();
    fibonacci(1, 2, v, 10);
    print("fib", v);

    return 0;
}