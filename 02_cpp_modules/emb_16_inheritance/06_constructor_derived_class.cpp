#include<iostream>
using namespace std;

class alpha
{
    private:
        int x;
    public:
        alpha(int i)
        {
            x = i;
            cout << "alpha initializesd \n";
        }
        void show_x(void)
        {
            cout << "x = " << x << endl;
        }
};

