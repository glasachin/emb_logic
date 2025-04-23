# GDB

1. `gcc -g factorial.c` => compile file with debugging option

2. `gdb a.out` => launch gdb

3. `break line_number` => sets up a break point inside C program
    * `break [file_name]:line_number`
    * `break [file_name]:func_name`

4. `run` => start running the program

5. `print [variable_name]` => Printing variable values inside gdb debugger
    * print i or p i
    * print j

6. `continue, stepping over and in`
    * c or continue => continue executing untill the next break point
    * n or next => will execute the next line as single instruction
    * s or step => same as next but does not treats function as a single instruction, instead goes into the function and execute it line by line.

7. `bt` => backtrack

8. `quit` => Exit from the debugger




