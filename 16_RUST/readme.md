# Rust
Rust's performance is comparable to C and C++ because it compiles directly to machine code. Developers can write low-level, highly optimized code without sacrificing safety. This makes it ideal for use cases like game engines, operating systems, embedded systems, and high-performance web services.


**Installations**

1. `sudo apt install curl build-essential -y`

2. `curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh` : The command downloads a script and starts the installation of the rustup tool, which installs the latest stable version of Rust. 

`NOTE`: You will also need a linker, which is a program that Rust uses to join its compiled outputs into one file. It is likely you already have one. If you get linker errors, you should install a C compiler, which will typically include a linker. A C compiler is also useful because some common Rust packages depend on C code and will need a C compiler.

3. `source $HOME/.cargo/env` ==> update environment

4. `rustc --version` ==> verify version

5. `sudo apt-get install rustc` ==? `rustc` is the official Rust Compiler. It converts into machine code.


## Anatomy 

```
fn main()
{

}
```
The `main` function is special: it is always the first code that runs in every executable Rust program. Here, the first line declares a function named main that has no parameters and returns nothing. If there were parameters, they would go inside the parentheses ().

`!`: It specifies that the preceding name idicates a `macro`.

## Cargo
`Cargo` is Rust’s build system and package manager. Rust projects because Cargo handles a lot of tasks for you, such as building your code, downloading the libraries your code depends on, and building those libraries.

If we had built the “Hello, world!” project with Cargo, it would only use the part of Cargo that handles building your code. As you write more complex Rust programs, you’ll add dependencies, and if you start a project using Cargo, adding dependencies will be much easier to do.

### Creating a project with cargo

`$ cargo new hello_cargo`
`$ cd hello_cargo`

Cargo has generated two files and one directory for us: a `Cargo.toml` file and a `src` directory with a main.rs file inside.

**Cargo.toml**

The first line, `[package]`, is a section heading that indicates that the following statements are configuring a package. 
The last line, `[dependencies]`, is the start of a section for you to list any of your project’s dependencies. In Rust, packages of code are referred to as `crates`. 

Cargo expects your source files to live inside the src directory. The top-level project directory is just for README files, license information, configuration files, and anything else not related to your code. Using Cargo helps you organize your projects. There’s a place for everything, and everything is in its place.

If you started a project that doesn’t use Cargo, as we did with the “Hello, world!” project, you can convert it to a project that does use Cargo. Move the project code into the src directory and create an appropriate Cargo.toml file. One easy way to get that Cargo.toml file is to run `cargo init`, which will create it for you automatically.

**Building and Running a Cargo Project**

`cargo build` : This command creates an executable file in `target/debug/hello_cargo`

* Running cargo build for the first time also causes Cargo to create a new file at the top level: `Cargo.lock`. This file keeps track of the exact versions of dependencies in your project. This project doesn’t have dependencies, so the file is a bit sparse. 

* We can also use `cargo run` to compile the code and then run the resultant executable all in one command 

* Cargo also provides a command called `cargo check`. This command quickly checks your code to make sure it compiles but doesn’t produce an `executable`:

**Building for Release**

When your project is finally ready for release, you can use `cargo build --release` to compile it with optimizations.

