#include <iostream>
#include <array>
#include <cstddef>

/*
Array Arguments:
	-----------------
	Ability to declare 'refrence to arrays' enables creation of template that deduces the number of elements that an array contains
	
	Example 1:
	// Returns size of an array as a compile-time constant
	// Array parameter has no name, because we only care about the number of elements it conatains
	template<typename T, std::size_t N>
	constexpr std::size_t arraySize(T(&)[N]) noexcept
	{
		return N;
	}
	constexpr makes its result available during compilation.

*/

template<typename T, std::size_t N>
	constexpr std::size_t arraySize(T(&)[N]) noexcept
	{
		return N;
	}

int main()
{
	int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals has
												// 7 elements

	int mappedVals1[arraySize(keyVals)];         // so does
												// mappedVals

	std::array<int, arraySize(keyVals)> mappedVals2;  // mappedVals'
													// size is 7
	
    return 0;
}
