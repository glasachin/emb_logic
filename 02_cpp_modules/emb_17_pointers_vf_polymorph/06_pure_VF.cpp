#include <iostream>
using namespace std;

class Base
{
    public:
        virtual void show() = 0;
};

class Derv1:public Base
{
    public:
        void show()
        {
            cout << "Derived Class 1" << endl;
        }
};

class Derv2:public Base
{
    public:
        void show()
        {
            cout << "Derived Class 2\n";
        }
};

int main()
{
    Base* arr[2];
    Derv1 dv1;
    Derv2 dv2;
    arr[0] = &dv1;
    arr[1] = &dv2;
    arr[0]->show();
    arr[1]->show();
    return 0;
}