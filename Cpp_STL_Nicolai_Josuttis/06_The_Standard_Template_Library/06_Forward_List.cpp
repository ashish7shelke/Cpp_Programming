#include <iostream>
#include <forward_list>

using namespace std;

// push_back() size() are not supported by forward_list as performance would be poor
// It cant search for an element and then delete it or insert another element in front of it
int main()
{
    forward_list<long> coll = {2, 3, 5, 7, 11, 13, 17};

    // resize 2 times
    // Poor performance
    coll.resize(9);
    coll.resize(10, 99);

    for(auto elem : coll)
    {
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}