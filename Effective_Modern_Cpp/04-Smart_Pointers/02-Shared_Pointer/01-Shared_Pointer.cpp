#include <iostream>
#include <memory>
#include <cassert>
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

struct Base
{
    Base() { std::cout << "Base::Base()\n"; }
 
    // Note: non-virtual destructor is OK here
    ~Base() { std::cout << "Base::~Base()\n"; }
};
 
struct Derived : public Base
{
    Derived() { std::cout << "Derived::Derived()\n"; }
 
    ~Derived() { std::cout << "Derived::~Derived()\n"; }
};
 
void print( std::shared_ptr<Base> const& sp)
{
    std::cout << "Shared ownership between 3 threads and released ownership from main: " << "\n\tget() = " << sp.get()
              << ", use_count() = " << sp.use_count() << '\n';
}

void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(987ms);
    std::shared_ptr<Base> lp = p; // thread-safe, even though the
                                  // shared use_count is incremented
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "Local pointer in a thread: " << std::endl;
        print( lp);
    }
}

 int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();
 
    std::cout << "Created a shared Derived (as a pointer to Base)" << std::endl;
    print(p);
 
    std::thread t1{thr, p}, t2{thr, p}, t3{thr, p};
    p.reset(); // release ownership from main
 
    print(p);
 
    t1.join();
    t2.join();
    t3.join();
 
    std::cout << "All threads completed, the last one deleted Derived.\n";

    return 0;
}
