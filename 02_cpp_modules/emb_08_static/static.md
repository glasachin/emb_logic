# Static Members
`static` means something maintaining state either forever or up to some point. Following points are to be noted regarding the static members:

1. They are allocated as soon as the execution of program starts, regardless of their scope.
2. They are de-allocated at the end of the program execution.
3. Since they have lifetime, during the whole of the program execution, they retain the values in them.
4. They are usable in their scope only though their life is for the whole of the program execution.
5. on Creation, they are initialized with `zero`.

## Example 1

```
#include<iostream>
using namespace std;

class test
{
    public:
        static int objCounter;
        test()
        {
            objCounter++;
        }
        ~test()
        {
            objCounter--;
        }
};

int test::objCounter;

int main()
{
    test obj1, obj2, obj3, *ptr;
    cout << "Number of ojbects: " << test::objCounter << endl;

    ptr = new test;
    cout << "Number of ojbects: " << test::objCounter << endl;

    delete ptr;
    cout << "Number of ojbects: " << test::objCounter << endl;
    return 0;
}
```

`Important Points`
* Static members of the class must be re-declared outside the class (globally).
* Static data member can be used directly in static member functions only, otherwise they are used using Scope resolution operator.
* Static Members are created only once as soon as the execution of the program starts and the same is shared among all the objects (obj1, obj2, *ptr) of the class.
* Static members are constrained by the access modifiers (public, private, protected)
* Static functions can only use static data member or local variables, it can not use non-static data members of the class.

### Important

```
#include<iostream>
using namespace std;

class test1
{
    static int testvar;
    int testvar1;
    public:
        static void testfunc()
        {
            cout << "Value of static variable: " << testvar << endl;

            cout << "value of nonstatic variable: " << testvar1 << endl;
        }
};

int test1::testvar;

int main()
{
    test1::testfunc();
    return 0;
}
```

This line `cout << "value of nonstatic variable: " << testvar1 << endl;` will give compilar error:
illegal reference to non-static member