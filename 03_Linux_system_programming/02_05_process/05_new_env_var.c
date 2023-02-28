/*
This file create a new environment variable and set a value to the same.
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    char new_var[10];
    printf("Enter new value to environment value: ");
    // scanf("%s", new_var);
    gets(new_var);
    // getchar();
    setenv("Sachin_new", new_var, 1);

    printf("Value of the new env var is: %s\n", getenv("Sachin_new"));
    return 0;
}