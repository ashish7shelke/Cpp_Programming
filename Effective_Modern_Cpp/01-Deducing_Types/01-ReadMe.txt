*------------------------------------------------------------------------------*
							Deducing Types
--------------------------------------------------------------------------------

C++98 had a single set of rules for type deduction: onr for function templates.

C++11 modifies that and two more 
1) auto and decltype

Type deduction frees you from tyranny of spelling out types that are obvious redunduant.
Changing a type at one point in the source code sutomatically propagates through type deduction
to other locations

However this can render code more difficult to reason about, types deducted by compilers
may not be as apparent as you'd like.

In this chapter, topics covered are
1) How template type deduction works
2) How auto builds on that
3) How programmer can force compilers to make the results of their type deductions visible,
   thus enabling you to ensure that compilers are deducing the types you want them to.
   
*---------------Item 1---------------*
Understand template type deduction
--------------------------------------

This item covers, the aspects of template type deduction that auto builds on.

There are 3 type deduction scenarios in template functions

	template<typename T>
	void f(paramType param);

	f(expr);	// Deduce T and ParamType from expr

Case 1: ParamType is a pointer or reference, but not universal reference
Case 2: ParamType is universal reference
Case 3: ParamType is neither a pointer or a reference

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
	
	Example 2: Param is 'reference to const'
		template<typename T>
		void f(const T& param); // param is constant reference
		
		int x = 27; 		f(x); 		=> T is 'int', 	param's type is 'const int&'
		const int cx = x;	f(cx);		=> T is 'int', 	param's type is 'const int&'
		const int& rx = x;	f(rx);		=> T is 'int', 	param's type is 'const int&'
	
	Example 3: param is pointer or pointer to const instead reference
		template<typename T>
		void f(T* param); // param is pointer
		
		int x = 27; 		f(&x); 		=> T is 'int', 	param's type is 'int*'
		const int* px = &x;	f(px);		=> T is 'const int', 	param's type is 'const int*'	

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
	
	Example 1:
	// Returns size of an array as a compile-time constant
	// Array parameter has no name, because we only care about the number of elements it conatains
	template<typename T, std::size_t N>
	constexpr std::size_t arraySize(T(&)[N]) noexcept
	{
		return N;
	}
	constexpr makes its result available during compilation.
	
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
		
		
	* During template type deduction, arguments that are refrence are treated as non-refrences, i.e. refrenceness is ignored.
	* While deducing types for universal reference parameters, lvalue arguments get special treatment.
	* When duducing types for by-value parameters, const and/or volatile arguments are treated as non-const and non-volatile.
	* During tempalte type deduction, arguments that are array or function names decays to pointer, unless they are used to initialize refrences.


-----------------------------------------------------------------------------------------------------------------------------------------------

*---------------Item 2---------------*
Understand auto type deduction
--------------------------------------


	
	
	