# Polymorphism and Virtual Functions

A base pointer, even when it is made to contain the address of a derived class, always executes the function in the base class. The compiler simply ignores the contents of the pointer and chooses the member function that matches the type of the pointer. In this case the polymorphism is achieved using `virtual` functions.

## Virtual Functions
when we use the same function name in both the base and derived classes, the function in base class is declared as `virtual`. When a function is made `virtual`, C++ determines which function to use at run time based on the type of object ponted to by the base pointer, rather than the type of the pointer. Thus, by making the base pointer to different objects, we can execute different versions of the `virtual` function.

**Example**

```
#include <iostream>

using namespace std;

class Base
{
    public:
        void display()
        {
            cout << "Display base" << endl;
        }

        virtual void show()
        {
            cout << "Show base" << endl;
        }
};

class Derived: public Base
{
    public:
        void display()
        {
            cout << "Display Derived" << endl;
        }

        void show()
        {
            cout << "Show Derived" << endl;
        }
};

int main()
{
    Base B;
    Derived D;
    Base *bptr;
    Derived *dptr;

    cout << "bptr points to Base" << endl;
    bptr = &B;
    bptr->display();
    bptr->show();

    cout << "Bptr points to Derived" << endl;
    bptr = &D;
    bptr->display();
    bptr->show();
}
```
**Output**
```
bptr points to Base
Display base
Show base
Bptr points to Derived
Display base
Show Derived
```



