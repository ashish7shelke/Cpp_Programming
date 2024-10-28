#include <iostream>

/*
Array Arguments:
	-----------------
	Array types are different from pointer types, even though they sometimes seem to interchangeable.
	
	A primary contributor to this illusion is that, in many context, an array decays into pointer to the first element.
	
	const char name[] = "J. P. Briggs"; // name 's type is const char[13]
	//it decays to pointer as
	const char* ptrToName = name; // array decays to pointer
	
	Here const char* ptrToName is being initialized with name which is const char[13].
	These types conast char* and const char[13] are not the same.
	Because of array-to-pointer decay rule, the code compiles.
	 
	What happens if array is passed to template taking by-value-parameter?
	template<typename T>
	void f(T param); // Template with by-value parameter
	f(name); => // name is array, but T is deduced as const char*
	
	The observations that there is no such thing as a funciton parameter that's an array.
		void myFunc(int param[]); <---> void myFunc(int* param);
		But array declaration is treated as pointer declaration.
	
	Array parameter declarations are treated as if they were pointer parameters, type of an array that's passed to 
	template function by value is deduced to be a pointer type.
	
	Although function can't declare parameters that are truly arrays, they can declare parameters that are refrence to arrays.
		template<typename T>
		void f(T& param);	//Template with refrence parameter
		f(name);		//T is actual array type that includes array size -> T is deduced to const char[13]
						// Param type is deduced to refrence to array that is 'char(&)[13]'
						
		Ability to declare 'refrence to arrays' enables creation of template that deduces the number of elements that an array contains

*/

template <typename T>
void f1(T param) {} // param is pass-by-value

void myFunc1(int param[]) {}
void myFunc2(int* param) {}   // same function as myFunc1


template <typename T>
void f2(T& param) {} // param is refrence to array
int main()
{
	const char name[] = "J. P. Briggs"; // name 's type is const char[13]
	//it decays to pointer as
	const char* ptrToName = name; // array decays to pointer

	f1(name); // name is array, but T is deduced as const char*

	f2(name); //T is actual array type that includes array size -> T is deduced to const char[13]
			// Param type is deduced to refrence to array that is 'char(&)[13]'
	
    return 0;
}
