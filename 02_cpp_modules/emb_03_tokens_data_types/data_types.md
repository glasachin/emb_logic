# Tokens, Data Types etc
Several data types are similar to that of C. Here, we will be mentioning the new one in C++ only.


## Reference Variables
A `reference` variable provides an `alias` for a previously defined variable. Syntax is follows:

`data-type & reference-name = variable-name`

**Example**
```
float total = 100;
float & sum = total;
```

Here sum will be alternative name for the total variable.

``` cout << total; and cout << sum;``` will give the same result.

make `sum = 0` will change the value of both.

A reference variable must be `initialized` at the time of declaration. In C++, `&` have additional meaning. Here `&` is not an address operator. 
```
int n[10];
int & x = n[8];
```
In the above code, `x` is an alternative to the arrya element `n[8]`.

**Pointer and Reference**
the following are also allowed:
```
int x;
int *p = &x;
int & m = *p;
```

**Illegle Instructions**
```
int & x = 50;
char & a = '\n';
```

A non-const, lvalue reference cannot be bound to a constant.

**Application in Functions**
```
void f(int & x)
{
    x = x + 10;
}

int main()
{
    int m = 10;
    f(m);   //function call
}
```

The above function calling is known as `call by reference`. The value of m becomes 20 after the function is executed. 


## Operators in C++

* `::`      scope resolution operator
* `::*`     pointer-to-member declaratior
* `->*`     pointer-to-member operator
* `.*`      Pointer-to-member operator
* `delete`  memory release operator
* `endl`    Line feed operator
* `new`     Memory allocation operator
* `setw`    Field width operator

## Memory Management Operators
C++ supports additional two unary operators `new` and `delete` for runtime memory allocation. Since these operators manipulate memory on the freee store, they are also known as `free store` operators. 

A data object created inside a block with `new`, will remain in existence until it is explicityly destroyed by using `delete`. Thus the lifetime of an object is unrelated to the block structure of the program.

`pointer-variable = new data-type`

**Example**
`int *p = new int`


We can also initialize the memory using the `new` operator. This is done as follows:

`pointer-variable = new data-type(value)`

**Example**
```
int *p = new int(25);
float *q = new float(7.5);
```

`new` can be used to create a memory space for any data-type including `arrays`, `structures`, `classes` etc. 

**Array Example**
```
int *p = new int[10];
```
It will create a memory space for an array of 10 integers.

### Delete

`delete pinter-variable`

to delete  the dynamically allocated array following form of `delete` will be used:
```delete [] pointer_variable```

`delete []p;`





