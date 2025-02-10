#include <iostream>
#include "05_Function_Template_Overloading.hpp"
int main(void)
{

    // Eample 1
    std::cout << "*** Example 1 ***" << std::endl;
    std::cout << "max(" << 7 << "," << 42 << ") : "<< Example_1::max(7, 42) << std::endl << std::endl;

    std::cout << "max(" << 7.11 << "," << 42.11 << ") : "<< Example_1::max(7.11, 42.11) << std::endl << std::endl;

    std::cout << "max(" << 'a' << "," << 'b' << ") : "<< Example_1::max('a', 'b') << std::endl << std::endl;

    std::cout << "max<>(" << 7 << "," << 42 << ") : "<< Example_1::max<>(7, 42) << std::endl << std::endl;

    std::cout << "max<double>(" << 7.11 << "," << 42.11 << ") : "<< Example_1::max<double>(7.11, 42.11) << std::endl << std::endl;

    std::cout << "max(" << 'a' << "," << 42.11 << ") : "<< Example_1::max('a', 42.11) << std::endl << std::endl;

    //Example 2
    std::cout << "*** Example 2 ***" << std::endl;
    auto ret = Example_2::max(4, 7.2);
    std::cout << "max(" << 4 << "," << 7.2 << ") : "<< ret << std::endl << std::endl;

    auto ret_2 = Example_2::max<long double>(7.2, 4);
    std::cout << "max(" << 7.2 << "," << 4 << ") : "<< ret_2 << std::endl << std::endl;

    /*auto ret_3 = Example_2::max<int>(4, 7.2); // ERROR : both remplate matches
    std::cout << "max(" << 4 << "," << 7.2 << ") : "<< ret_3 << std::endl << std::endl;*/ 
    // TYPEID prints are pending

    return 0;
}