# Data Types
Every value in Rust is of a certain `data type`. Rust is a statically `typed language`, which means that it must know the types of all variables at compile time. 

two data type subsets: `scalar` and `compound`.

## Scalar Types
A scalar type represents a single value. Rust has four primary scalar types: `integers, floating-point numbers, Booleans, and characters`. 

### Integer Types

Length|	Signed|	Unsigned
---|---|---
8-bit|	i8|	u8
16-bit|	i16|	u16
32-bit|	i32|	u32
64-bit|	i64|	u64
128-bit|	i128|	u128
arch (architectrue dependent)|	isize|	usize

we can write integer literals in any of the forms shown in Table.

Number literals	|Example
---|---
Decimal|	98_222
Hex	|0xff
Octal|	0o77
Binary|	0b1111_0000
Byte (u8 only)|	b'A'

**Integer Overflow**

If we have a variable of type `u8` that can hold values between 0 and 255. If you try to change the variable to a value outside that range, such as 256, integer overflow will occur, which can result in one of two behaviors. 
1.  When you’re compiling in debug mode, Rust includes checks for `integer overflow` that cause your program to `panic` at runtime if this behavior occurs. Rust uses the term panicking when a program exits with an error; 
2. When you’re compiling in release mode with the `--release` flag, Rust does not include checks for integer overflow that cause panics. Instead, if `overflow` occurs, Rust performs `two’s complement `wrapping. In short, values greater than the maximum value the type can hold “wrap around” to the minimum of the values the type can hold. In the case of a u8, the value 256 becomes 0, the value 257 becomes 1, and so on.

To explicitly handle the possibility of overflow, you can use these families of methods provided by the standard library for primitive numeric types:

* Wrap in all modes with the wrapping_* methods, such as wrapping_add.
* Return the None value if there is overflow with the checked_* methods.
* Return the value and a boolean indicating whether there was overflow with the overflowing_* methods.
* Saturate at the value’s minimum or maximum values with the saturating_* methods.

**Special Operations**

Rust provides utility methods for integers:
1. `Check Overflow`: `.checked_add(), .wrapping_sub()`
2. `Bit Manipulation`: `.rotate_left()`, `.rotate_right()`
3. `Conversion`: `.to_string()`

```
fn main()
{
    let x: i32 = 5;
    let y = x.checked_add(2147483647); // return none on overslow
    println!("Result: {:?}", y); // Output none
}
```

### Floating-Point Type
Rust’s floating-point types are `f32` and `f64`, The default type is f64 because on modern CPUs, it’s roughly the same speed as f32 but is capable of more precision. `All floating-point types are signed`.

```
fn main() {
    let x = 2.0; // f64

    let y: f32 = 3.0; // f32
}
```

#### Numeric Operations
addition, subtraction, multiplication, division, and remainder. `Integer division truncates toward zero to the nearest integer`.
```
fn main() {
    // addition
    let sum = 5 + 10;

    // subtraction
    let difference = 95.5 - 4.3;

    // multiplication
    let product = 4 * 30;

    // division
    let quotient = 56.7 / 32.2;
    let truncated = -5 / 3; // Results in -1

    // remainder
    let remainder = 43 % 5;
}
```

### Boolean Type
`true` and `false`. Booleans are `one byte` in size. The Boolean type in Rust is specified using `bool`.

```
fn main() {
    let t = true;

    let f: bool = false; // with explicit type annotation
}
```

**Boolean Expressions**

`==` : is equal to
`!= `: is different from
`< ` : is less than
`<=` : is less than or equal to
`> ` : is greater than
`>=` : is greater than or equal to

`&&` : logical and
`||` : logical OR 
`!`  : logical not 

### Character Type

```
fn main() {
    let c = 'z';
    let z: char = 'ℤ'; // with explicit type annotation
    let heart_eyed_cat = '😻';
}
```
Rust’s char type is `four bytes` in size and represents a `Unicode Scalar Value`, which means it can represent a lot more than just ASCII. 
* Accented letters; Chinese, Japanese, and Korean characters; emoji; and zero-width spaces are all valid char values in Rust. 
* Unicode Scalar Values range from U+0000 to U+D7FF and U+E000 to U+10FFFF inclusive.


## Compound Types
Compound types can group multiple values into one type. Rust has two primitive compound types: `tuples` and `arrays`.

### Tuple Types
Tuples have a `fixed length`: once declared, they cannot grow or shrink in size.

We create a tuple by writing a `comma-separated` list of values inside parentheses. Each position in the tuple has a `type`, and the types of the different values in the tuple don’t have to be the same.

```
fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
}
```
To get the individual values out of a tuple, we can use pattern matching to destructure a tuple value,
```
fn main() {
    let tup = (500, 6.4, 1);

    let (x, y, z) = tup;

    println!("The value of y is: {y}");
}
```

We can also access a tuple element directly by `using a period (.) followed by the index` of the value we want to access. the first index in a tuple is `0`.

```
fn main() {
    let x: (i32, f64, u8) = (500, 6.4, 1);

    let five_hundred = x.0;

    let six_point_four = x.1;

    let one = x.2;
}
```

The tuple without any values has a special name, `unit`. This value and its corresponding type are both written `()` and represent an empty value or an empty return type.


### Array Type
Unlike a tuple, every element of an `array` must have the `same type`. Unlike arrays in some other languages, arrays in Rust have a 
fixed length.

```
fn main() {
    let a = [1, 2, 3, 4, 5];
    let b: [i32; 5] = [1, 2, 3, 4, 5];
}
```

You can also initialize an array to contain the same value for each element by specifying the initial value, followed by a `semicolon`, and then the length of the array in 
square brackets
```
let a = [3; 5];
```
The array named a will contain 5 elements that will all be set to the value 3 initially. 
This is the same as writing `let a = [3, 3, 3, 3, 3];` but in a more concise way.

**Accessing Array Elements**

```
fn main() {
    let a = [1, 2, 3, 4, 5];

    let first = a[0];
    let second = a[1];
}
```

## Type Conversion
Rust doesn't automatically convert types. Explicit casting is required using the 
`as` keyword.

```
fn main()
{
    let x: i32 = 10;
    let y: f64 = x as f64 + 3.5;
    println!("x as f64: {}", y);
}
```

