#include <iostream>
#include <initializer_list>
#include <vector>

/*
C++14 permits auto to indicate that function's return type should be deduced and C++14 lambda may use auto in paramters declarations.
This auto uses employ 'template type deduction'. so function with auto return type that returns braced initializer won't compile.

	auto createInitList()
	{
		return {1, 2, 3}; // error! can'r deduce type for {1, 2, 3}
	}

	std::vector<int> v;

	auto resetV = [&v] (const auto& newValue) {v = newValue;} 

	resetV ({1, 2, 3}); // error! can't deduce type for {1, 2, 3}
*/

auto createInitList()
{
  //return {1, 2, 3};    // error: can't deduce type for {1, 2, 3}
}

int main()
{
  std::vector<int> v;

  auto resetV =
    [&v](const auto& newValue) { v = newValue; };  // C++14

  //resetV( {1, 2, 3} );  // error! can't deduce type for { 1, 2, 3 }

  return 0;
}
