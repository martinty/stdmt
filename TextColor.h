#pragma once

// Martin Tysseland - 08.04.2021
// Class for changing the text color in the terminal (windows and Linux).
// NB!: Only for windows: TextColor.h" allways needs to be included over
// "std_lib_facilities.h".
// This example will print the text in blue and change it back to white after:
// {
//     cout << TextColor{ColorId::blue} << "This line is blue!\n" <<
//     TextColor{};
// }
// Can also make variables:
// {
//     TextColor blue{ColorId::blue};
//     TextColor white;  // white is defualt color
//     cout << blue << "This line is blue!\n" << white;
// }

#ifndef __APPLE__

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

namespace stdmt {

enum class ColorId {
#ifdef __linux__
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    black_bright = 90,
    red_bright = 91,
    green_bright = 92,
    yellow_bright = 93,
    blue_bright = 94,
    magenta_bright = 94,
    cyan_bright = 96,
    white_bright = 97,
#elif _WIN32
    black = 0,
    blue = 1,
    green = 2,
    cyan = 3,
    red = 4,
    magenta = 5,
    yellow = 6,
    white = 7,
    black_bright = 8,
    blue_bright = 9,
    green_bright = 10,
    cyan_bright = 11,
    red_bright = 12,
    magenta_bright = 13,
    yellow_bright = 14,
    white_bright = 15
#endif
};

class TextColor {
   private:
    const int color;
#ifdef _WIN32
    HANDLE hConsole;
#endif

   public:
    TextColor(ColorId c = ColorId::white) : color((int)c) {
#ifdef _WIN32
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
    }
    ~TextColor() = default;
    friend std::ostream& operator<<(std::ostream& os, const TextColor& text) {
#ifdef __linux__
        os << "\033[" << text.color << "m";
#elif _WIN32
        SetConsoleTextAttribute(text.hConsole, text.color);
#endif
        return os;
    }
};

}  // namespace stdmt

#endif  // __APPLE__
