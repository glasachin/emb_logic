/*
This file converts the lower case string to uppercase.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void lower_to_upper(char *str)
{
    int i = 0;
    for(i = 0; *str != '\0'; i++)
    {
        *str = toupper(*str);
        str += 1;
    } 
}

int main()
{
    char str[20] = "";
    printf("-------Start Running File: %s--------\n", __FILE__);
    printf("Enter the string: ");
    // scanf("%s",str);
    gets(str);
    printf("Entered string is: %s\n", str);
    lower_to_upper(str);
    printf("String in UPPER CASE is \n%s\n", str);
    printf("-------Stopped Running File: %s--------\n", __FILE__);
    return 0;
}