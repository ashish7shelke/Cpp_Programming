#include <iostream>
#include <initializer_list>

/*
here is special type deduction rule for auto.
When the initializer for an auto-declared variable is enclode din braces, deduced type is std::initializer_list

	auto x1 = 27;	// int x1 = 27; 	--> It declares variable of type int with value 27
	auto x2 (27);	// int x2 (27); 	--> It declares variable of type int with value 27

	auto x3 = {27}; // int x3 = {27}; 	--> It declares a variable of type std::initializer_list<int>
	auto x4 = {27}; // int x4{27}; 		--> It declares a variable of type std::initializer_list<int>


	auto x5 = {1, 2, 3.0}; --> error! can't deduce T for std::initializer_list<T>
							--> here deducing T of initializer_list is failed

The treatment of braced initializers is the only way in which auto type deduction and template type deduction differ.

When auto declared variable is initialized with braced initializer, deduced type is an instantiation of std::initializer_list.
But if corresponding tempalte is passed same initializer, type deduction fails, and code is rejected.

	auto x = {11, 23, 9};	// x's type is std::initializer_list<int>

	template<typename T>
	void f(T param);	// template with parameter declaration equivalent to x's declaration
	f({11, 23, 9}); 	// error! can't deduce type in tamplate 

	template<typename T>
	void f(std::initializer_list<T> param);	// template with parameter declaration equivalent to x's declaration
	f({11, 23, 9}); 	// T is deduced as int, param is std::initalizer_list<int>


Auto assumes that a braced initializer represents a std::initalizer_list but tempalte type deductions doesn't.
*/

template<typename T>  // template with parameter
void f(T param) {}    // declaration equivalent to
                      // x's declaration

template<typename T>
void f2(std::initializer_list<T> initList) {}

int main()
{

	{
		int x1 = 27;
		int x2(27);
		int x3 = {27};
		int x4{27};
	}

	{
		auto x1 = 27;    // type is int, value is 27
		auto x2(27);     // ditto
		auto x3 = {27};  // type is std::initializer_list<int>,
						// value is {27}
		auto x4{27};     // ditto

		//auto x5 = {1, 2, 3.0};  // error! can't deduce T for
		//                        // std::initializer_list<T>
	}

	{
		auto x = { 11, 23, 9 };  // x's type is
								// std::initializer_list<int>

		//f({ 11, 23, 9 });        // error! can't deduce type for T

		f2({ 11, 23, 9 });        // T deduced as int, and initList's
								// type is std::initializer_list<int>
	}
    return 0;
}
