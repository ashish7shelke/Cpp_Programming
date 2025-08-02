#include <iostream>
#include <deque>

using namespace std;

// Double neded queue - Dynamic array that is implemented so that it can groe in both directions.
int main()
{
    deque<float> coll; // deque container for floating point elemtns

    // Insert elements from 1.1 to 6.6 each at the front
    for(int i = 1; i <= 6; i++)
    {

        // STL containers only provide those special member functions that in general have good performance
        // good performance normally means constant or lagarithmic complexity
        coll.push_front(i*1.1); // insert at the front
    }

    // print all elements followed by space
    for (int i = 0; i < coll.size(); ++i)
    {
        cout << coll[i] << " "; // access elements using subscript operator
    }
    cout << endl;
    
    return 0;
}