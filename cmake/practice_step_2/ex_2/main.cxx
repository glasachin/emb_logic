#include<iostream>
#include<cmath>
#ifdef USE_MYMATH
    #include "functions.h"
#endif


using namespace std;
int main()
{
    float num,res;
    cout<<"Enter any number: \n"<<endl;
    cin>>num;
    // res = find_root(num);
    #ifdef USE_MYMATH
        cout<<"*********using our own library*************"<<endl;
        res = mysqrt(num);
    #else
        cout<<"*********using cmath library*************"<<endl;
        res = sqrt(num);
    #endif
    cout<<"Square root of "<<num<<" is "<<res<<endl;
    return 0;
}