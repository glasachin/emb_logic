#include<iostream>

using namespace std;

class point
{
    int x, y;
    public:
        // constructor
        point(int a, int b)
        {
            x = a;
            y = b;
        }

        void display()
        {
            cout<<"x = " << x <<", y = "<< y << endl;
        }
};

int main()
{
    point p(10,50);
    p.display();
    return 0;
}