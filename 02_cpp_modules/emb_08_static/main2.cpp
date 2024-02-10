#include<iostream>
using namespace std;

class test1
{
    static int testvar;
    int testvar1;
    public:
        static void testfunc()
        {
            cout << "Value of static variable: " << testvar << endl;

            cout << "value of nonstatic variable: " << testvar1 << endl;
        }
};

int test1::testvar;

int main()
{
    test1::testfunc();
    return 0;
}