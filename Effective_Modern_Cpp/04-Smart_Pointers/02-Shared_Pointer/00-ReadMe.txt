*------------------------------------------------------------------------------*
							Smart Pointer
--------------------------------------------------------------------------------

Problems faced with raw pointers.
	1) It's declaration doesn't indicate whether it points to a single object or to an array.
	2) It's declaration reveals nothing about whether to destroy what it points to when access is done.
	3) There is no way defined how to destroy what pointer is pointing to. Use delete or any other function to destroy.
	4) If we decide to use delete, its not clear to use delete or delete[].
	5) There's is typically no way to tell if the pointer dangles.

Smart pointers are one way to address these issues.
Smart pointers are wrappers around raw pointerthat act much like raw pointers they wrap, but avoid many of their pitfalls.

There are 4 smart pointers
	1) std::autp_pter
	2) std::unique_ptr
	3) std::shared_ptr
	4) std::weak_ptr

All these are designed to help manage the life times of dynamically allocated objects.
To avoid resource leaks by ensuring that such objects are destroyed in the appropriate manner at the appropriate time.

*------------------------------------------------------------------------------*
							Shared Pointer
--------------------------------------------------------------------------------
An object accessede via std::shared_ptr has its lifetime managed by those pointers through shared ownership.
No specific std::shared_ptr owns the object. Instead all std::shared_ptrs pointing to it colalborate to ensure its destructionat the point 
where it's no longer needed. When the last shared_ptr poinitng to an object stops pointing there, that shared_ptr destroys the object it points to.

std::shared_ptr has resource's reference count, a value associated with the resource that keeps track of how many std::shared_ptrs are pointing to resource.

std::shared_ptr are twice the size of a raw pointer. It internally contains raw pointer and resource's reference count.

Memory for the reference count must be dynamically allocated.

Increament and decreament of referecne count must be atomic.

While move constructing a std::shared_ptr from another std::shared_ptr sets the source std::shared_ptr to null, that means that old std::shared_ptr
stops poinitng the resource at the moment new std::shared_ptr starts. As a result no reference count manipulation is required.

Moving std::shared_ptr is faster than copying them.
Copying requires increamenting the reference count but moving doesn't.

Similar to std::unique_ptr std::shared_ptr has default delete function also can be supplied with deleter function.
But design differs from std::unique_ptr. In std::unique_ptr, the type deleter is part of the smart pointer. Dor std::shared_ptr it's not.
Deleter is not part of pointer template type in std::shared_ptr.
So two std::shared_ptrs with different deleter functions can be assigned.

Size of custom deleter doesn't change the size of std::shared_ptr.
std::shared+ptr stores deleter function object data in some other memory which is not part of std::shared_ptr object.

std::shared_ptr<T> --> contains (1) ptr to T and (2) Ptr to control block
	Control block contains, reference count, custom deleter and weak count.

When first time std::shared_ptr is poinitng to object control block is created.
There are some rules for creating control block
1) std::make_shared always creates a control block
2) when std::shared_ptr is constructed from a unique-ownership pointer
3) when std::shared_ptr constructor is called from a raw pointer

