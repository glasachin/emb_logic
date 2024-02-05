# Namespace
a namespace is a section of a file that is given a name. 
**E.G.**
```
namespace geo
{
    const double PI = 3.14;
    double circumf(double radius)
    {
        return 2*PI*radius;
    }
}
```

## Accessing namespace members
**Method 1**
```double c = geo::circumf(10);```

**Method 2**
```
using namespace geo;
double c = circumf(10);
```

The `using` directive causes the namespace to be visible from that point onward. However, we can restrict the region where the `using` directive is in effect to a particular block, such as function:

```
void seriousCalcs()
{
    using namespace geo;
    double c = circumf(r);
}
```

## Namespace in header files
Namespaces are most commonly used in header files containing library classes or functions.

## Multiple Namespace Definitions
**definition 1**
```
namespace geo
{
    const double PI = 3.14;
}
```

**definition 2**
```
namespace geo
{
    double circumf(double radius)
    {
        return 2*PI*radius;
    }
}
```

The second definition is just a continuation of the same definition. It allows a namespace to be used in several header files, which can then all be included in a source file.

## Declaration outside namespace
We can place declarations outside a namespace as well and it will behave as if they were inside it.

```
namespace beta
{
    int uno;
}
int beta::dos;
```

Here both `uno` and `dos` are declared in the namespace `beta`.

## Un-named Namespace
We can create a namespace without a name. It will create the namespace to be visible throughout the file in which it's defined but not visible from other files. Compiler gives an internal name unique to the file for such namespaces.

```
/*----File A.CPP-----*/
namespace
{
    int gloVar = 111;
}
funcA()
{
    cout << gloVar;
}

/*-----File B.CPP---------*/
namespace
{
    int gloVar = 222;
}
funcB()
{
    cout << gloVar;
}
```