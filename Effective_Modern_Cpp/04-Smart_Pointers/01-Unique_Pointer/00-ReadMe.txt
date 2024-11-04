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
							Unique Pointer
--------------------------------------------------------------------------------
For exclusive ownership resource management.

Default std::unique_ptr are same size as raw pointers and for most operations they execute exactly same instructions.
We can thsi pointer where situations such as memory and cycle are tight.

As like raw pointer is small enough and fast enought, unique pointer is.

std::unique_ptr embodies exclusive ownership seamantics.

A non-null unique_ptr always owns what it points to.
Moving std::unique_ptr transfers ownership from source pointer to destination pointer. i.e. source pointer is set to null.

Copying of std::unique_ptr is not allowed. Copying will end up in two std::unique_ptr are owning same resource. And destruction time
both will destroy same memory and leads to conflict.
std::unique_ptr is move_only type poiter.
Upon destruction non-null std::unique_ptr destroys its resource. Destruction is accomplished by applying delete to raw pointer inside
the std::unique_ptr

By default, destruction would take place via delete, but during construction, std::unique_ptr object can be configured to use custom deleters
custome deleters are arbitary functions such as function objects arising from lambda expression.

By default std::unique_ptr size is same as raw pointer, as we add deleter function objects size keep on growing.

There are 2 forms of std::unique_ptr
	1) Individual objects 	-> std::unique_ptr<T>		-> This lacks indexing operator []
	2) Arrays				-> std::unique_ptr<T[]>		-> This lacks dereferencing operator* and operator ->

std::unique_ptr is the C++11 way to express exclusive ownership, but one of its most attractive feature is that it is easily and
efficiently converts to std::shared_ptr

std::unique_ptr is so well suited as a factory function return type.
As factory functions can't know whether callers will want to use exclusive ownership seamntics for the object they return or whether shared ownership.
