#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream outf("ITEM");  // connect ITEM file to outf. It will create a file if not present.

    cout << "Enter Item Name: ";
    char name[30];
    cin >> name;    

    outf << name << endl;

    cout << "Enter Item Cost: ";
    float cost;
    cin >> cost;

    outf << cost << endl;
    
    outf.close();

    ifstream inf("ITEM");   // Connects ITEM file to inf
    
    inf >> name;
    inf >> cost;

    cout << endl;
    cout << "Item name: " << name << endl;
    cout << "Item Cost: " << cost << endl;

    inf.close();
    return 0;
}