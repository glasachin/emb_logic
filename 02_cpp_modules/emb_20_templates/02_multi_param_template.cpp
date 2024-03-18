#include<iostream>

using namespace std;

template <class T1, class T2>
class Test
{
    T1 a;
    T2 b;
    public:
        Test(T1 x, T2 y)
        {
            a = x;
            b = y;
        }
        void show()
        {
            cout << a << " and " << b << "\n";
        }
};

int main()
{
    Test <float, int> test1(2.314, 35);
    Test<int, char> test2(200, 's');

    test1.show();
    test2.show();
    return 0;
}