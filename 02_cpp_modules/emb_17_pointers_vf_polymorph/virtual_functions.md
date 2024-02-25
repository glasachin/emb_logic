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

`Note: We must access virtual functions through the use of a pointer declared as a pointer to the base class as run time polymorphism is achieved only when a virtual function is accessed through a pointer to the base class.`

### Rules for Virtual Functions
1. The VFs must be members of some class.
2. They cannot be static members.
3. They are accessed by using object pointers.
4. A VF can be a friend of another class.
5. A VF in a base class must be defined, even though it may not be used.
6. The prototype of the base class version of a VF and all the derived class versions must be identical. If they have different prototypes, C++ considers them as `overloaded` functions and the VF mechanism is ignored.
7. We cannot have `virtual constructors` but we can have `virtual destructors`.
8. While a base pointer can point to any type of the derived object, the reverse is not true. i.e. we cannot use a pointer to a derived class to access an object of the base type.
9. When a base pointer points to a derived class, incrementing or decrementing it will not make it to point to the next object of the derived class. It is incremented of decremented only relative to its base type. Hence, this should not be used to move the pointer to the next object.
10. If a VF is defined in the base class, it need not be necessarily redefined in the derived class. In such cases, calls will invoke the base function.

## Pure Virtual Functions




