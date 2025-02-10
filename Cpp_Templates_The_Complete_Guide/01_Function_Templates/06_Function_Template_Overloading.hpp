#include <iostream>
#include <string>

//Maximum of two values of any type
template <typename T>
T max(T a, T b)
{
    std:: cout << "Inside T max(T, T)" << std::endl;
    return b < a ? a : b;
}

//Maximum of two pointers
template <typename T>
T* max(T* a, T* b)
{
    std:: cout << "Inside T* max(T*, T*)" << std::endl;
    return *b < *a ? a : b;
}

//Maximum of two C-string
char const* max(char const* a, char const* b)
{
    std:: cout << "Inside char const* max(char const* a, char const* b)" << std::endl;
    return std::strcmp(b, a) < 0 ? a : b; 
}
