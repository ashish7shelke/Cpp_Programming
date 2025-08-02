#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    multiset<string> cities {
        "Delhi", "Mumbai", "Berlin", "London", "Paris", "New York", "Tokyo"
    };

    for(const auto& elem : cities)
    {
        cout << elem << " ";
    }
    cout << endl;

    cities.insert({"London", "Berlin", "Delhi"});

    for(const auto& elem : cities)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
