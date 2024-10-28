#include <iostream>

/*
Case 1: ParamType is a pointer or reference, but not universal reference
	
	Type deduction steps as follows:
	Step 1: If expr's is a reference, ignore the reference part
	Step 2: Then pattern-match expr's type against ParamType to determine T
	
	Example 1: Param is 'reference'
		template<typename T>
		void f(T& param); // param is reference
		
		int x = 27; 		f(x); 		=> T is 'int', 			param's type is 'int&'
		const int cx = x;	f(cx);		=> T is 'const int', 	param's type is 'const int&'
		const int& rx = x;	f(rx);		=> T is 'const int', 	param's type is 'const int&'
	
	when programmer passes a const object to reference parameter, they expect that object to be unmodifiable,
	i.e. parameter to be refernce to const. 
	Passing const object to tempalte taking T& as parameter is safe.
	Constness of the object becomes part of the type deduced for T.
	
	Type deduction works exactly same for r-value reference.
*/

template <typename T>
void f(T& param) {} // param is reference

int main()
{
	int x = 27;
	f(x);
	
	const int cx = x;
	f(cx);
	
	const int& rx = x;
	f(rx);

    return 0;
}
