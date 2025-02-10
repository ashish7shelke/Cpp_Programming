#include <iostream>
#include "06_Function_Template_Overloading.hpp"

int main()
{
    int a = 7;
    int b = 42;

    auto m1 = ::max(a, b);
    std::cout << "max(" << a << "," << b << ") : "<< m1 << std::endl << std::endl;

    std::string s1 = "hey";
    std::string s2 = "you";
    auto m2 = ::max(s1, s2);
    std::cout << "max(" << s1 << "," << s2 << ") : "<< m2 << std::endl << std::endl;

    int* p1 = &b;
    int* p2 = &a;
    auto m3 = ::max(p1, p2);
    std::cout << "max(" << *p1 << "," << *p2 << ") : "<< *m3 << std::endl << std::endl;

    char const* x = "hello";
    char const* y = "world";
    auto m4 = ::max(x, y);
    std::cout << "max(" << *x << "," << *y << ") : "<< *m4 << std::endl << std::endl;
    
    return 0;
}