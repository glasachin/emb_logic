#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> myVect;

    /*fill vector with numbers*/
    for (int i = 0; i < 10; i++)
    {
        myVect.push_back(i + 1);
    }

    /*print vector*/
    for(vector<int>::iterator it = myVect.begin(); it < myVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*remove numbers above 5th index*/
    myVect.erase(myVect.begin()+5, myVect.end());
    for(vector<int>::iterator it = myVect.begin(); it < myVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*Insert number after 6th index*/
    for(int i = 5; i < 10; i++)
    {
        myVect.insert(myVect.begin()+i, i+1);
    }
    for(vector<int>::iterator it = myVect.begin(); it < myVect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*delete all elements*/
    myVect.clear();

    return 0;
}