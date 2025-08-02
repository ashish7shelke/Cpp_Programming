#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<char> coll; // List container for character elements

    //append elelments from 'a' to 'z'
    for (char c = 'a'; c <= 'z'; ++c)
    {
        coll.push_back(c);
    }

    // Print all the lements
    // use range based for loop
    for(auto elem : coll)
    {
        cout << elem <<  " ";
    }

    cout << endl;
    return 0;
}