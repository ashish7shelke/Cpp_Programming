#include <iostream>
#include <map>
#include <string>
#include <mutex>
#include <filesystem>

class Status
{
    public:
        Status(bool s = false) : state(s)
        {
            std::cout << "Status()" << std::endl;
        }

        ~Status()
        {
            std::cout << "~Status()" << std::endl;
        }
        
        void setState()
        {
            state = true;
        }

        void resetState()
        {
            state = false;
        }

        bool getState()
        {
            return state;
        }
    private:
        bool state;
};

int main()
{
    std::cout << "Value Initialization inside IF Statement :: " << std::endl; 
    std::cout << "Case 1 :" << std::endl;
    if(Status S(true); S.getState() == true)
    {
        std::cout << "If with Initilization demo - Then part" << std::endl;
    }

    std::cout << "Case 2 :" << std::endl;
    if(Status S(true); S.getState() == false)
    {
        std::cout << "If with Initilization demo - Then part" << std::endl;
    }
    else
    {
        std::cout << "If with Initilization demo - Else part" << std::endl;
    }

    std::cout << "Case 3 :" << std::endl;
    std::cout << "Every initialized object must have name " << std::endl;
    if(Status {true}; true)
    {
        std::cout << "Every initialized object must have name - constructor & destructor immediately called after statement execution" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Map indertion check : Initialization inside IF Statement :: " << std::endl; 
    std::map<std::string, int> coll;
    coll["Hello"] = 1;
    coll["World"] = 2;

    std::cout << "Case 1 :: " << std::endl;
    if(auto [pos, ok] = coll.insert({"World", 3}); !ok)
    {
        // if insert failes then handle with iterator pos
        const auto& [key, value] = *pos;
        std::cout << "Map Insertion : Already there : " << key << std::endl;
    }

    std::cout << "Case 2 :: " << std::endl;
    if(auto [pos, ok] = coll.insert({"Welcome", 3}); !ok)
    {
        // if insert failes then handle with iterator pos
        const auto& [key, value] = *pos;
        std::cout << "Already there: " << key << std::endl;
    }
    else
    {
        std::cout << "Map Insertion : Successful : " << pos->first << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Mutex Lock : Initialization inside IF Statement :: " << std::endl;
    std::mutex collMutex;

    if(std::lock_guard<std::mutex> lg{collMutex}; !coll.empty())
    {
        for(auto& elem : coll)
        {
            std::cout << "Key: " << elem.first << "\tValue: " << elem.second << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Value Initialization inside SWITCH Statement :: " << std::endl; 
    using namespace std::filesystem;

    //switch(path p("D:/Programming/Git_Repos/Cpp_Programming/C++17_Complete_Guide_Josuttis/02_If_and_Switch_Initialization"); status(p).type())
    switch(path p("01_If_and_Switch_With_Initialization.cpp"); status(p).type())
    {
        case file_type::not_found:
            std::cout << p << " not_found" << std::endl;
            break;
        case file_type::directory:
            std::cout << p << " directory :" << std::endl;
            for(auto& e : std::filesystem::directory_iterator(p))
            {
                std::cout << "_ " << e.path() << std::endl;
            }
            break;
        default:
            std::cout << p << " exists" << std::endl;
            break;
    }

    return 0;
}