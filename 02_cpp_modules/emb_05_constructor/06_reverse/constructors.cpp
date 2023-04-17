#include"includes.h"
#include"classes.h"

reverse::reverse(char *data)
{
    int i = 0;
    for(i = 0; *(data+i)!='\0'; i++)
    {
        a[i] = *(data+i);
    }
}

reverse::~reverse()
{
    cout << "destructor is called";
}

