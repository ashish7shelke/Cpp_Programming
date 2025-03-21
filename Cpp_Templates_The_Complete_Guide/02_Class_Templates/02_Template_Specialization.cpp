#include <iostream>
#include <string>
#include "02_Template_Specialization.hpp"

int main(void)
{
    Stack<int>          intStack;       // Stack of ints
    Stack<std::string>  stringStack;    // Stack of Strings

    // Manipulate int stack
    intStack.push(7);
    std::cout << intStack.top() << std::endl;
    intStack.push(14);
    intStack.push(21);
    intStack.push(28);
    std::cout << intStack << std::endl;

    //Manipulate string stack
    stringStack.push("Hello");
    stringStack.push("World!!!");
    stringStack.push("Cpp Template World !!!");
    std::cout << stringStack << std::endl; //Error: As not specialized in string specialized template class
    stringStack.pop();

    return 0;
}