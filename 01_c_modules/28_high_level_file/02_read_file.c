#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char val;
    fp = fopen("01_test.txt","r");
    if(fp == NULL)
    {
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        // fread(&val,1,1,fp);
        val = fgetc(fp);
        if(val == EOF)
            break;
        printf("%c",val);
    }
}