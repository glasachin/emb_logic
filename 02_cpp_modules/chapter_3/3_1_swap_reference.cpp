#include<iostream>
using namespace std;

void swap(int & a, int & b)
{
    int temp ;
    temp = b;
    b = a;
    a = temp;
}

int main()
{
    int x,y;
    x = 10;
    y = 20;
    cout << "Value of x and y before call is: " << x << " and " << y << " respectively." << endl;
    swap(x,y);
    cout << "value of x and y after call is: " << x << " and " << y << " respectively." << endl;

    return 0;
}