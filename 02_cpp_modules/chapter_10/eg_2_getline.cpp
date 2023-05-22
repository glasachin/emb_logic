#include<iostream>
using namespace std;

int main()
{
    int size = 20;
    char city[20];

    cout << "Enter City Name: \n";
    cin >> city;
    cout << "City Name: " << city << endl << endl;

    cout << "Enter City Name again: \n";
    cin.getline(city, size);
    cout << "City Name now: " << city << endl << endl;

    cout << "Enter another city name: \n";
    cin.getline(city, size);
    cout << "New city name: " << city << endl << endl;

    return 0;
}