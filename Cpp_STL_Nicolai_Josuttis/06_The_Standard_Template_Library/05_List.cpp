#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<char> coll;
    
    // Append elements from 'a' to 'z
    for (char c = 'a'; c <= 'z'; ++c)
    {
        coll.push_back(c);
    }

    while(! coll.empty())
    {
        // front() returns first element 
        cout << coll.front() << " ";

        // removes first element
        coll.pop_front();  
    }
    cout << endl;

    return 0;
}