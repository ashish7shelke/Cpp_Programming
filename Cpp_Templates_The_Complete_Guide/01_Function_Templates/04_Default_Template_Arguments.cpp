#include <iostream>
#include "04_Default_Template_Arguments.hpp"

int main(void)
{
    // Template Parameters for Return Types
    // Instantiate T as double, int is also deduced as float
    auto ret = ::max_with_common_type_t(4, 6.2);
    std::cout << "max(" << 4 << "," << 6.2 << ") : "<< ret << std::endl;

    auto ret_1 = ::max_with_common_type_t<int, double, double>(7, 6.2);
    std::cout << "max(" << 7 << "," << 6.2 << ") : "<< ret_1 << std::endl;

    // TYPEID prints are pending

    return 0;
}