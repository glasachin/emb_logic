# Namespace
a namespace is a section of a file that is given a name. 

1. **Avoid Name Collisions**:
Namespaces help prevent name conflicts between identifiers (like variables, functions, classes) from different libraries or parts of a large program. Without namespaces, if two libraries define a function with the same name, it would lead to a naming conflict. Namespaces allow you to separate these definitions.

2. **Code Organization**:
Namespaces help group related code logically. By placing classes, functions, and constants into namespaces, you can keep your code well-organized, especially in large projects. It creates a cleaner and more maintainable structure.

3. **Modular Development**:
Namespaces support modular programming by allowing you to separate concerns. Different developers or teams can work on different namespaces without worrying about naming conflicts or code mixing.

4. **Reusability**:
Code within namespaces can be reused across projects without the risk of interfering with existing code. Libraries or large applications can offer reusable components, and namespaces ensure their names don't clash with user code.

5. **Enhances Code Readability**:
When properly used, namespaces can make code more self-documenting and easier to understand. The hierarchy and scope are clearer, especially when dealing with multiple libraries or complex systems.

6. **Global Namespace Protection**:
All C++ code by default is part of the global namespace. If you don't use namespaces, all the names are introduced globally, which can cause conflicts. Placing code inside a namespace avoids cluttering the global namespace.

7. **Namespace Aliasing**:
C++ allows you to alias namespaces, which can simplify the usage of long or nested namespaces, improving code readability and reducing repetition.

8. **Extendibility**:
Namespaces can be extended across multiple files. You can declare and define parts of the same namespace in different files, allowing you to manage complex libraries or modules across multiple files.


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