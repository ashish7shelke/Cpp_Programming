#include <iostream>

/*
Case 3: ParamType is neither a pointer or a reference
	Here we are dealing with pass by value. Here is param is copied object and new object. 
			
 	Type deduction steps as follows:
	Step 1: If expr's is a reference, ignore the reference part
	Step 2: If after ignoring reference-ness, expr is const, then ignore that too. If its volatile also ignore that.

	Example 1: Param is pass by value
		template<typename T>
		void f(T param);	// Param is pass by value

		int x = 27; 		f(x); 		=> T is 'int', 	param's type is 'int'
		const int cx = x;	f(cx);		=> T is 'int', 	param's type is 'int'
		const int& rx = x;	f(rx);		=> T is 'int', 	param's type is 'int'
		
		Even though cx and rx represents const values, param isn't const. That makes sense. Param is object that is 
		completely independent of cx and rx as its copy of cx and rx. Function will modify copied objects.
		That's why expr's constness and volatileness is ignored.
		
	Example 2: param is const pointer to const object and expr is passed by value
		template<typename T>
		void f(T param);	// Param is pass by value

		const char* const ptr = "Fun with Pointers"; // ptr is const pointer to const object.
		f(ptr); 	=> T is cahr*, param's type is 'const char*'
		
		->	As per type deductions steps, poiter to const object is passed to parameter as pass by vlue.
			So const ptr is able to point another object so constness of pointer is ignored here.
	
*/

template <typename T>
void f(T param) {} // param is pass-by-value

int main()
{
	int x = 27; 		
	f(x);
	
	const int cx = x;
	f(cx);
	
	const int& rx = x;	
	f(rx);

	const char* const ptr = "Fun with Pointers"; // ptr is const pointer to const object.
	f(ptr);

    return 0;
}
