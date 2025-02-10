/*
    Function Template provides a function behaviour that can be called on different types

    Or Function templates represents a family of functions
*/

// Function template that returns maximum of two values


// T --> T represents arbitrary type that is determined by the called when the caller calls the functions
// Programmer can use any TYPE as long as it provides the operations that template uses
template <typename T>
T max(T a, T b)
{
    // if b << a then yeild a  else yeild b
    return b < a ? a : b;

    // return a < b ? b : a;
}

/*
    The process of replacing tempalte parameters by concrete types is called 'instantiation'

    'Instance of a template'

    Use of function template can trigger such instantiation process
    Programmer is not neede explicit instantiation

*/

/*
    Instantiating template for a type that doesn't support all the operationsused within tempalte code will result in 
    compile time error

    *** Template compilation steps / phase
    1) Without instantiation at definition time, the template code itself is checked for correctness ignoring 
    template parameters
        - Syntax errors
        - Using unknown names independent of template parameters
        - Static assertion independent of tempalte parameters

    2) At instantiation time, template code is checked again to ensure all code is valid.
    Now specially all parts depends on teplate parameters are double-checked
*/


