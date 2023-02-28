/*
This file run the other lower to upper file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("----Start Running %s\n", __FILE__);
    system("./lower_to_upper");
    printf("----End Running %s------\n",__FILE__);
}