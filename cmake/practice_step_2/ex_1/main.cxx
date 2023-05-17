#include<iostream>
#include "functions.h"
using namespace std;
int main()
{
    float num,res;
    cout<<"Enter any number: \n"<<endl;
    cin>>num;
    res = find_root(num);
    cout<<"Square root of "<<num<<" is "<<res<<endl;
    return 0;
}