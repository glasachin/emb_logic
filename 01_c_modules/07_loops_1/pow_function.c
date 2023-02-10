#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    for(i = 0; i<10; i++)
    {
        printf("%d to power 3 is %f, %d\n",i,pow(i,3),(int)pow(i,3));
    }
    return 0;
}