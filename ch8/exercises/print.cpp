//
// Created by efuquen on 10/20/22.
//

#include "print.h"

#include <iostream>
#include <string>
#include <vector>

void print(std::string label, const std::vector<int> &vints) {
    std::cout << label << ": [";
    bool first = true;
    for(auto &vint : vints) {
        if(!first) {
            std::cout << ", ";
        }
        std::cout << vint;
        first = false;
    }
    std::cout << "]\n";
}