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

## Member initialization in constructors
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

