#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, double> coll {
        {"tim", 9.9},
        {"struppi", 11.77}        
    };

    for(pair<const string, double>& elem : coll)
    {
        cout << elem.first << ": " << elem.second << endl;
    }
    cout << endl;
}