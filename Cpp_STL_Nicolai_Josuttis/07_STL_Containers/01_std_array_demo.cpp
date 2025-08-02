#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    // Initialization

    std::cout << "Demonstrating std::array initialization" << std::endl;
    // Case1 - Default initialized when nothing is passed to initialize the elements
    std::array<int, 5> arr1; // OOPS: Elements have undefined values
    std::cout << "case 1: array<T, N> arr1; (default Constructor)" << std::endl;
    for(const auto& elem : arr1)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Case2 -Default initlaization with wmpty initializer list, calls elements default constructor
    std::array<int, 5> arr2{}; // Elements are initialized to 0
    std::cout << "case 2: array<T, N> arr1{}; with empty initializer list (default initialized to 0)" << std::endl;    
    for(const auto& elem : arr2)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Case 3 - Initialization with initializer list
    std::array<int, 5> arr3 = {10, 20, 30, 40, 50}; // Elements are initialized with provided values
    std::cout << "case 3: array<T, N> arr3 = {10, 20, 30, 40, 50}; (initialized with values)" << std::endl;
    for(const auto& elem : arr3)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Case 4 - Initialization with partial initializer list
    std::array<int, 5> arr4 = {100, 200}; // Remaining elements are default initialized to 0
    std::cout << "case 4: array<T, N> arr4 = {100, 200}; (partially initialized, remaining default to 0)" << std::endl;
    for(const auto& elem : arr4)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Case 5 - Initialization with higher than array size - Prone to ERROR - Too many initializers
    //std::array<int, 5> arr5 = {1, 2, 3, 4, 5, 6}; // Uncommenting this line will cause a compilation error

    // Case 6 - Initializer list as parameter in parenthesis syntax
    std::array<int, 5> arr6({1, 2, 3, 4, 5}); // Elements are initialized with provided values
    std::cout << "case 6: array<T, N> arr6({1, 2, 3, 4, 5}); (initialized with values using parenthesis syntax)" << std::endl;
    for(const auto& elem : arr6)
    {
        std::cout << elem << " ";
    }   
    std::cout << std::endl;

    // Case 7 - Copy construction
    std::array<int, 5> arr6_copy = arr6; // Copying elements from arr6 to arr7_copy
    std::cout << "case 7: array<T, N> arr6_copy = arr6; (copy construction)" << std::endl;
    for(const auto& elem : arr6_copy)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Case 8 - Move construction
    std::array<int, 5> arr6_move = std::move(arr6);
    std::cout << "case 8: array<T, N> arr6_move = std::move(arr6); (move construction)" << std::endl;
    for(const auto& elem : arr6_move)
    {
        std::cout << elem << " ";
    }   
    std::cout << std::endl << std::endl;

    // Swap()
    std::cout << "Demonstrating std::array swap()" << std::endl;
    std::array<int, 5> arr7 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr8 = {6, 7, 8, 9, 10};
    std::cout << "Before swap:" << std::endl;
    std::cout << "arr7: ";
    for(const auto& elem : arr7)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "arr8: ";
    for(const auto& elem : arr8)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    arr7.swap(arr8); // Swapping contents of arr7 and arr8
    std::cout << "After swap:" << std::endl;
    std::cout << "arr7: ";
    for(const auto& elem : arr7)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "arr8: ";
    for(const auto& elem : arr8)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    // As swap() has liners complexity wrt std::array, move semantics are used which are implicitly provided by std::array
    std::cout << "Demonstrating std::array with std::move()" << std::endl;
    std::array<int, 5> arr9 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr10;
    std::cout << "Before move:" << std::endl;
    std::cout << "arr10: ";
    for(const auto& elem : arr10)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    arr10 = std::move(arr9); // Move semantics to transfer ownership
    std::cout << "After move:" << std::endl;
    std::cout << "arr10: ";
    for(const auto& elem : arr10)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    // Size and capacity
    std::cout << "Demonstrating std::array size and capacity" << std::endl;
    std::array<int, 5> arr11 = {1, 2, 3, 4, 5};
    std::cout << "Size of arr11: " << arr11.size() << std::endl;
    std::cout << "Max size of arr11: " << arr11.max_size() << std::endl;
    std::cout << "Capacity of arr11: " << arr11.size() << std::endl; // std::array has fixed capacity equal to its size
    std::cout << "Is arr11 empty? " << (arr11.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "Demonstrating array with 0 size"  << std::endl;
    std::array<int, 0> arr12; // Empty array with size 0
    std::sort(arr12.begin(), arr12.end()); // Valid operation, no elements to sort --> It runs but does nothing
    // arr12[5] = 10; // OOPS: This will cause an out-of-bounds access, as size is 0 --> It runs but leads to undefined behavior as RUNTIME ERROR
    // std::cout << "arr12.front() : "<<arr12.front() << std::endl; // OOPS: This will cause an out-of-bounds access, as size is 0 --> It runs but leads to undefined behavior RUNTIME ERROR
    std::cout << std::endl << std::endl;
    
    // Assignment
    std::cout << "Demonstrating std::array assignment" << std::endl;
    std::array<int, 5> arr13 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr14;
    arr14 = arr13; // Assignment operator
    std::cout << "arr14 after assignment from arr13: "; 
    for(const auto& elem : arr14)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    // Assignments with fill()
    std::cout << "Demonstrating std::array fill()" << std::endl;
    std::array<int, 5> arr15;
    arr15.fill(42); // Fill all elements with 42
    std::cout << "arr15 after fill(42): ";
    for(const auto& elem : arr15)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl << std::endl;

    // Accessing elements
    std::cout << "Demonstrating std::array element access" << std::endl;
    std::array<int, 5> arr16 = {10, 20, 30, 40, 50};
    std::cout << "arr16[0]: " << arr16[0] << std::endl; // Accessing first element
    std::cout << "arr16.at(1): " << arr16.at(1) << std::endl; // Accessing second element with bounds checking 
    std::cout << "arr16.front(): " << arr16.front() << std::endl; // Accessing first element
    std::cout << "arr16.back(): " << arr16.back() << std::endl; // Accessing last element
    std::cout << "arr16.data(): " << *arr16.data() << std::endl; // Accessing underlying data pointer
    // Out of bound element access
    // std::cout << "arr16[5]: " << arr16[5] --> undefined behavior, as it is out of bounds RUNTIME ERROR
    //std::cout << "arr16.at(5): " << arr16.at(5) << std::endl; // Uncommenting these lines will cause a runtime error or throws exception out_of_range
    std::cout << std::endl << std::endl;

    // Iterating over elements
    std::cout << "Demonstrating std::array iteration" << std::endl;
    std::array<int, 5> arr17 = {10, 20, 30, 40, 50};
    std::cout << "Using range-based for loop: ";
    for(const auto& elem : arr17)
    {
        std::cout << elem << " ";
    }   
    std::cout << std::endl;
    std::cout << "Using traditional for loop: ";
    for(size_t i = 0; i < arr17.size(); ++i)
    {
        std::cout << arr17[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Using iterators: ";
    for(auto it = arr17.begin(); it != arr17.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

     // Iterator operations
    std::cout << "Demonstrating std::array iterator operations" << std::endl;
    std::cout << "Using begin() and end() to iterate -  arr17: ";
    for(auto it = arr17.begin(); it != arr17.end(); ++it)
    {
        std::cout << *it << " ";
    }   
    std::cout << std::endl;
    std::cout << "Using cbegin() and cend() for const iteration -  arr17: ";
    for(auto it = arr17.cbegin(); it != arr17.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using rbegin() and rend() for reverse iteration -  arr17: ";
    for(auto it = arr17.rbegin(); it != arr17.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using crbegin() and crend() for const reverse iteration -  arr17: ";
    for(auto it = arr17.crbegin(); it != arr17.crend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    // Demonstrating std::array comparison operators   
    // Comparison operators
    std::cout << "Demonstrating std::array comparison operators" << std::endl;
    std::array<int, 5> arr18 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr19 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr20 = {5, 4, 3, 2, 1};
    std::cout << "arr18: ";
    for(const auto& elem : arr18)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "arr19: ";
    for(const auto& elem : arr19)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "arr20: ";
    for(const auto& elem : arr20)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // Comparison results
    std::cout << "Comparison results:" << std::endl;
    std::cout << "arr18 == arr19: " << (arr18 == arr19 ? "true" : "false") << std::endl; // Equal
    std::cout << "arr18 != arr20: " << (arr18 != arr20 ? "true" : "false") << std::endl; // Not equal
    std::cout << "arr18 < arr20: " << (arr18 < arr20 ? "true" : "false") << std::endl; // Less than
    std::cout << "arr18 > arr20: " << (arr18 > arr20 ? "true" : "false") << std::endl; // Greater than
    std::cout << "arr18 <= arr19: " << (arr18 <= arr19 ? "true" : "false") << std::endl; // Less than or equal
    std::cout << "arr18 >= arr19: " << (arr18 >= arr19 ? "true" : "false") << std::endl; // Greater than or equal       
    std::cout << std::endl << std::endl;

    // Tuple-like behavior
    std::cout << "Demonstrating std::array tuple-like behavior" << std::endl;
    std::array<int, 3> arr21 = {1, 2, 3};
    std::cout << "Using std::get<0>(arr21): " << std::get<0>(arr21) << std::endl; // Accessing first element
    std::cout << "Using std::get<1>(arr21): " << std::get<1>(arr21) << std::endl; // Accessing second element
    std::cout << "Using std::get<2>(arr21): " << std::get<2>(arr21) << std::endl; // Accessing third element
    std::cout << "Using std::tuple_size<decltype(arr21)>::value: " << std::tuple_size<decltype(arr21)>::value << std::endl; // Getting size of array
    std::cout << "Using std::tuple_element<0, decltype(arr21)>::type: " << typeid(std::tuple_element<0, decltype(arr21)>::type).name() << std::endl; // Getting type of first element   
    std::cout << std::endl << std::endl;
    
    return 0;

}