#include<iostream>
using namespace std;

class test
{
    public:
        static int objCounter;
        test()
        {
            objCounter++;
        }
        ~test()
        {
            objCounter--;
        }
};

int test::objCounter;

int main()
{
    test obj1, obj2, obj3, *ptr;
    cout << "Number of ojbects: " << test::objCounter << endl;

    ptr = new test;
    cout << "Number of ojbects: " << test::objCounter << endl;

    delete ptr;
    cout << "Number of ojbects: " << test::objCounter << endl;
    return 0;
}