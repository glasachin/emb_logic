# Smart Pointers
In C/C++, deallocating a pointer can cause a memory leak that may crash the program. A special category of pointers ensures that programs are free of memory and resource leaks and are safe from exceptions. To deallocate unused memory and free the destroyed object’s memory, Smart pointers are used.
1. auto_ptr (deprecated) in c++11
2. unique_ptr
3. shared_ptr
4. weak_ptr

## Unique Pointers
The `unique_ptr` is a smart pointer that owns and manages another object via a pointer. It disposes of the object using the associated deleter when unique_ptr goes out of scope. Out of scope means that either the unique_ptr object is destroyed or is assigned another pointer. The default deleter destroys the object and deallocates the memory using the delete operator.

**Syntax**

`unique_ptr<T> ptr(raw);`

where,

`ptr` – pointer of unique_ptr type,

`raw` – raw pointer to type T,

`T` is the type of value pointed to by ptr.

It has three main functions:

* `get()` returns a standard pointer to an object based on the unique_ptr pointer without transferring its ownership.
 
* `release()` returns a standard pointer based on the unique_ptr pointer with the transfer of ownership.
 
* `reset()` resets the ownership of the object. The unique_ptr pointer's value is changed to NULL.

**Example**

```
#include <iostream>
#include <memory>
using namespace std;

class A 
{
	public:
		void display() {}
};

unique_ptr<A> fun()
{
	unique_ptr<A> ptr(new A);
	cout << "ptr: " << ptr.get() << endl;
	return ptr;
}

int main()
{
	unique_ptr<A> x(new A);
	cout << "x" << endl;
  
	// returns address of a
	cout << "Before Transfer" << x.get() << endl;

	// transferring ownership
	unique_ptr<A> y = move(x);
  
	// x is empty
	cout << "After Transfer " << x.get() << endl;
	cout << "y" << endl;
	cout << "Before Call " << y.get() << endl;

	// calling fun()
	y = move(fun());
	cout << "After call " << y.get() << endl;

	return 0;
}
```

## Shared Pointers
The `shared_ptr` pointer shares the ownership of an object while storing a pointer to another object. It uses the `reference counting ownership model`, which maintains the reference count of the pointer with all copies of the shared_ptr. Unlike a simple pointer, it has an associated control block that keeps track of the reference count for the managed object. This reference count is shared among all the copies of the shared_ptr instances pointing to the same object, ensuring proper memory management and deletion. 

Reference counting is a way of sorting the number of references, disk space, memory block and other resources. A counter is incremented every time a new pointer points to the resource and decremented when the destructor of an object is called.

An object referenced by the `raw pointer` is not destroyed until the reference count is greater than zero. A reference count greater than zero implies that all copies of shared_ptr have not been deleted.

`Shared_ptr` is used to point to member objects while owning the object they belong to. Multiple threads on different instances of shared_ptr can be called without additional synchronisation, even if the instances are copies.

**Syntax**
`shared_ptr<T> ptr;`

`shared_ptr<T> ptr(raw);`

where

`ptr` refers to the name of the shared_ptr,

`T` denotes the data type of the pointer it points to,

`raw` is a pointer to data of type T.

1. Initialization using a New Pointer

`shared_ptr<T> ptr (new T());`

`shared_ptr<T> ptr  = make_shared<T> (new T());`

2. Initialization using existing Pointer

`shared_ptr<T> ptr(already_existing_pointer);`

`shared_ptr<T> ptr = make_shared (already_existing_pointer);`



The methods supported by shared_ptr pointer:

* `get()` returns a pointer based on the shared_ptr pointer without transferring rights to the object. 
 
* `swap()` swaps the values of two pointers.
 
* `reset()` resets the ownership of the object.
 
* `use_count()` returns the number of copies of the object pointers.

* `unique()`	Check if there is only one std::shared_ptr owning the object (reference count is 1).

**Example**

```
#include <iostream>
#include <memory>
using namespace std;
// Define a singly linked list node
struct Node {
	int data;
	shared_ptr<Node> next;

	Node(int val)
		: data(val)
		, next(NULL)
	{
	}
};

class LinkedList {
public:
	LinkedList()
		: head(NULL)
	{
	}

	// Insert a new node at the end of the linked list
	void insert(int val)
	{
		shared_ptr<Node> newNode = make_shared<Node>(val);
		if (!head) {
			head = newNode;
		}
		else {
			shared_ptr<Node> current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	// Delete a node with a given value from the linked list
	void del(int val)
	{
		if (!head) {
			return;
		}
		if (head->data == val) {
			head = head->next;
			return;
		}
		shared_ptr<Node> current = head;
		while (current->next
			&& current->next->data != val) {
			current = current->next;
		}
		if (current->next && current->next->data == val) {
			current->next = current->next->next;
		}
	}

	// Traverse and print the linked list
	void Print()
	{
		shared_ptr<Node> current = head;
		while (current) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

private:
	shared_ptr<Node> head;
};

int main()
{
	LinkedList linkedList;

	// Insert nodes into the linked list
	linkedList.insert(1);
	linkedList.insert(2);
	linkedList.insert(3);

	// Print the linked list
	cout << "Linked List: ";
	linkedList.Print();

	// Delete a node and print the updated linked list
	linkedList.del(2);
	cout << "Linked List after deleting 2: ";
	linkedList.Print();

	return 0;
}

```

## Weak Pointer
`weak_ptr` holds a weak reference to an object managed by the `shared_ptr`. It must be converted to `shared_ptr` to access the referenced object. Thus, `weak_ptr` is created as a `copy of shared_ptr`. weak_ptr implements temporary ownership and does not own the object it points to. It tracks the object, which is then converted to shared_ptr to assume temporary ownership.

`weak_ptr` can also break `reference cycles` that are formed by the objects managed by `shared_ptr`. This helps solve `Cyclic Dependency Problems` with `shared_ptr`. If two classes A and B point to each other using a shared_ptr, the use_count will never reach zero, and they never get deleted. weak_ptr can prevent this problem as they are not reference counted. The shared_ptr of class A can be declared as a weak_ptr declaring A_ptr as weak_ptr. Hence, class A does not own the object and can only access it.

To change the object a `weak_ptr` pointer points to, it is converted into a shared_ptr pointer using the lock() method. If the original shared_ptr gets destroyed, then the object's lifetime continues until the temporary shared_ptr is destroyed.

**Syntax**

`shared_ptr<T> shared(raw);`

`weak_ptr<T> weak = shared;`

where

`raw` – a raw pointer pointing to data of type T,

`shared` – a pointer of shared_ptr type,

`weak` – a pointer of weak_ptr typ,

`T` – data type pointed to by raw, shared, weak pointers.

The methods defined for weak_ptr are:

* `lock()` converts a pointer of weak_ptr type into shared_ptr type.
 
* `swap()` swaps weak_ptr type pointers.

```
#include <memory>
#include <iostream>
int main()
{
    // shared_ptr 
    std::shared_ptr<int> shrd_ptr_1(new int(8));
    std::shared_ptr<int> shrd_ptr_2(new int(10));
    
    // weak_ptr
    std::weak_ptr<int> wk_ptr_1(shrd_ptr_1);
    std::weak_ptr<int> wk_ptr_2(shrd_ptr_2);
 
    std::cout << "Before swap wk_ptr_1 = " << *wk_ptr_1.lock() << std::endl;
  
    std::cout << "Before swap wk_ptr_2 = " << *wk_ptr_2.lock() << std::endl;

    // swapping weak_ptr_1 and weak_ptr_2
    swap(wk_ptr_1, wk_ptr_2);
    std::cout << " After swap wk_ptr_1 = " << *wk_ptr_1.lock() << std::endl;
  
    std::cout << "After swap wk_ptr_2 = " << *wk_ptr_2.lock() << std::endl;

    std::cout << "Initial count the number_of_weak_ptr : " << wk_ptr_1.use_count() << std::endl;

    std::shared_ptr<int> shrd_ptr_3(shrd_ptr_2);
    
    std::cout << "Final count the number_of_weak_ptr : " << wk_ptr_1.use_count() << std::endl;
    return (0);
}
```

