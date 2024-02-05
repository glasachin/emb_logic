#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> myVect;
    /*print size and capacity*/
    cout << "vector size: " << myVect.size() << endl;
    cout << "vector capacity: " << myVect.capacity() << endl;

    /*add 5 elements*/
    cout << endl << "Added 5 elements" << endl;
    for(int i = 0; i < 5; i++)
    {
        myVect.push_back(i+1);
    }

    /*print size and capacity*/
    cout << "Vector size after: " << myVect.size() << endl;
    cout << "Vector capacity after: " << myVect.capacity() << endl;

    /*shring to fit*/
    myVect.shrink_to_fit();
    cout << "shrink: Vector size: " << myVect.size() << endl;
    cout << "shrink: Vector Capacity: " << myVect.capacity() << endl;

    /*resize the vector to 3*/
    myVect.resize(3);
    cout << "resize: Vector Size: " << myVect.size() << endl;
    cout << "resize: Vector Capacity: " << myVect.capacity() << endl;

    /*clear all elements*/
    myVect.clear();
    cout << "Is vector empty? ";
    if(myVect.empty())
        cout << "TRUE" << endl;
    else 
        cout << "FALSE" << endl;
    return 0;
}