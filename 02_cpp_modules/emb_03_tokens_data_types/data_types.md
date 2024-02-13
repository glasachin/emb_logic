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

