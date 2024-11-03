#include <iostream>
#include <vector>
/*
To address the confusion of multiple initialization syntaxes, C++11 introduces 'uniform initialization'
A singal initialization syntax, that is {}. 

* Braces can also be used to specify default initialization values for non-static data members.
parentheses can not be used for non-static data member initialization.

* Uncopyable objects may be initialized using both {} and (), but not using '='
*/

class Widget{

	private:
		int x {0};	// x's is initialized to 0
		int y = 0;  // It works
		//int z(0);	// Compiler error
};

int main()
{
    int x(0); // Initializer is parenthesis
    int y = 0; // Initializer follows '='
    int z {0}; // Initilizer is braces
    int w = {0}; // Compiler treats it as int w{0}

    std::vector<int> v{1, 2, 3}; // v's initial content is 1, 3, 5

    return 0;
}
