# Class, objects and Constructor
A class contains two parts:
1. Data: it is private to the class
2. Member functions: only these can access the data items of the class.

An object is said to be an instance of a class. E.g.
```
class smallobj
{
    private:
        int somedata;
    public:
        void setdata(int d)
        {
            somedata = d;
        }
        void showdata()
        {
            cout << "\nData is " << somedata;
        }
};

```

## Using the class
We need to create the object of class in order to use it.

```smallobj s1, s2;```

Here, `s1` and `s2` are class objects.

## arrays as class member
arrays can be used as data items in classes. E.g.
```
class stack
{
    private:
        enumb {max = 10};
        int st[max];
        int top;
    public:
        stack() // constructor
        {
            top = 0;
        }

        void push(int var)
        {
            st[++top] = var;
        }

        int pop()
        {
            return st[top--];
        }
};
```

## Constructors
Member functions of the class can be used to initialize the data items of the class. Such member functions are known as `constructors`.

A `constructor` is a member function that is executed automatically whenever an object is created.

### Name of constructor
Constructor name is exactly the same as that of the class and No return type is used for constructors. 

E.g.
```
class rectange
{
    private:
        int width;
        int height;
    public:
        rectangle();
        rectangle(int, int);
        int area(void)
        {
            return width*height;
        }
};

rectangle::rectangle()
{
    // default constructor
    widht = 5;
    height = 5;
}

rectangle::rectangle(int a, int b)
{
    // overloaded constructor
    width = a;
    height = b;
}


int main()
{
    rectangle recta; // invoke default constructor
    rectangle rectb(3,5); // invokde overloaded constructor
}
```

### uniform initialization
constructors can be called in different ways:
* rectangle recta(3,5)  // functional form
* rectangle rectb = {10, 50} //assignment init
* rectangle rectc {50, 60} // uniform init
* rectangle rectd{}; // default constructor is called

### Member initialization in constructors
other members of the class can also be initialized directly, without resorting to statements in its body. This is done by `inserting` before the constructor's body, a `colon (:)` and a list of initializations for class members.

E.g.
```
rectangle::rectangle (int x, int y) {width = x; height = y;}

or
rectangle::rectangle (int x, int y) : width(x) {height = y;}

or
rectangle::rectangle (int x, int y) : widht(x), height(y) { }
```

## Destructors
These functions are called automatically when an object is destroyed. 
* It also have the same name as that of the class with a `~` sign preceding it.
* Similar to constructor, destructors also don't have a return value.

E.g.
```
class foo
{
    private:
        int data;
    public:
        foo() : data(0)
        {

        }
        ~foo()
        {
            // destructor
        }
};
```


## initializer list
An `initializer list` in C++ is a way to initialize class members directly in a constructor, before the constructor's body is executed. It's a comma-separated list of members and their initial values, placed after a colon following the constructor's parameter list.

```C++
class MyClass {
public:
    int x;
    int y;

    // Constructor with an initializer list
    MyClass(int a, int b) : x(a), y(b) {}
};
```

Initializer lists are particularly useful and sometimes necessary in several situations:
1. `Initializing const and reference members:` const and reference members must be initialized in the initializer list because they cannot be assigned values later.
2. `Initializing member objects without default constructors:`
If a class member is an object of another class that doesn't have a default constructor, it must be initialized in the initializer list, specifying the appropriate constructor and arguments.
3. `Initializing base class members:`
When inheriting from a base class, the base class constructor can be explicitly called in the initializer list.
4. `Efficiency:`
Initializer lists can be more efficient than assigning values in the constructor body, especially for complex objects, as they directly initialize the members instead of default-initializing them first and then assigning new values.
5. `Order of Initialization:`
Initializer lists guarantee that members are initialized in the order they are declared in the class, regardless of the order in the initializer list itself.

**if Class A has default constructor and parametrized constructor then how will we create object of class A in class B**

✅ Scenario 1: Use Default Constructor of Class A

```c++
class A {
public:
    A();             // default constructor
    A(int x);        // parameterized constructor
    void display();
};

#include "A.h"

class B {
private:
    A objA;   // uses default constructor

public:
    B();      // B's constructor
    void useA();
};

// b.cpp
#include "B.h"
#include <iostream>
using namespace std;

B::B() {
    cout << "Class B Constructor" << endl;
}

void B::useA() {
    objA.display();
}

```

✅ Scenario 2: Use Parameterized Constructor of Class A

```c++
class B {
private:
    A objA;

public:
    B(int x);   // Pass value to A's constructor
    void useA();
};

#include "B.h"
#include <iostream>
using namespace std;

B::B(int x) : objA(x) {
    cout << "Class B Constructor" << endl;
}

void B::useA() {
    objA.display();
}
```

**both class have both constructors**

```c++
// A.h
class A {
public:
    A();             // Default constructor
    A(int x);        // Parameterized constructor
    void display();
};

// B.h
#include "A.h"

class B {
private:
    A objA;

public:
    B();             // Default constructor
    B(int x);        // Parameterized constructor
    void useA();
};

// B.cpp
#include "B.h"
#include <iostream>
using namespace std;

B::B() : objA() {
    cout << "B's Default Constructor\n";
}

B::B(int x) : objA(x) {
    cout << "B's Parameterized Constructor\n";
}

void B::useA() {
    objA.display();
}

// A.cpp
#include "A.h"
#include <iostream>
using namespace std;

A::A() {
    cout << "A's Default Constructor\n";
}

A::A(int x) {
    cout << "A's Parameterized Constructor with x = " << x << endl;
}

void A::display() {
    cout << "Inside A::display()\n";
}

//main.cpp
#include "B.h"

int main() {
    B b1;        // Calls B's default constructor -> A's default constructor
    B b2(10);    // Calls B's param constructor -> A's param constructor

    b1.useA();
    b2.useA();

    return 0;
}

```

```NOTE: 
1. Make sure that constructor of A doesn't have any default arguments for above to work
2. Class A object in Class B should not be static. for static process is different.
3. if Class B doesn't define a constructor, the compiler will default-initialize its members. Hence, Class A must have a default constructor.
```



