#include <iostream>

/*
Case 1: ParamType is a pointer or reference, but not universal reference
	
	Type deduction steps as follows:
	Step 1: If expr's is a reference, ignore the reference part
	Step 2: Then pattern-match expr's type against ParamType to determine T
	
	Example 3: param is pointer or pointer to const instead reference
		template<typename T>
		void f(T* param); // param is pointer
		
		int x = 27; 		f(&x); 		=> T is 'int', 	param's type is 'int*'
		const int* px = &x;	f(px);		=> T is 'const int', 	param's type is 'const int*'	
	
*/

template <typename T>
void f(T* param) {} // param is pointer

int main()
{
    int x = 27; 		
    f(&x);
	
    const int* px = &x;	
    f(px);

    return 0;
}
