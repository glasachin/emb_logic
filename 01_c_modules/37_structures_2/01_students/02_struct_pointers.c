// This program write the previous program using pointers
// 
#include<stdio.h>
#include<stdlib.h>
#define LEN(s) (s)
typedef struct
{
    /* data */
    char *name;
    int roll;
    float marks;
} student; 

student** get_st(int len)
{
    student **st;
    st = (student**)malloc(sizeof(student*)*len);
    return st;
}

void get_info(student **st, int len)
{
    int i;
    for(i = 0; i < LEN(len); i++)
    {
        *(st+i) = (student*)malloc(sizeof(student)); //allocating memory for student structure
        (*(st+i))->name = (char*)malloc(sizeof(char)*20);//allocate memory for name in structure
    }

    for(i = 0; i < LEN(len); i++)
    {
        printf("enter the name of student: \n");
        scanf("%s",(*(st+i))->name);
        printf("enter the roll no of student: \n");
        scanf("%d",&(*(st+i))->roll);
        printf("enter the marks of student: \n");
        scanf("%f",&(*(st+i))->marks);
    }
    
}

void show_info(student **st, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("Student: %s, Roll No.: %d, Marks: %0.2f\n",(*(st+i))->name, (*(st+i))->roll, (*(st+i))->marks);
    }
}

int main()
{
    int num_st;
    student **st_array;
    printf("Enter number of students you want to store: \n");
    scanf("%d",&num_st);
    st_array = get_st(LEN(num_st)); //get array of structure pointers
    get_info(st_array, LEN(num_st));
    printf("Entered values are: \n");
    show_info(st_array, LEN(num_st));
    return 0;
}