#include<iostream>

using namespace std;

int main()
{
    int count = 0;
    char c;

    cout << "Input Text" << endl;
    cin.get(c);
    while(c!='\n')
    {
        cout.put(c);
        count++;
        cin.get(c);
    }
    cout << "\nNumber of Characters = " << count << endl;
    return 0;
}