#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
class Stack {
    private:
        std::vector<T> elems;   //Elements
    
    public:
        void push(T const& elem);   // Push element
        void pop();                 // Pop element
        T const& top() const;       // return top element

        bool empty () const {       // return whether the stack is empty
            return elems.empty();
        }

        friend std::ostream& operator<< (std::ostream& strm, Stack<T> const& s)
        {
            /*for (T const& elem : s.elems)
                strm << elem << " ";*/
            s.printOn(strm);
            return strm;
        }
        
        std::ostream& printOn(std::ostream& strm) const
        {
            for (T const& elem : elems){
                strm << elem << " " ; // Call << for each element
            }
            return strm;
        }
        
};

template <typename T>
void Stack<T> :: push (T const& elem)
{
    elems.push_back(elem);  //append copy of passed elem
}

template <typename T>
void Stack<T>::pop()
{
    assert(!elems.empty());
    elems.pop_back();       // remove last element
}

/*
template <typename T>
T Stack<T>::pop()
{
    assert(!elems.empty());
    T elem = elems.back();  // Saves copy of last element
    elems.pop_back();       // remove last element
    return elem;
}
//As back() & pop_back() has undefined behaviour when empty
*/

template <typename T>
T const& Stack<T> :: top() const
{
    assert(!elems.empty());
    return elems.back();    // return copy of last element
}


