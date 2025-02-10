#include <iostream>
#include <string>
#include "01_Max.hpp"

int main()
{
    
    int i = 42;
    std::cout << "T is deduced to INT: max(" << 7 << "," << i << ") : "<< ::max(7, i) << std::endl;
    // :: it ensure our max() template found in global namespace. std::max may also gets called 

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "T is deduced to FLOAT: max(" << f1 << "," << f2 << ") : "<< ::max(f1, f2) << std::endl;

    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "T is deduced to STRING: max(" << s1 << "," << s2 << ") : "<< ::max(s1, s2) << std::endl;

    return 0;
}
