#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Enter values of a and b " << endl;
    cin >> a;
    cin >> b;
    int x = a - b;
    try
    {
        if (x != 0)
        {
            cout << "Result (a/x) = " << a/x << endl;
        }
        else
        {
            throw(x);
        }
    }
    catch(int i)
    {
        cout << "Exception caught: x = " << x << "\n";
    }

    return 0;
}