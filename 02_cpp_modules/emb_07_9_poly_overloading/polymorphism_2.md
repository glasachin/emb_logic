# Polymorphism and overloading


## Overload Comparison (<) operator

```
/* this adds two distances */
class distance
{
    private:
        int feet;
        float inches;
    public:
        distance() : feet(0), inches(0.0) // constructor
        { }

        distance(int ft, float in) : feet(ft), inches(in) // constructor with two arguments
        { }

        bool operator < ( distance ) const; //overload to add two distances
};

bool distance :: operator < (distance d2) const
{
    float bf1 = feet + inches / 12;
    float bf2 = d2.feet + d2.inches/12;
    return (bf1 < bf2) ? true : false;
}
```

## Overload '==' operator
we will compare two strings using these operators.

```
class String
{
    private:
        enum {sz = 80};
        char str[sz];
    
    public:
        String()
        {
            strcpy(str, "");
        }

        String(char s[])
        {
            strcpy(str, s);
        }

        void display()
        {
            cout << str;
        }

        void getstr()
        {
            cin.get(str, sz);
        }

        bool operator == (String ss) const
        {
            return (strcmp(str, ss.str) == 0) ? true : false;
        }
};

int main()
{

}

```

## Overloading 'assignment' (+=) operator

```
class distance
{
    private:
        int feet;
        float inches;
    public:
        distance () : inches(0.0)
        {
            feet = 0;
        }

        distance(int ft, float in)
        {
            feet = ft;
            inches = in;
        }

        void operator += (distance);
};

void distance :: operator += (distance d2)
{
    inches += d2.inches;
    feet += d2.feet;
    if(inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}

int main()
{
    distance d1, d2(10,15.6);
    d1 += d2;
    return 0;
}
```

`Note: if want to use += operator in more complex ways such as: dist3 = dist1 += dist2; then we would need to provide a return value.`

## Overloading 'subscript' ( [] ) operator
`[]` operator is used to access array elements and can also be overloaded. It is useful if we want to modify the way arrays work in C++.

The overload `subscript` operator must return by reference. We can understand this by different programs:

* separate put() and get() functions
* A single access() function using return by reference
* The overloaded `[]` operator using return by reference

### Separate get() and put() functions

```
int size = 100;
class safearray
{
    private:
        int arr[size];
    public:
        void putel(int n, int elvalue)
        {
            i
        }
}
```

### Overload [] operator

```
int size = 100;
class safearray
{
    private:
        int arr[size];
    public:
        int& operator [](int n)
        {
            if ( n < 0 || n >= size )
            {
                cout << "Index out of bound" ; 
                exit(1);
            }
            return arr[n];
        }
};

int main()
{
    safearray sal;
    for(int i = 0; i < size; i++)
        sal[i] = i*10;
    
    for(j = 0; j < size; j++)
    {
        int temp = sal[j];
    }
    return 0;
}
```
