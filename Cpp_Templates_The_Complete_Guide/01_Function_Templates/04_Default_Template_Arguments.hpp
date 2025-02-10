#include <type_traits>

template <typename T1, typename T2, typename RT = std::decay_t<decltype(true?T1() : T2())> >
RT max_with_decay_t(T1 a, T2 b)
{
    return b < a ? a : b;
}


template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2> >
RT max_with_common_type_t(T1 a, T2 b)
{
    return b < a ? a : b;
}