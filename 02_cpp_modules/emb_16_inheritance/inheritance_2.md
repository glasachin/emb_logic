# More on inheritance

## Multilevel Inheritance
The class A serves as a bse class for thederived class B, which in turn serves as a base class for the derived class C. The chain `ABC` is known as inheritance path.

### Example
```
class A{...};   // Base Class
class B: public A {.....};  // B derived from A
class C: public B {.....}; // C derived from B
```

The above mentioned process can be extended to any number of levels.

## Multiple Inheritance
A class can inherit the attributes of two or more classes. This is known as `multiple inheritance`. It allows us to combine the features of several existing classes as a starting point for defining new classes. It is like a child inheriting the physical features of one parent and the intelligence of another.

**Syntax**
```
class D: visibility B-1, visibility B-2 ...
{
    .....
    .....
};
```

## Hierarchical Inheritance
It is used to support the `hierarchical` design of a program. Many programming problems can be cast into a hierarchy where certain feature of one level are shared by many other below that level.

![Hierarchical Design](./hieriarchical_classification_pic.jpg)

## Hybrid Inheritance
This contains two or more types of inheritance to design a program.


## Virtual Base Classes
If we combine different types of inheritance then the following situation can arise (as shown in figure). This is termed as `multi path inheritance`. 
![](./multipath.jpg)

This kind of situation pose some problems. All the public and protected members of the `Base Class` will be inherited into the final class `twice`. This introduces `ambiguity` and should be avoided. 

This mulipath problem can be avoided by making the common base clas as `virtual base class` while declaring the direct or intermediate base classes.

### Example
```
class A
{
    ....
    ....
};

class B1: virtual public A
{

};

class B2: public virtual A
{

};

class C: public B1, public B2
{

};
```

## Abstract Classes
An `abstract` class is one that is not used to create objects. An `abstract` class is designed only to act a base class (to be inherited by other classes). It provides a base upon which other classes may be built. It holds significance as far as logical program design is concerned. Also, we may include some of the common characteristics of all the derived classes in the abstract base class itself.

A class can only be considered as an abstract class if it has at least `one pure virtual function`. 

## Constructors in Derived Classes
As long as no base class constructor takes any arguments, the derived class need not have constructor function. 

However, if any base class contains a constructor with one or more arguments, then it is mandatory for the derived class to have a constructor and pass the arguments to the base class constructors. 

When both the derived and base classes contain constructors, the base constructor is executed first and then the constructor in the derived class is executed. 

In case of multiple inheritance, the base classes are constructed in `the order in which they appear in the declaration of the derived class`. Similarly, in a multilevel inheritance, the constructors will be executed in the order of inheritance.

The constructor of the derived class receives the entire list of values as its arguments and passes them on to the base constructors in the order in which they are declared in the derived class. The base constructors are called and executed before executing the statements in the body of the derived constructor.

![](./Constructors+in+Derived+Class.jpg)


