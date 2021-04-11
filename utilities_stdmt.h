#pragma once

// Useful functions
// getInput examples:
// {
//     string a = getInput(string{"A"}, string{"zzzz"});
//     char b = getInput('a', 'z');
//     int c = getInput(-10, 10);
//     double d = getInput(-100.0, 100.0);
//     int n = getInputInt();
// }
// Check ASCII Chart for ranges:
// https://en.cppreference.com/w/cpp/language/ascii

#include <iostream>
#include <numeric>
#include <string>

namespace stdmt {

template <typename T>
T getInput(T lower, T upper) {
    T input;
    for (;;) {
        std::cout << "Input: ";
        std::cin >> input;
        if (std::cin && input >= lower && input <= upper) {
            std::cin.ignore(256, '\n');
            return input;
        }
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Incorrect input, try again!\n";
    }
}

inline int getInputIntV2(int lower = INT_MIN, int upper = INT_MAX) {
    std::string input;
    for (;;) {
        std::cout << "Input: ";
        std::cin >> input;
        try {
            int n = std::stoi(input);
            if (n >= lower && n <= upper) {
                std::cin.ignore(256, '\n');
                return n;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Incorrect input, try again!\n";
    }
}

}  // namespace stdmt
