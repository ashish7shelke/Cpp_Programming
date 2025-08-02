#include <vector>
#include <iostream>

using namespace std;

/*
    Vector manages its elements in dynamic array
    It enables random access, which means that we can directly access each element with corresponding index
    Appending and removing elements at the end of the array is very fast
    Inserting an element in the middle or at the beginning of arrray takes time because following elements have to be moved to make room for it while maintaining the order
*/
int main()
{
    vector<int> coll;   //VEctor container for integer elements
    // Vector is not initialized so default constructor creates an empty collection

    // Append elements with value 1 to 6
    for(int i = 1; i <= 6; i++)
    {
        // push_back() appends an element to the container
        // Appending an element is possible and reasonably fast.
        coll.push_back(i);
    }   
    
    // Print all elements followed by space

    // size() is provided by any container class except singly linded list forward_list
    for (int i = 0; i < coll.size(); ++i)
    {
        // By using subscript operator [] we can access an single element of vector
        cout << coll[i] << " ";
    }

    cout << endl;

    return 0;
}