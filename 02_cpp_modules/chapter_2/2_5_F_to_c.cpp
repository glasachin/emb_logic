#include<iostream>
using namespace std;

int main()
{
    int t_c, t_f;
    cout << "Enter the temperature in Farenheit: ";
    cin >> t_f;

    t_c = (t_f - 32)*5/9;
    cout << "Temperatue in celcius is: " << t_c << "\n";
    return 0;
}