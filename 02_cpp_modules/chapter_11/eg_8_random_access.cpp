#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class INVENTORY
{
    char name[10];
    int code;
    float cost;
    public:
        void getdata(void)
        {
            cout << "Enter name: "; cin >> name;
            cout << "Enter code: "; cin >> code;
            cout << "Enter cost: "; cin >> cost;
        }
        void putdata(void)
        {
            cout << setiosflags(ios::left)
                << setw(10) << name   
                << setiosflags(ios::right)
                << setw(10) << code
                << setprecision(2)
                << setw(10) << cost
                << endl;
        }
};

int main()
{
    INVENTORY item;
    fstream inoutfile;
    inoutfile.open("STOCK.DAT", ios::ate | ios::in | ios::out | ios::binary);
    inoutfile.seekg(0,ios::beg); //go to start

    cout << "CURRENT CONTENTS OF STOCK" << "\n";

    while(inoutfile.read((char*)&item, sizeof item))
    {
        item.putdata();
    }
    inoutfile.clear();

    cout << "\nADD and ITEM\n";
    item.getdata();
    char ch;
    cin.get(ch);
    inoutfile.write((char*)&item, sizeof item);
    //Display the appended file
    inoutfile.seekg(0);
    cout << "CONTENTS OF APPENDED FILE\n";
    while(inoutfile.read((char*) &item, sizeof(item)))
    {
        item.putdata();
    }
    //Find number of objects in the file
    int last = inoutfile.tellg();
    int n = last/sizeof(item);
    cout << "Number of objects = " << n << "\n";
    cout << "Total bytes in the file = " << last << "\n";

    //------modifying the details of an item----------
    cout << "Enter object number to be updated \n";
    int object;
    cin >> object;
    cin.get(ch);
    int location = (object -1) * sizeof(item);
    if(inoutfile.eof())
    inoutfile.clear();
    inoutfile.seekp(location);
    cout << "Enter new values of the object \n";
    item.getdata();
    cin.get(ch);
    inoutfile.write((char*)&item, sizeof(item)) << flush;

    //--------shhow updated file---------------
    inoutfile.seekg(0); //go to start
    cout << "Contents of updated file is \n";
    while(inoutfile.read((char*)&item, sizeof item))
    {
        item.putdata();
    }
    inoutfile.close();
    return 0;
}