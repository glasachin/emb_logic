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
arch|	isize|	usize

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


### Floating-Point Type

