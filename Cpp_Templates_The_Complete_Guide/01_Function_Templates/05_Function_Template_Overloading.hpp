#include <iostream>

namespace Example_1
{
    // Maximum of two integer values
    int max(int a, int b)
    {
        std:: cout << "Inside int max(int, int)" << std::endl;
        return b < a ? a : b;
    }

    // MAximum of two values of any type
    template <typename T>
    T max(T a, T b)
    {
        std:: cout << "Inside T max(T, T)" << std::endl;
        return b < a ? a : b;
    }

}

namespace Example_2
{
    template <typename T1, typename T2>
    auto max(T1 a, T2 b)
    {
        std:: cout << "Inside auto max(T1 a, T2 b)" << std::endl;
        return b < a ? a : b; 
    }

    template <typename RT, typename T1, typename T2>
    RT max(T1 a, T2 b)
    {
        std:: cout << "Inside RT max(T1 a, T2 b)" << std::endl;
        return b < a ? a : b; 
    }
}



