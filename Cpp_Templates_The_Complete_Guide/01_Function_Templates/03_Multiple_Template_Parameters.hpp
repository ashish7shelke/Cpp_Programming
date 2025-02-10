/*
    Function templates have 2 sets of parameters

    template <typename T> --> T is template parameter

    T max(T a, T b) --> a and b are call parameters

*/




#include <typeinfo>
// Function template that returns maximum of two values

// Template Parameters for Return Types
template <typename T1, typename T2, typename RT>
RT max(T1 a, T2 b)
{
    // if b << a then yeild a  else yeild b
    return b < a ? a : b;
}
/*_______________________________________________________________________________________________________*/

// Deducing Return Type without trailing retrun type
template <typename T1, typename T2>
auto max_with_auto (T1 a, T2 b) // auto for the return type without trailing return type
{
    return b < a ? a : b; 
}

// Deducing Return Type with trailing retrun type
template <typename T1, typename T2>
auto max_with_auto_decltype (T1 a, T2 b) -> decltype(b < a ? a : b)
{
    return b < a ? a : b;
}
// This may deduce type to refrence type 

#include <type_traits>
// Deducing Return Type without trailing retrun type with dacay (it removes reference or qualifiers)
template <typename T1, typename T2>
auto max_with_auto_decltype_decayed(T1 a, T2 b) -> typename std::decay<decltype(true? a : b)> :: type
{
    return b < a ? a : b;
}

/*_______________________________________________________________________________________________________*/

// Return Type as Common Type
#include <type_traits>
template <typename T1, typename T2>
std::common_type_t<T1, T2> max_with_commontrait(T1 a, T2 b) // C++14
{
    return b < a ? a : b;
}

/*
    typename std::common_type<T1, T2> :: type   --> C++11
    std::common_type_t<T1, T2>                  --> C++14
*/


/* TYPEID Prints are pending*/

