#include <iostream>

/*
	Auto type deduction works exactly like template type deduction.

	with only one exception.


*/

template <typename T>
void func_for_x(T param) {} // Conceptual template for deducing auto x

template <typename T>
void func_for_cx(const T param) {} // Conceptual template for deducing const auto cx

template <typename T>
void func_for_rx(const T& param) {} // Conceptual template for deducing const auto& rx


void someFunc(int, double){}  // someFunc is a function;
                              // type is void(int, double)

int main()
{
	auto x = 27;
	const auto cx = x;
	const auto& rx = x;

	func_for_x(27);
	func_for_cx(x);
	func_for_rx(x);

	//Universal reference
	auto&& uref1 = x;
	auto&& uref2 = cx;
	auto&& uref3 = rx;

	//Array arguments
	const char name[] = "J. P. Briggs"; // name 's type is const char[13]

	auto arr1 = name; // arr1 type is const char*
	auto& arr2 = name; // arry2's type is const char(&)[13]

	
	//Function arguments
	auto func1 = someFunc; // func1's type is void(*)(int, double)

	auto func2 = someFunc; // func2's type is void(&)(int, double)
    return 0;
}
