#include <iostream>
/*
    In cosntructor calls, {} & () have same meaning as long as std::initializer_list parameters are
    not involved in constructor
*/

class Widget
{
	public:
		Widget(int i, bool b) {std::cout << "Widget(int i, bool b)" << std::endl;};	// First Constructor
		Widget(int i, double d){std::cout << "Widget(int i, double d)" << std::endl;}; // Second Constructor
};

/*
    In cosntructor calls, {} & () have different meaning as std::initializer_list parameters are
    involved in constructor.
    Compilers determination to match braced initializers with constructor taking std::initializer_lists
    is so strong.
*/
class Widget_with_il // Class with constructor with initializer_list
{
	public:
		Widget_with_il(int i, bool b) {std::cout << "Widget_with_il(int i, bool b)" << std::endl;};	// First Constructor
		Widget_with_il(int i, double d){std::cout << "Widget_with_il(int i, double d)" << std::endl;}; // Second Constructor
        Widget_with_il(std::initializer_list<double> il) {std::cout << "Widget_with_il(std::initializer_list<double> il)" << std::endl;}; // Third constructor
};

/*
    Only if thre is no way to convert the types of the arguments in a braced initializer to type in a std::initializer_lists
    do compiler fall back on normal overlaod resolution.
*/
class Widget_with_il_with_implicit_conversion // Class with constructor with initializer_list
{
	public:
		Widget_with_il_with_implicit_conversion(int i, bool b) {std::cout << "Widget_with_il_with_implicit_conversion(int i, bool b)" << std::endl;};	// First Constructor
		Widget_with_il_with_implicit_conversion(int i, double d){std::cout << "Widget_with_il_with_implicit_conversion(int i, double d)" << std::endl;}; // Second Constructor
        Widget_with_il_with_implicit_conversion(std::initializer_list<std::string> il) {std::cout << "Widget_with_il_with_implicit_conversion(std::initializer_list<double> il)" << std::endl;}; // Third constructor
        // No implicit conversion to std::string from int or float values
};

/*
    Default constructor with empty std::initializer_List
*/
class Widget_empty_braces
{
	public:
		Widget_empty_braces(){std::cout << "Widget_empty_braces()" << std::endl;};	// Default Constructor
		Widget_empty_braces(std::initializer_list<int> il){std::cout << "Widget_empty_braces(std::initializer_list<int>)" << std::endl;};
};

int main()
{
    Widget w1(10, true); // Calls first constructor
    Widget w2{10, true}; // Calls first constructor
    Widget w3(10, 5.0); // Calls second constructor
    Widget w4{10, 5.0}; // Calls second constructor

    Widget_with_il w1_il(10, true); // Calls first constructor
    Widget_with_il w2_il{10, true}; // Calls third constructor, 10 and true converted to long double
    Widget_with_il w3_il(10, 5.0); // Calls second constructor
    Widget_with_il w4_il{10, 5.0}; // Calls third constructor, 10 and 5.0 converted to long double

    Widget_with_il_with_implicit_conversion w1_il_string(10, true); // Calls first constructor
    Widget_with_il_with_implicit_conversion w2_il_string{10, true}; // Calls first constructor
    Widget_with_il_with_implicit_conversion w3_il_string(10, 5.0); // Calls second constructor
    Widget_with_il_with_implicit_conversion w4_il_string{10, 5.0}; // Calls second constructor

    Widget_empty_braces w1_eb; // calls default constructor
    Widget_empty_braces w2_eb{}; // calls default constructor
    //Widget_empty_braces w3_eb(); // most vexing parse! declares function
    Widget_empty_braces ({}); // calls constructor with std::initializer_list empty list
    Widget_empty_braces {{}}; // calls constructor with std::initializer_list empty list
}
