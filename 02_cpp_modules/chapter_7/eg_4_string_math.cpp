#include<iostream>
#include<string>
using namespace std;

class String
{
        char *p;
        int len;
    public:
        String(){len = 0, p = 0;}
        String(const char *s);
        String(const String & s);
        ~String(){delete p;}

        // + operator
        friend String operator +(const String &s, const String &t);

        // <= operator
        friend int operator <= (const String &s, const String &t);
        friend void show(const String s);
};

String :: String(const char *s)
{
    len = strlen(s);
    p = new char[len+1];
    strcpy(p,s);
}