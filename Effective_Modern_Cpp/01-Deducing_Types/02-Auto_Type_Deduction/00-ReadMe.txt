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
Understand auto type deduction
--------------------------------------

Auto tyoe deduction works on similar concepts as template type deduction.

Template type deduction involves templates, functions and parametersbut auto deals non of these.

There is direct mapping between template type deduction and auto type deduction. Literally an algorithmic transformation from one to the another.

	auto x = 27;
	template <typename T>
	void func_for_x(T param) {} // Conceptual template for deducing auto x

	const auto cx = x;
	template <typename T>
	void func_for_cx(const T param) {} // Conceptual template for deducing const auto cx

	const auto& rx = x;
	template <typename T>
	void func_for_rx(const T& param) {} // Conceptual template for deducing const auto& rx

Similar to template type deduction, auto has 3 cases based on characteristics of ParamType.

Case 1: ParamType is a pointer or reference, but not universal reference
Case 2: ParamType is universal reference
Case 3: ParamType is neither a pointer or a reference

	auto x = 27;	// Case 3
	const auto cx = x; // Case 3
	const auto& rx = x; // Case 1

Case 2:
	Example 1:
		auto&& uref1 = x;	// x is int val and lvalue - so uref's type is int&

		auto&& uref2 = cx; // cx is const int and lvalue - uref2's type is const int&

		auto&& uref3 = 27; // 27 is int and rvalue - uref3's type is int&&

	Example 2: Array Arguments

		const char name[] = "J. P. Briggs"; // name 's type is const char[13]

		auto arr1 = name; // arr1 type is const char*
		auto& arr2 = name; // arry2's type is const char(&)[13]

	Example 3: Function Arguments

		void someFunc(int, double);

		auto func1 = someFunc; // func1's type is void(*)(int, double)

		auto func2 = someFunc; // func2's type is void(&)(int, double)
------------------------------------------------------------------------------------------------------------------------
There is special type deduction rule for auto.
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
----------------------------------------------------------------------------------------------------------------

C++14 permits auto to indicate that function's return type should be deduced and C++14 lambda may use auto in paramters declarations.
This auto uses employ 'template type deduction'. so function with auto return type that returns braced initializer won't compile.

	auto createInitList()
	{
		return {1, 2, 3}; // error! can'r deduce type for {1, 2, 3}
	}

	std::vector<int> v;

	auto resetV = [&v] (const auto& newValue) {v = newValue;} 

	resetV ({1, 2, 3}); // error! can't deduce type for {1, 2, 3}

------------------------------------------------------------------------------------------------------------------------------
* auto type deduction is usually the same as template type deduction, but auto type deduction assumes that a braced initializer represents
  a std::initializer_list, and template type doesn'T

* auto in a function return type or a lambda parameter implies tempalte type deduction, not auto type dection

	
