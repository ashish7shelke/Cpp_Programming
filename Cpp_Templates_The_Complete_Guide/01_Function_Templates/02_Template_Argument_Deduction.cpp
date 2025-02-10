#include <iostream>
#include "02_Max.hpp"

int main(void)
{
    int i = 42;
    std::cout << "Inside Main: max(int, int) --> max(" << 7 << "," << i << ") : "<< ::max(7, i) << std::endl << std::endl;

    int const c = 42;
    std::cout << "Inside Main: max(int, const int) --> max(" << i << "," << c << ") : "<< ::max(i, c) << std::endl << std::endl;

    std::cout << "Inside Main: max(const int, const int) --> max(" << c << "," << c << ") : "<< ::max(c, c) << std::endl << std::endl;

    int &ir = i;
    std::cout << "Inside Main: max(int, refrence int) --> max(" << i << "," << ir << ") : "<< ::max(i, ir) << std::endl << std::endl;

    // Codes from Scott Meyers Book
    int x = 27;         // x is an int
    const int cx = x;   // cx is a const int
    const int& rx = x;  // rx is a reference to x as const int

    ::f(x);
    std::cout << "Inside Main: f(int) --> f(" << x << ") : "  << std::endl << std::endl;

    ::f(cx);
    std::cout << "Inside Main: f(const int) --> f(" << cx << ") : "  << std::endl << std::endl;

    ::f(rx);
    std::cout << "Inside Main: f(const int&) --> f(" << rx << ") : "  << std::endl << std::endl;

    return 0;
}