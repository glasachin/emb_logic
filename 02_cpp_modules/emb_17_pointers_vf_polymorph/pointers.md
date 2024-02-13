# Pointers
all functionality of pointers is similar to whatever we have studied in C. Here we will discuss mainly about additional functionalities with reference to C++.

```data-type *pointer-variable;```

```
int *ptr, a;
ptr = &a;
```

## Pointers to objects
A pointer can point to an object created by a class. Object pointers are useful in creating objects at run time. We can also use an object pointer to access the public members of an object using `->` sign or `(*ptr).class_member()`. 

We can also create the objects using pointers and `new` operator:
```item *ptr = new item```

`Note`:If a class has a constructor with arguments and does not include an empty constructor, then we must supply the arguments when the object is created. 

We can also create an `array of objects` using pointers as:
```item *ptr = new item[10]```

## this Pointer
C++ uses a unique keyword called `this` to represent an object that invokes a member function. `this` is a pointer that points to the object for which `this` function was called. E.g. the function call `A.max()` will set the pointer `this` to the address of the object `A`. The starting address is the same as the address of the first variable in the class structure.

The pointer `this` acts as an implicity argument to all the member functions.

```
class ABC
{
    int a;
    ....
    ....
}

The private variable `a` can be used directly inside a member function, like
a = 123 or this->a = 123
```

`return *this` returns the `reference` of invoking object.

