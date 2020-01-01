//
// Created by Edwin Fuquen on 12/16/19.
//

#include "std_lib_facilities.h"

int main() {
    cout << "Please enter your first name and age\n";
    string first_name;
    double age;
    cin >> first_name >> age;
    cout << "Hello, " << first_name << " (age " << age * 12 << " months)\n";
    return 0;
}

