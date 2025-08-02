#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    unordered_multiset<string> cities {"Delhi", "Mumbai", "Berlin", "London", "Paris", "New York", "Tokyo"};

    for(const auto& elem : cities)
    {
        cout << elem << " ";
    }
    cout << endl;

    cities.insert({"London", "Munich", "Frankfurt"});

    for(const auto& elem : cities)
    {
        cout << elem << " ";
    }
    cout << endl;
}