# Templates
It is used to define `generic classes` and `functions` which in turn provides support for `generic programming`. 

A template can be considered as a kind of `macro`. When an object of a specific type is defined for actual use, the `template definition` for that class is substituted with the required `data type`. The templates are sometimes called `parameterized classes or functions`.

**Syntax**

```
template<class T>
class classname
{
    ......
};
```

The prefix `template<class T>` tells the compiler that we are going to declare a template and use `T` as a type name in the declaration.

**Variable Declaration**

`classname<type> objectname(arglist);`

**Example**

```
#include<iostream>

using namespace std;

const int size1 = 3;

template <class T>
class vector
{
    T* v;   //type T vector
    public:
        vector()
        {
            cout << "hello";
            v = new T[size1];
            for(int i = 0; i < size1; i++)
                v[i] = 0;
        }

        vector(T* a)
        {
            for(int i = 0; i < size1; i++)
                v[i] = a[i];
        }

        T operator* (vector &y)
        {
            T sum = 0;
            for(int i = 0; i < size1; i++)
                sum += this -> v[i] * y.v[i];
            return sum;
        }
};


int main()
{
    cout << "1\n";
    int x[3] = {1,2,3};
    cout << "2\n";
    int y[3] = {4,5,6};
    cout << "3\n";
    vector <int> v1;
    cout << "4\n";
    vector <int> v2;
    cout << "5\n";
    v1 = x;
    cout << "6\n";
    v2 = y;
    cout << "7\n";
    v1 = x;
    v2 = y;
    int R = v1 * v2;
    cout << "R = " << R << endl;
    return 0;
}
```

## Class Templates with Multiple Parameters
We can use more than one generic data type is a `comma-separated` list with the `template` specification.

```
template<class T1, class T2, ...>
class classname
{
    .....
};
```

**Example**
```
#include<iostream>

using namespace std;

template <class T1, class T2>
class Test
{
    T1 a;
    T2 b;
    public:
        Test(T1 x, T2 y)
        {
            a = x;
            b = y;
        }
        void show()
        {
            cout << a << " and " << b << "\n";
        }
};

int main()
{
    Test <float, int> test1(2.314, 35);
    Test<int, char> test2(200, 's');

    test1.show();
    test2.show();
    return 0;
}
```




## Function Templates
It is similar to that of the class template. 

**Syntax**
```
templat<class T>
returntype functioname(args)
{
    .......
}
```

**Example**




## Function Templates with Multiple Parameters


**Syntax**

```
template<class T1, class T2,...>
returntype functionname(args)
{
    .....
}
```

**Example**

```
#include<iostream>

using namespace std;

template <class T1, class T2>
void display(T1 x, T2 y)
{
    cout << x << ", " << y << "\n";
}

int main()
{
    display(200, "Sachin");
    display(12.34, 1200);
    return 0;
}

```

## Overloading of Template Functions
A template function may be overloaded either by template functions or ordinary functions of its name. In such cases, overloading resolution is accomplished as follows:
1. Call an ordinary function that has an exact match.
2. Call a template function that could be created with an exact match.
3. Try normal overloading resolution to ordinary functions and call the one that matches.

**Template function with explicit function**

```
#include<iostream>
#include<string>

using namespace std;

template<class T>
void display(T x)
{
    cout << "Template display: " << x << endl;
}

void display(int x)
{
    cout << "Explicit Display: " << x << endl;
}

int main()
{
    display(100);
    display(12.34);
    display('C');
    return 0;
}
```

