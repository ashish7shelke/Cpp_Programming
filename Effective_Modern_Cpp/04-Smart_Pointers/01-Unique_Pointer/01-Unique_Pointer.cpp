#include <iostream>
#include <memory>
#include <cassert>
#include <fstream>
//Class fir run time polymorphism demo below
struct B
{
    virtual ~B() = default;

    virtual void bar() {std::cout << "B::bar" << std::endl;}

};

struct D : B
{
    D() {std::cout << "D::D()" << std::endl;}
    ~D() {std::cout << "D::~D()" << std::endl;}

    void bar() override {std::cout << "D::bar" << std::endl;}
};

//A function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

//Helper function for the custom deleter demo below
void close_file(std::FILE *fp)
{
    std::cout << "Clsong file" << std::endl;
    std::fclose(fp);
}

// unique_ptr based linked list demo
struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    ~List()
    {
        //Destroy list nodes sequencially in a loop
        //Defaulr construcor would have invoked its next destructor recursively, which would cause stack overflow
        while(head)
        {
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }

    void push(int data)
    {
        head = std::unique_ptr<Node> (new Node{data, std::move(head)});
    }
};

int main()
{
    std::cout << "1) Unique ownership semantics demo " << std::endl;
    {
        //Create unique resource
        std::unique_ptr<D> p = std::make_unique<D>();

        //Transfer ownership to 'pass-through'
        std::unique_ptr<D> q =  pass_through(std::move(p));

        //p is now in a moved from empty state , equal to nullptr
        assert(!p);
    }

    std::cout << "2) Runtime polymorphism demo" << std::endl;
    {
        //Derive a derived resource and point to it via base pointer
        std::unique_ptr<B> p = std::make_unique<D>();

        //Dyanmic dispatch works as expected
        p->bar();
    }

    std::cout << "3) custom deleter demo" << std::endl;
    std::ofstream("unique_ptr_demo.txt") << 'xyz'; //prepare file to read
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("unique_ptr_demo.txt", "r"), &close_file);

        if(fp)
            std::cout << char(std::fgetc(fp.get())) << std::endl;
        
        std::cout << "Deleter function is : " << fp.get_deleter() << std::endl;
        //close_file(is called here)
    }

    std::cout << "4) custom lambda deleter demo" << std::endl;
    std::ofstream("unique_ptr_demo.txt") << 'x'; //prepare file to read
    try
    {
        std::unique_ptr<D, void(*)(D*)> p (new D, [](D* ptr)
        {
            std::cout << "Destroying from custom deleter " << std::endl;
            delete ptr;
        });

        throw std::runtime_error("");
    }
    catch(const std::exception&)
    {
        std::cout << "Caught exception " << std::endl;
    }

    std::cout << "5) Array form of unique_ptr demo" << std::endl;
    {
        std::unique_ptr<D[]> p(new D[3]);

    }

    std::cout << "6) Linked_list demo" << std::endl;
    {
        List wall;
        const int enough {100};
        for(int beer = 0; beer != enough; ++beer)
        {
            wall.push(beer);
        }

        std::cout << enough << " bottles are on road " << std::endl;
    }
    return 0;
}
