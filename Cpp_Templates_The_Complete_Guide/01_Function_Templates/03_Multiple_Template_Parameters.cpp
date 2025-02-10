#include <iostream>
#include "03_Multiple_Template_Parameters.hpp"

int main(void)
{
    double f1 = 3.4;
    double f2 = -6.7;
    int i = 42;
    // Template Parameters for Return Types
    // Instantiate T as double, int is also deduced as float
    std::cout << "max(" << f1 << "," << f2 << ") : "<< ::max<double, double, double>(f1, f2) << std::endl;

    //Deducing the return type
    std::cout << "max_with_auto(" << f1 << "," << f2 << ") : "<< ::max_with_auto(f2, f2) << std::endl;

    std::cout << "max_with_auto_decltype_decayed(" << i << "," << f2 << ") : "<< ::max_with_auto(i, f2) << std::endl;

    std::cout << "max_with_commontrait(" << f2 << "," << -7 << ") : "<< ::max_with_commontrait(f2, -7) << std::endl;

    // TYPEID prints are pending

    return 0;
}