#include<stdio.h>

int main()
{
    FILE *fp;
    fp  = fopen("sachin_test.txt","r");
    int val;
    int i;
    for(i = 0; i < 50; i++)
    {
        fscanf(fp,"%d",&val);
        printf("%d\n",val);
    }
    fclose(fp);
}