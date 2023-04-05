#include<iostream>
using namespace std;

int count = 0;

class test
{
    public:
        test()
        {
            count++;
            cout << "Constructor message: object number " << count<<" created."<<endl;
        }

        ~test()
        {
            cout<<"Destructor message: Object number " << count <<" destroyed.." << endl;
            count--;
        }
};

int main()
{
    cout << "Inside the main..." << endl;
    cout << " Creating first object T1.. "<<endl;
    test T1;
    {
        cout << "Inside Block 1.."<< endl;
        cout << "Creating more objects T2 and T3.."<< endl;
        test T2, T3;
        cout << "leaving block 1.." << endl;
    }
    cout << " Back in the main..." << endl;
    return 0;
}