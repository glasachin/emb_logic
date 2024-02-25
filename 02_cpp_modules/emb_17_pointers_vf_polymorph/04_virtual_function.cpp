#include <iostream>

using namespace std;

class Base
{
    public:
        void display()
        {
            cout << "Display base" << endl;
        }

        virtual void show()
        {
            cout << "Show base" << endl;
        }
};

class Derived: public Base
{
    public:
        void display()
        {
            cout << "Display Derived" << endl;
        }

        void show()
        {
            cout << "Show Derived" << endl;
        }
};

int main()
{
    Base B;
    Derived D;
    Base *bptr;
    Derived *dptr;

    cout << "bptr points to Base" << endl;
    bptr = &B;
    bptr->display();
    bptr->show();

    cout << "Bptr points to Derived" << endl;
    bptr = &D;
    bptr->display();
    bptr->show();
}