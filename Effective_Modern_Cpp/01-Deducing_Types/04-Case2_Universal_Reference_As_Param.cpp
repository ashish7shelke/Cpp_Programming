#include <iostream>

/*
Case 2: ParamType is universal reference
	Universal refernce parameters are declared like rvalue references.
	Universal reference's declared type is T&&. But it behaves differently with l-value reference.
	
	If expr is l-value reference, both T and ParamType are deduced to be l-value reference.
	If expr is r-value reference, then normal case 1 rules apply.

	When universal references are in use, type deduction distinguishes between lavalue and rvalue arguments.
	This distinguish never happens for non-universal refrences.
	
	Example 1: 
		template<typename T>
		void f(T&& param);	// Param is universal refrence
		
		int x = 27; 		f(x); 		=> x is l-value,	T is 'int&', 		param's type is 'int&'
		const int cx = x;	f(cx);		=> cx is l-value,	T is 'const int&', 	param's type is 'const int&'
		const int& rx = x;	f(rx);		=> rx is l-value,	T is 'const int&', 	param's type is 'const int&'
							f(27);		=> 27 is r-value,	T is 'int', 		param's type is 'int&&'	
*/

template <typename T>
void f(T&& param) {}	// Param is universal refrence

int main()
{
	int x = 27;
	f(x);

	const int cx = x;
	f(cx);

	const int& rx = x;
	f(rx);

	f(27);

    return 0;
}
