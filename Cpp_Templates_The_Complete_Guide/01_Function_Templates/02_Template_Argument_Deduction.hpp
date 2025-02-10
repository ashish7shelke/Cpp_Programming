/*
    This assignment includes content from book
    Effective Modern C++, 42 Specific Ways to ImprioveYour Use Of C++11 and C++17 by Scott Meyers

    Item 1: Understand template Type deduction

    template <typename T>
    void f(ParamType param){}

    f(expr);

    Compiler use 'expr' to deduce two types: 
    1) T
    2) ParamType
    These types are frequently different, because ParamType often caontains const or reference qualifiers 

    Case 1: ParamType is a Pointer or reference (non-universal)
    Case 2: ParamType is a Universal Reference
    Case 3: ParamType is a Pass-by-value (neither pointer nor reference) 

    TYPEID Prints are pending
*/


#include <typeinfo>
// Function template that returns maximum of two values

template <typename T>
T max(T a, T b)
{
    // if b << a then yeild a  else yeild b

    std::cout << "Inside T max(T a, T b): Type T is deduced to : " << typeid(T).name() << std::endl;
    std::cout << "Inside T max(T a, T b): ParamType is deduced to : " << typeid(a).name() << std::endl;
    return b < a ? a : b;
}

/*template <typename T>
T max(T const& a, T const& b)
{
    std::cout << "Inside Template function: Type T is deduced to : " << typeid(T).name() << std::endl;
    return b < a ? a : b;
}*/

// Codes from Scott Meyers Book
template <typename T>
void f(T& param)
{
    std::cout << "Inside void f(T& param): Type T is deduced to : " << typeid(T).name() << std::endl;
    std::cout << "Inside void f(T& param): Type ParamType is deduced to : " << typeid(param).name() << std::endl;
}

