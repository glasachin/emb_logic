# Basics


# Printin or output

`!` to indicate a macro

`println!("Hello world");`

**multiple combinations of literal strings**

`print!("{}, {}!", "hello", "world");`

1. `{}` are called `placeholders`


**Printing Integer Numbers**

`print!("My number: {}", 140);`


**adding numbers**

`print!("The sum is {}.", 80 + 45);`

`print!("{} + {} = {}", 34, 80, 80+34);`

`print!("{}", 90.3 + 34.9);`

`print!("{}", 2.7 + 1);` : Compilation error

`print!("{}", 2.7 + 1.);`


**Sequences of Statements**
```
print!("{} + ", 80);
print!("{} = ", 30);
print!("{}", 80 + 30);
```
The above code snippet will give output in a single line.

```
println!("This 
    is
    next 
    line");

Output:     This 
            is
            next 
            line
```


## Variables
1. `value`: which can be stored in memory
2. `object`: A portion of memory holding a value.

by default `variables` are `immutable`. However, we can make variable mutables. When a variable is immutable, once a value is bound to a name, you can’t change that value. 
```
fn main() {
    let x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");
}
```
This will give error message. 

We you can make them `mutable` by adding `mut` in front of the variable name

```
fn main() {
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");
}
```

## Constants
Like immutable variables, constants are values that are bound to a name and are not allowed to change, 
1. you aren’t allowed to use mut with constants. 
2. You declare constants using the `const` keyword instead of the `let` keyword, and the type of the value must be annotated.
3. Constants can be declared in any scope, including the global scope, which makes them useful for values that many parts of code need to know about.

`const THREE_HOURS_IN_SECONDS: u32 = 60 * 60 * 3;`


## Shadowing

We can declare a new variable with the same name as a previous variable. 
Rustaceans say that the first variable is shadowed by the second, which means that the second variable is what the 
compiler will see when you use the name of the variable. 

In effect, the second variable overshadows the first, taking any uses of the variable name to itself until either it 
itself is shadowed or the scope ends.

```
fn main() {
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");
}
```

difference between mut and shadowing is that because we’re effectively creating a new variable when we use the let keyword again,
we can change the type of the value but reuse the same name. 

```
let spaces = "   ";
let spaces = spaces.len();
```

```
let mut spaces = "   ";
spaces = spaces.len();
```
The error says we’re `not allowed to mutate a variable’s` type:

