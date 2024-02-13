#include<iostream>
#include<cstring>

using namespace std;

class city
{
    protected:
        char *name;
        int len;
    public:
        city()
        {
            len = 0;
            name = new char[len+1];
        }

        void getname(void)
        {
            char *s;
            s = new char[30];
            cout << "Enter city Name: ";
            cin >> s;
            len = strlen(s);
            name = new char[len + 1];
            strcpy(name,s);
        }

        void printname(void)
        {
            cout << name << endl;
        }
};

int main()
{
    city *cptr[10];
    int n = 0;
    int option;

    do
    {
        cptr[n] = new city;
        cptr[n]->getname();
        n++;
        cout << "Do you want to enter one more name?\n";
        cout << "(Enter 1 for yes 0 for no): ";
        cin >> option;
    } while (option);
    
    cout << "\n\n";

    for(int i = 0; i < n; i++)
    {
        cptr[i]->printname();
    }
    return 0;
}
