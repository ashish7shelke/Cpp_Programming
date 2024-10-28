#include <iostream>

/*
Case 1: ParamType is a pointer or reference, but not universal reference
	
	Type deduction steps as follows:
	Step 1: If expr's is a reference, ignore the reference part
	Step 2: Then pattern-match expr's type against ParamType to determine T
	
	Example 2: Param is 'reference to const'
		template<typename T>
		void f(const T& param); // param is constant reference
		
		int x = 27; 		f(x); 		=> T is 'int', 	param's type is 'const int&'
		const int cx = x;	f(cx);		=> T is 'int', 	param's type is 'const int&'
		const int& rx = x;	f(rx);		=> T is 'int', 	param's type is 'const int&'
	
*/

template <typename T>
void f(const T& param) {} // param is constant reference

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
