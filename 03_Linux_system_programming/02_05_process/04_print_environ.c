#include<stdio.h>
#include<stdlib.h>

int main()
{
    extern char **environ;
    char **env_lst = environ;
    while(*env_lst != NULL)
    {
        printf("Environment variables are %s\n",*env_lst);
        env_lst++;
    }
    
    return 0;
}