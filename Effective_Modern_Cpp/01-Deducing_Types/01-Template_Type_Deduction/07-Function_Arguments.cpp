#include <iostream>
#include <array>
#include <cstddef>

/*
Function Arguments:
	--------------------
	Function types can decay into function pointers.
	
		void simeFunc(int, double);
		
		template <typename T>
		void f1(T param);	//Param is passed by value
		
		template <typenamr T>
		void f2(T& param);	// Param is passed by reference
		
		f1(someFunc); 		// Param is deduced as ptr-to-func type is -- void(*)(int,double)

		f2(someFunc);		// Param is deduced as ref-to-function is -- void(&) (int, double)

*/

void someFunc(int, double){}  // someFunc is a function;
                              // type is void(int, double)

template<typename T>
void f1(T param) {}           // in f1, param passed by value

template<typename T>
void f2(T& param) {}          // in f2, param passed by ref

int main()
{
	f1(someFunc);               // param deduced as ptr-to-func;
								// type is void (*)(int, double)

	f2(someFunc);               // param deduced as ref-to-func;
								// type is void (&)(int, double)
		
		return 0;
}
