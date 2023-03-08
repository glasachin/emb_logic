#include<iostream>
using namespace std;

int main()
{
    int a,b,c,x;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of c: ";
    cin >> c;
    
    x = a/b - c;
    cout << "Final Answer is: " << x <<"\n";
    return 0;
}