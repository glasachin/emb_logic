#include<iostream>

using namespace std;

class space
{
    int x;
    int y;
    int z;
    public:
        void getdata(int a, int b, int c);
        void display(void);
        void operator - (); // overload uniary minus
};

void space::getdata(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

void space::display(void)
{
    cout<<"x = " << x << " ";
    cout<<"y = " << y << " ";
    cout<<"z = " << z << endl;
}

void space::operator - ()
{
    x = -x;
    y = -y;
    z = -z;
}

int main()
{
    space s;
    s.getdata(10,-20,30);
    cout<<"S: ";
    s.display();
    -s;
    cout <<"-S: ";
    s.display();
    return 0;
}