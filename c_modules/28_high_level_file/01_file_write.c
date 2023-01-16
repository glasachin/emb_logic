#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int i;
    fp = fopen("01_test.txt","w");
    if(fp == NULL)
    {
        perror("File Opening Error");
        exit(EXIT_FAILURE);
    }
    fprintf(fp,"This is generated using C program\n");
    fputs("Hi, this is Fputs\n",fp);
    for(i = 0; i < 100; i++)
    {
        fprintf(fp,"%d\n",i);
    }
    fclose(fp);
    return 0;
}