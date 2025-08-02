#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
void printList(std::list<T> vec)
{   
    if(vec.empty())
        std::cout << "Emptry List" << std::endl;
    else
    {
        for (const auto& elem : vec)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
    std::cout << "Size() = " << vec.size() << ", max_size() = "
                        << vec.max_size() << ", empty() = " << vec.empty() << std::endl;
    std::cout << std::endl;
}

int main()
{
    // Initialization
    // Initialization
    std::cout << "Demonstrating std::list" << std::endl;

    // Constructors and destructors of vectors
    std::cout << "Demonstrating lists constructors & destructors" << std::endl;

    //Default constructor

    std::list<int> list1;
    std::cout << "Case 1: list<T> list1 : Default constructor :: " << std::endl; 
    printList(list1);

    std::list<int> list2(5);
    std::cout << "Case 2: list<T> list1(5) : Creates list of n elements created by default constructor :: " << std::endl; 
    printList(list2);

    std::list<int> list3(5, 2);
    std::cout << "Case 3: list<T> list1(5, 2) : Creates list of n elements with value 2:: " << std::endl; 
    printList(list3);

    std::list<int> list4(list3);
    std::cout << "Case 4: list<T> list4(list2) : Copy constructor:: " << std::endl; 
    printList(list4);
    
    std::list<int> list5 = list2;
    std::cout << "Case 5: list<T> list5 = list2 : Copy constructor:: " << std::endl; 
    printList(list5);

    std::list<int> list6(std::list<int> {1, 2, 3, 4, 5});
    std::cout << "Case 6: list<T> list6(std::list<int> {1, 2, 3, 4, 5}) : Move constructor:: " << std::endl; 
    printList(list6); 

    std::list<int> list7 = std::list<int> {1, 2, 3, 4, 5};
    std::cout << "Case 7: list<T> list7 = std::list<int> {1, 2, 3, 4, 5} : Move constructor: " << std::endl; 
    printList(list7);

    std::list<int> list8({6, 7, 8, 9, 10});
    std::cout << "Case 8: list<T> list8({1, 2, 3, 4, 5}) : Move constructor:: " << std::endl; 
    printList(list8); 

    std::list<int> list9 = {6, 7, 8, 9, 10};
    std::cout << "Case 9: list<T> list9 = {1, 2, 3, 4, 5} : Move constructor: " << std::endl; 
    printList(list9);

    // Assigning and Accessing elements
    list9 = list6;
    std::cout << "Assignment: list9 = list6 : Assignment operator: " << std::endl; 
    printList(list9);    

    list9 = std::list<int> {6, 7, 8, 9, 10};
    std::cout << "Assignment:  list9 = std::list<int> {6, 7, 8, 9, 10} : Move Assignment operator: " << std::endl; 
    printList(list9);

    list9 = {11, 12, 13, 14, 15};
    std::cout << "Assignment:  list9 = {11, 12, 13, 14, 15} : Assigning with initializer list: " << std::endl; 
    printList(list9);

    list9.assign(3, 5);
    std::cout << "Assignment:  list9.assign(3, 5) : assign n copies of elem " << std::endl; 
    printList(list9);
    
    list9.assign({10, 20, 30, 40, 50});
    std::cout << "Assignment:   list9.assign({10, 20, 30, 40, 50}) : assign n copies of elem " << std::endl; 
    printList(list9);

    std::cout << "Swapping list :: "<< std::endl;
    std::cout << "Lists before swapping" << std::endl;
    std::cout << "list8 : "; printList(list8);
    std::cout << "list9 : "; printList(list9);
    list8.swap(list9);
    std::cout << "Lists after swapping" << std::endl;
    std::cout << "list8 : "; printList(list8);
    std::cout << "list9 : "; printList(list9);
    
    // Direct access of lists
    std::cout << "Direct access using front() and back() " << std::endl;
    std::cout << "First element : list9.front() = " << list9.front() << std::endl;
    std::cout << "Last element : list9.back() = " << list9.back() << std::endl;


    // Iterator operaions 
    std::cout << "Demonstrating std::list iterator operations" << std::endl;
    std::cout << "Using begin() and end() to iterate -  list9: ";
    for(auto it = list9.begin(); it != list9.end(); ++it)
    {
        std::cout << *it << " ";
    }   
    std::cout << std::endl;
    std::cout << "Using cbegin() and cend() for const iteration -  list9: ";
    for(auto it = list9.cbegin(); it != list9.cend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using rbegin() and rend() for reverse iteration -  list9: ";
    for(auto it = list9.rbegin(); it != list9.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Using crbegin() and crend() for const reverse iteration -  list9: ";
    for(auto it = list9.crbegin(); it != list9.crend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Insert and remove operations of lists
    std::cout << "Insert and remove operations " << std::endl;
    std::cout << "list9 : "; printList(list9);

    list9.push_back(1);
    std::cout << "list9 : list9.push_back(1) : "; printList(list9);

    list9.pop_back();
    std::cout << "list9 : list9.pop_back() : "; printList(list9);

    list9.push_front(1);
    std::cout << "list9 : list9.push_front(1) : "; printList(list9);

    list9.pop_front();
    std::cout << "list9 : list9.pop_front() : "; printList(list9);

    auto it = list9.begin();
    std::advance(it, 3);
    list9.insert(it, 100);
    std::cout << "list9 : list9.insert(it, 10) : "; printList(list9);

    it = list9.begin();
    std::advance(it, 4);
    list9.insert(it, 5, 101);
    std::cout << "list9 : list9.insert(it, 5, 101) : "; printList(list9);
    
    it = list9.begin();
    std::advance(it, 7);
    list9.insert(it, {201, 202, 203});
    std::cout << "list9 : list9.insert(it, {201, 202, 203}) : "; printList(list9);

    it = list9.begin();
    std::advance(it, 7);
    list9.erase(it);
    std::cout << "list9 : list9.erase(it) : "; printList(list9);

    list9.remove(101);
    std::cout << "list9 : list9.remove(it) : "; printList(list9);

    list9.remove_if([](int i){return i % 2 == 0;});
    std::cout << "list9 : list9.remove_if([](int i){return i % 2 == 0}) : "; printList(list9);

    list9.resize(20); 
    std::cout << "list9 : list9.resize(20) : "; printList(list9);

    list9.resize(25, 1000);
    std::cout << "list9 : list9.resize(25, 1000) : "; printList(list9);

    list9.clear();
    std::cout << "list9 : list9.clear() : "; printList(list9);
    
    // Special modifying operations for lists
    std::list<int> list10, list11;
    for(int i = 0; i < 6; i++)
    {
        list10.push_back(i);
        list11.push_back(i * 2);
        list11.push_back(i*2);
    }

    std::cout << "list10 : "; printList(list10);
    std::cout << "list11 : "; printList(list11);

    std::cout << "unique() : removes duplicate of consecutive elements with same value" << std::endl;
    list10.unique(); list11.unique();
    std::cout << "list10 list10.unique(): "; printList(list10);
    std::cout << "list11 : list11.unique() "; printList(list11);

    std::cout << "splice(pos, c2) : moves all elements of c2 to c in front of iterator pos " << std::endl;
    it = list10.begin();
    std::advance(it, 4);
    std::list<int> list12 = list11;
    list10.splice(it, list12);
    std::cout << "list10 : list10.splice(it, list12) "; printList(list10);
    std::cout << "list12 : list10.splice(it, list12) "; printList(list12);
    
    std::cout << "splice(pos, c2) : moves element of c2pos to c in front of iterator pos " << std::endl;
    it = list10.begin();
    std::advance(it, 7);
    list12 = list11;
    list10.splice(it, list12, list12.begin());
    std::cout << "list10 : list10.splice(it, list12, list12.begin()) "; printList(list10);
    std::cout << "list12 : list10.splice(it, list12, list12.begin()) "; printList(list12);    

    std::cout << "sort() lists" << std::endl;
    list12 = {10, 5, 6, 200, 0, 1};
    std::cout << "list12 : before sort() "; printList(list12);
    list12.sort();
    std::cout << "list12 : after sort() "; printList(list12);    

    std::cout << "sort(op) lists" << std::endl;
    list12 = {10, 5, 6, 200, 0, 1};
    std::cout << "list12 : before sort() "; printList(list12);
    list12.sort([](int a, int b){return a > b;});
    std::cout << "list12 : after list12.sort([](int a, int b){return a > b;}) "; printList(list12);
    
     std::list<int> list13, list14;
    for(int i = 0; i < 6; i++)
    {
        list13.push_back(i);
        list14.push_back(i * 2);
    }
    std::cout << "list13 : "; printList(list13);
    std::cout << "list14 : "; printList(list14);
    std::cout << "c1.merge(c2) : assuming both containers have sorted elements, moves c2 elements in c1 and all elements are sorted" << std::endl;
    list13.merge(list14);
    std::cout << "list13 list13.merge(list14): "; printList(list13);
    std::cout << "list14 : list13.merge(list14) "; printList(list14);

    list13.clear(); list14.clear();
    for(int i = 0; i < 6; i++)
    {
        list13.push_back(i);
        list14.push_back(i * 2);
    }
    std::cout << "list13 : "; printList(list13);
    std::cout << "list14 : "; printList(list14);
    list13.sort([](int a, int b){return a > b;});
    list14.sort([](int a, int b){return a > b;});
    std::cout << "c1.merge(c2, op) : assuming both containers have sorted elements, moves c2 elements in c1 and all elements are sorted" << std::endl;
    list13.merge(list14, [](int a, int b){return a > b;});
    std::cout << "list13 list13.merge(list14): "; printList(list13);
    std::cout << "list14 : list13.merge(list14) "; printList(list14);

    list13.reverse();
    std::cout << "list13 : list13.reverse() "; printList(list13);
    return 0;
}