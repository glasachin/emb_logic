// This file do the example using structure variables
#include<stdio.h>

typedef struct
{
    /* data */
    char name[50];
    int roll;
    float marks;
}student;

int main()
{
    int i, n_s;
    student s[3];
    // printf("Enter number of students you wanted to save: \n");
    // scanf("%d",&n_s);
    for(i = 0; i < 3; i++)
    {
        printf("Enter %d stdent name: \n",i);
        scanf("%s",&s[i].name);
        // getchar();
        printf("Enter %d student roll no.: \n",i);
        scanf("%d",&s[i].roll);
        printf("Enter %d student marks:\n",i);
        scanf("%f",&s[i].marks);
    }

    printf("Entered Students Data is as follows: \n");
    for(i = 0; i < 3; i++)
    {
        printf("Stendt: %s, Roll No.: %d, Marks: %f\n",s[i].name,s[i].roll,s[i].marks);
    }
    return(0);

}
