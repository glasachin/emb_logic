#include<iostream>

using namespace std;

template <class T1, class T2>
void display(T1 x, T2 y)
{
    cout << x << ", " << y << "\n";
}

int main()
{
    display(200, "Sachin");
    display(12.34, 1200);
    return 0;
}
