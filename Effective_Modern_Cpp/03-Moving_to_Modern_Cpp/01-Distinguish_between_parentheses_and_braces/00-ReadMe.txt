*------------------------------------------------------------------------------*
							Distinguish Between () and {}
--------------------------------------------------------------------------------

Depending on programmer perspective, synatx choices for object initializes in C++11 

int x(0);	// initializer is in parentheses
int y = 0;  // initializer follows '='
int z{0};	// initializer in in {}
also possible that
int w = {0}; // initializer uses '=' and {} => compiler treats it as w{}

Widget w1;	// call to default constructor
Widget w2 = w1; // call to copy constructor
w1 = w2; // call to assignment operator

To address the confusion of multiple initialization syntaxes, C++11 introduces 'uniform initialization'
A singal initialization syntax, that is {}. 

std::vector<int> v{1, 2, 3}; // v's initial content is 1, 3, 5

* Braces can also be used to specify default initialization values for non-static data members.
parentheses can not be used for non-static data member initialization.

class Widget{

	private:
		int x {0};	// x's is initialized to 0
		int y = 0;  // It works
		int z(0);	// Compiler error
};

* Uncopyable objects may be initialized using both {} and (), but not using '='

***
A novel feature of braced initialization is that it prohibits implicit narrowing conversions among built-in types.
If the value of an expression in a braced initializer isn't guranteed to be expressible by the type of the object
being initialized, the won't compile.

double x, y, z;
int sum {x + y +z}; //error! sum of doubles may not be expressible as int

Initialization with () and = doesn't check for narrowing conversiions.

*** 
Another characteristic of braced initialization is its immunity to C++'s most vaxing parse.

Widget w1 (10); // Calls Widget constructor with argument 10
Widget w2 (); // most vexing parse; declares function named w2 that returns Widget object

Functions can't be declared with {} so 
Widget w2{}; // It calls Widget constructor with no argument

***
Drawback of {} initialization
There is tangled relationship among braced initialization and std::initializer_lists and constructor overload 
resolution.

In constructor calls, () and {} has same meaning as long as std::initializer_lists parameters are not involved

class Widget
{
	public:
		Widget(int i, bool b);	// First Constructor
		Widget(int i, double d); // Second Constructor
};

Widget w1(10, true); // Calls first constructor
Widget w2{10, true}; // Calls first constructor
Widget w1(10, 5.0); // Calls second constructor
Widget w2{10, 5.0}; // Calls second constructor

Now as constructor taking std::initializer_lists.
class Widget
{
	public:
		Widget(int i, bool b);	// First Constructor
		Widget(int i, double d); // Second Constructor
		Widget(std::initializer_list<double> il); // Third constructor
};

Widget w1(10, true); // Calls first constructor
Widget w2{10, true}; // Calls third constructor, 10 and true converted to long double
Widget w1(10, 5.0); // Calls second constructor
Widget w2{10, 5.0}; // Calls third constructor, 10 and 5.0 converted to long double

Compilers determination to match braced initializers with constructor taking std::initializer_lists
is so strong.

Only if thre is no way to convert the types of the arguments in a braced initializer to type in a std::initializer_lists
do compiler fall back on normal overlaod resolution.
class Widget
{
	public:
		Widget(int i, bool b);	// First Constructor
		Widget(int i, double d); // Second Constructor
		Widget(std::initializer_list<std::string> il); // Third constructor
		// No implicit conversion possible
};

Widget w1(10, true); // Calls first constructor
Widget w2{10, true}; // Calls first constructor
Widget w1(10, 5.0); // Calls second constructor
Widget w2{10, 5.0}; // Calls second constructor

**
class Widget
{
	public:
		Widget();	// Default Constructor
		Widget(std::initializer_list<int> il);
};

Widget w1; // calls default constructor
Widget w2{}; // calls default constructor
Widget w3(); // most vexing parse! declares function
Widget ({}) // calls constructor with std::initializer_list empty list
Widget {{}} // calls constructor with std::initializer_list empty list



