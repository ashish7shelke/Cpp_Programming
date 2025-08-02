#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void printVector(std::vector<T> vec)
{   
    if(vec.empty())
        std::cout << "Emptry vecor" << std::endl;
    else
    {
        for (const auto& elem : vec)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
    std::cout << "Size() = " << vec.size() << ", capacity() = " << vec.capacity() << ", max_size() = "
                        << vec.max_size() << ", empty() = " << vec.empty() << std::endl;
    std::cout << std::endl;
}

void vectorDemo();
void booleanVectorDemo();

int main()
{
    vectorDemo();

    booleanVectorDemo();
    return 0;
}

void vectorDemo()
{
    // Initialization
    std::cout << "Demonstrating std::vector" << std::endl;

    // Constructors and destructors of vectors
    std::cout << "Demonstrating vectors constructors & destructors" << std::endl;

    //Default constructor

    std::vector<int> vec1;
    std::cout << "Case 1: vector<T> vec1 : Default constructor :: " << std::endl; 
    printVector(vec1);

    std::vector<int> vec2(5);
    std::cout << "Case 2: vector<T> vec2(5) : Vector with 5 elements with default constructor of element:: " << std::endl; 
    printVector(vec2);    

    std::vector<int> vec3(5, 2);
    std::cout << "Case 3: vector<T> vec3(5,2) : Vector with 5 elements with value of 2 :: " << std::endl; 
    printVector(vec3);     
    
    // Copy constructor & Assignment constructor
    std::vector<int> vec4(vec3);
    std::cout << "Case 4: vector<T> vec4(vec3) : Copy constructor  :: " << std::endl; 
    printVector(vec4);        

    std::vector<int> vec5 = vec2;
    std::cout << "Case 5: vector<T> vec5 = vec2 : Assignment operator  :: " << std::endl; 
    printVector(vec5);

    // Move constructor & move assignment operator
    std::vector<int> vec6(std::move(std::vector<int> {1, 2, 3, 4, 5}));
    std::cout << "Case 6: vector<int> vec6(std::move(std::vector<int> {1, 2, 3, 4, 5})) : Move constructor  :: " << std::endl; 
    printVector(vec6);        

    std::vector<int> vec7 = std::move(std::vector<int> {5, 4, 3, 2, 1});
    std::cout << "Case 7: vector<int> vec7 = std::move(std::vector<int> {5, 4, 3, 2, 1}) :: " << std::endl; 
    printVector(vec7);

    // Initializer list
    std::vector<int> vec8({6, 7, 8, 9, 10});
    std::cout << "Case 8: vector<int> vec8({6, 7, 8, 9, 10}) : Move constructor  :: " << std::endl; 
    printVector(vec8);        

    std::vector<int> vec9 = {10, 9, 8, 7, 6};
    std::cout << "Case 9: vector<int> vec7 = {5, 4, 3, 2, 1} : Move Assignment operator  :: " << std::endl; 
    printVector(vec9);
   
    // Vector operations
    std::cout << "Demo of vector::reserve(size)" << std::endl;
    std::vector<int> vec10;
    std::cout << "Reserving vector space vec10.reserve(80) :: " << std::endl; 
    vec10.reserve(80);
    printVector(vec10);

    // Vector operations
    std::cout << "Demo of vector::shrink_to_fit()" << std::endl;
    std::vector<int> vec11{1, 2, 3, 4, 5};
    std::cout << "vec11 before shrinking : " << std::endl;
    printVector(vec11);      
    std::cout << "Shrinking vector  :: vec12.shrink_to_fit() " << std::endl; 
    std::vector<int> vec12 = vec11;
    vec12.pop_back();
    vec12.pop_back();
    vec12.shrink_to_fit();
    printVector(vec12);
    
    std::cout << "Demo assign() Operation" << std::endl;
    std::vector<int> vec13;
    std::cout << "Case 1 : vec13.assign(n, elem) :: " << std::endl;
    vec13.assign(10, 7); 
    printVector(vec13);

    std::vector<int> vec14;
    std::cout << "Case 2 : vec13.assign(initlist) :: " << std::endl;
    vec14.assign({10, 22, 33, 44, 55}); 
    printVector(vec14);    
    
    std::cout << "Demo swap() Operation" << std::endl;
    std::cout << "Case 1 : vec14.swap(vec13)  :: " << std::endl;
    vec14.swap(vec13); 
    std::cout << "Vectors after swapping vec14.swap(vec13) " << std::endl;
    std::cout << "vec13 = "; printVector(vec13);
    std::cout << "vec14 = "; printVector(vec14);

    // Element access
    std::cout << "Demo :: Element access" << std::endl;
    std::cout << "Case 1 : with operator [] : " << std::endl;
    for(int i = 0 ; i < vec13.size() ; i++)
        std::cout << "vec13[" << i << "] = " << vec13[i] << std::endl;

    std::cout << "Case 2 : with operator at() : " << std::endl;
    for(int i = 0 ; i < vec13.size() ; i++)
        std::cout << "vec13[" << i << "] = " << vec13.at(i) << std::endl;
    
    std::cout << "Case 3 : front() & back() " << std::endl;
    std::cout << "Elemnt at front vec13.front() = " << vec13.front() << std::endl;
    std::cout << "Elemnt at back vec13.back() = " << vec13.back() << std::endl;    

    // Inserts and remove operations 
    std::cout << "Demostrating Insert and remove operations " << std::endl;
    std::vector<int> vec15{10, 20, 30, 40, 50};
    std::cout << "Vec15 : "; printVector(vec15);

    std::cout << "Insert with push_back() :: appends copy of elem at the end " << std::endl;
    vec15.push_back(11);
    std::cout << "Vec15 : after push_back(11)"; printVector(vec15);

    std::cout << "Remove with pop_back() :: removes elem at the end " << std::endl;
    vec15.pop_back();
    std::cout << "Vec15 : after pop_back()"; printVector(vec15);

    std::cout << "Insert with insert(pos, elem) :: Insert a copy of elem before interator pos and returns new pos" << std::endl;
    vec15.insert(vec15.begin() + 3, 11);
    std::cout << "Vec15 : after insert(vec15.begin() + 3, 11) "; printVector(vec15);

    std::cout << "Insert with insert(pos, n, elem) :: Insert n copies of elem before interator pos and returns new pos" << std::endl;
    vec15.insert(vec15.begin() + 3, 5, 100);
    std::cout << "Vec15 : after insert(vec15.begin() + + 3, 5, 100) "; printVector(vec15);

    std::cout << "Insert with insert(pos, initlistm) :: Insert initlist before interator pos and returns new pos" << std::endl;
    vec15.insert(vec15.begin() + 1, {201, 202, 203});
    std::cout << "Vec15 : after insert(vec15.begin() + 1, {201, 202, 203}) "; printVector(vec15);

    std::cout << "Remove with erase(pos) ::Removes the element at iterator pos" << std::endl;
    vec15.erase(vec15.begin() + 3);
    std::cout << "Vec15 : after erase(vec15.begin() + 3) "; printVector(vec15);

    std::cout << "Remove with erase(beg, end) ::Removes the element in range beg, end" << std::endl;
    vec15.erase(vec15.begin() + 3, vec15.begin() + 8);
    std::cout << "Vec15 : after erase(vec15.begin() + 3) "; printVector(vec15);

    std::cout << "Resize with resize(num) : change number of elements to num initlaized with default constructor " << std::endl;
    vec15.resize(vec15.size() + 10);
    std::cout << "Vec15 : after resize(vec15.size() + 10) "; printVector(vec15);

    std::cout << "Resize with resize(num, elem) : change number of elements to num initlaized with elem " << std::endl;
    vec15.resize(vec15.size() + 10, 1000);
    std::cout << "Vec15 : after resize(vec15.size() + 10) "; printVector(vec15);

    std::cout << "Clear vector " << std::endl;
    vec15.clear();
    std::cout << "Vec15 : after clear() "; printVector(vec15);

    // Iterator operations
    std::cout << "Using iterators: ";
    std::vector<int> vec16({6, 7, 8, 9, 10});
    std::cout << "vec16 : " << std::endl; 
    printVector(vec16);

     // Iterator operations
    std::cout << "Demonstrating std::vector iterator operations" << std::endl;
    std::cout << "Using begin() and end() to iterate -  arr17: ";
    for(auto it = vec16.begin(); it != vec16.end(); ++it)
    {
        std::cout << *it << " ";
    }   
    std::cout << std::endl;
    std::cout << "Using cbegin() and cend() for const iteration -  arr17: ";
    for(auto it = vec16.cbegin(); it != vec16.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using rbegin() and rend() for reverse iteration -  arr17: ";
    for(auto it = vec16.rbegin(); it != vec16.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using crbegin() and crend() for const reverse iteration -  arr17: ";
    for(auto it = vec16.crbegin(); it != vec16.crend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
}

void booleanVectorDemo()
{
    std::cout << "Specialized boolean vector demo :: " << std::endl;

    std::cout << "Boolean vector conbstruction :: std::vector<bool> bVec1(10) "  << std::endl;
    std::vector<bool> bVec1(10);
    printVector(bVec1);

    std::cout << "Flipping Compliments all elements: bVec1.flip() " << std::endl;
    bVec1.flip();
    printVector(bVec1);

    std::cout << "Flipping individual bit (2nd and 4th from MSB): bVec1[idx].flip() : " << std::endl;
    bVec1[2].flip();
    bVec1[4].flip();
    printVector(bVec1);
    
    std::cout << "Flipping front() bit: bVec1.front().flip() : " << std::endl;
    bVec1.front().flip();
    printVector(bVec1);

    std::cout << "Assign using [] operator : " << std::endl;
    bVec1[4] = bVec1.back(); // Assign last element
    printVector(bVec1);    
}