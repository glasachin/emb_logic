#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> myVect(10);

    /*create iterator*/
    vector <int>:: iterator it_begin = myVect.begin();
    vector <int>:: iterator it_end = myVect.end();

    /*Creating reverse iterators*/
    vector <int>:: reverse_iterator it_rbegin = myVect.rbegin();
    vector <int>:: reverse_iterator it_rend = myVect.rend();

    /* fill vector*/
    for(int i = 0; i < 10; i++)
    {
        myVect[i] = i+1;
    }

    /* Print Vector */
    for(vector<int>::iterator it = it_begin; it < it_end; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /*print vector in reverse Order*/
    for(vector<int>::reverse_iterator it = it_rbegin; it < it_rend; it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}