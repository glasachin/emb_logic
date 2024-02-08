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

```