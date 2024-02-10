# Inheritance
`Inheritance` is the means by which we can create new classes by reusing and expanding on existing class definitions. `Inheritance` is also fundamental to making polymorphism possible.

## Inheritance in Classes
Given a class A, suppose we create a new class B that is specialized version of class A. Then Class A is the base class (`parent`) and Class B (`child`) is the `derived` class. A base class is sometime referred to as a `superclass` and derived class is a `sub-class` of its base. 

A `derived` class automatically contains all the member variables of its base class and all the member functions. 

There are different forms of `inheritance`
1. single inheritance.
2. Multiple inheritance
3. Hierarchical inheritance
4. Multilevel inheritance
5. Hybrid inheritance


### Inheritance vs Aggregation
`derived` class objects should be sensible specializations of base class objects. In other words, a derived class should define a subset of the objects that are represented by the base class. 

## Defining Derived Classes

**Syntax**
```
class derived-class-name : visibility-mode base-class-name
{
    ........
    ........ // members of derived class
}
```

`visibility-mode` is optional and can be `public` or `private`. Default mode is `private`.

### Privately inherited
when a class is `privately` inherited by a derived class, `public members` of the base class become `private members` of the derived class and therefore the public members of the base class can only be accessed by the member functions of the derived class. 

They are inaccessible to the objects of the derived class. The result is that no member of the base clas is accessible to the objects of the derived class.

### Publicly inherited
in this case `public members` of the base class become `public members` of the derived class and therefore they are accessible to the objects of the derived class. 

In both the cases `private members` are not inherited and therefore, the private members of a base class will never become the members of its derived class.

```
class derived: private base
{
    members of derived
};
```

## Example


## Protected Members of a class
In addition to the public and private access specifiers for class members, we can declare members as protected. Within the class `protected` keyword has the same effect as the private keyword. `protected` member cannot be accessed from outside the class except from functions that have been specified as friend functions. 

Members of a base class that are declared as `protected` are freely accessible in member functions of a derived class, whereas the private members of the base class are not. 

```
class Box
{
    protected:
        double length {1.0};
        double width {1.0};
        double height {1.0};
    public:
        //----as before---
};
```
visibliblity of inherited members.

|Base class visibility|public derivation|private derivation|protected derivation|
|---|---|---|---|
|private|not inherited| not inherited| not inherited|
|protected|protected|private|protected|
|public|public|private|protected|


## changing the access specification of inherited members
we want to exempt a particular base class member from the effects of a protected or privated base class access specification.

`Note: There are several ways to establish the relationship in inheritance`


## Access Combinations

```
class A
{
    private:
        int privdataA;
    protected:
        int protdataA;
    public:
        int pubdataA;
};

class B : public A //pulicly-derived class
{
    public:
        void funct()
        {
            int a;
            a = privdataA;  //  error: not accessible
            a = protdataA;  // OK
            a = pubdataA; // OK
        }
};

class C : private A //privately-derived class
{
    public:
        void funct()
        {
            int a;
            a = privdataA;  //  error: not accessible
            a = protdataA;  // OK
            a = pubdataA; // OK
        }
};

int main()
{
    int a;
    B objB;
    a = objB.privdataA;     // error
    a = objB.protdataA;     //error
    objB.pubdataA;
}

It is not complete
```


