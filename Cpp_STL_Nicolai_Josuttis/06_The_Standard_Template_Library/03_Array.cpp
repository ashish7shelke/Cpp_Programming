#include <iostream>
#include <string>
#include <array>

using namespace std;

// Do not provide resize() function
int main()
{
    // Array container of 5 string elements
    // We have to specify its size at creation time.

    // By default elements are initialized with default constructor of the elements type
    array<string, 5> coll = {"hello", "world"};

    // print each element with an index on a line
    for (int i = 0; i < coll.size(); i++)
    {
        cout << i << ": " << coll[i] << endl;
    }

    return 0;
}