#include<iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter the value of a: ";
    cin >> a;
    int b;
    cout << "Enter the value of b: ";
    cin >> b;

    if(a > b)
    {
        cout<<"a is larger\n";
    }
    else
    {
        cout << "b is larger\n";
    }

    return 0;
}