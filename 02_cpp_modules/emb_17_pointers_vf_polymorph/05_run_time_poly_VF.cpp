#include <iostream>
#include <cstring>

using namespace std;

class media
{
    protected:
        char title[50];
        float price;
    public:
        media(char *s, float a)
        {
            strcpy(title, s);
            price = a;
        }
        virtual void display(){}
};