# Polymorphism
polymorphism means having different forms. C++ allows to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respecively.

Function or method overloading is a process of implementing the polymorphism. 

## Polymorphism: Function Overloading
using function overloading we can define multiple functions with same name but different argument types and functioning.

### Example
We can have mulitple functions with same naem and different data types or argument etc.

```
double add(double x, double y)
{
    return x + y;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

Which function will be called depends upon the function call in program.

`Note: function's return type is not considered when overloading functions`
e.g.

```
int randomfun();
double randomfun();
```
int this case compiler will throw an error.

## Polymorphism: Operator Overloading
`operator overloading` refers to giving the normal C++ operators, such as +, *, <= and += etc. additional meanings when they are applied to user-defined data types.

e.g.

`+` normally works with basic types such as `int` and `float` but we can modify it to add `objects` and `strings` as well.

### Overloading Unary Operators
unary operators act on only one operand. e.g. `++, --`. The keyword `operator` is used to overload the operator.

* overloading `++` doesn't take any argument.
* return type of overloading defines the application of operator.

e.g.
```
class counter
{
    private:
        unsigned int count;
    public:
        counter() : count(0); //assign value to count
        { }
        
        unsigned int get_count()
        {
            return count;
        }

        void operator ++ ()     // overloaded ++ to act on objects.
        {
            ++count;
        }

        counter operator -- ()
        {
            --count;
            counter temp; // make a temperary object
            temp.count = count;
            return temp;
        }
};

int main()
{
    counter c1, c2, c3;
    ++c1;
    c3 = --c2;
}
```

### Overloading Binary Operators

`Arithmatic Operators`

syntax for binary operator overloading is as follows:
```<class_name> operator + ( <class_name> ) cost;```

use is as follows:
    `c = a + b`

The argument on the lieft side of the operator (`a`) is the object of which the operator is a member. The object on the right side of the operator (`b`) must be furnished as an argument to the operator. The operator returns a value, which can be assigned or used in other ways. (This rule doesn't apply on `friend` functions and `operators`)

e.g.
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

        void getdist()
        {
            cin >> feet;
            cin >> inches;            
        }

        distance operator + ( distance ) const; //overload to add two distances
};

distance distance :: operator + (distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i > 12.0)
    {
        i -= 12.0;
        f++;
    }
    return distance(f,i);
}

int main()
{
    distance dist1, dist3, dist4;
    dist1.getdist();
    distance dist2(11, 6.25);
    dist3 = dist1 + dist2; // single + operator
    dist4 = dist1 + dist2 + dist3; // multiple '+' operator
}

```
### Multiple Overloading
We can do multiple overloading on same operator as well. e.g. it can be used to add distances and to concatenate strings as well.