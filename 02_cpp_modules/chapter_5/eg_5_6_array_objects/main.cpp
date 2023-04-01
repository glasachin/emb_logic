#include"includes.h"
#include"declarations.h"

void employee::getdata(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void employee::putdata(void)
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

const int size1=3;

int main()
{
    int i;
    employee manager[size1];
    for(i = 0; i < size1; i++)
    {
        cout << "Details of Manager" << i + 1 << endl;
        manager[i].getdata();
    }

    for( i = 0; i < size1; i++)
    {
        cout << "Manager: " << i+1 << endl;
        manager[i].putdata();
    }

    return 0;
}