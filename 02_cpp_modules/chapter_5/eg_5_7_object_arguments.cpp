/*
    This file passes the class object as an argument to the function
*/

#include<iostream>
using namespace std;
class time1
{
    int hours;
    int minutes;
    public:
        void gettime(int h, int m)
        {
            hours = h;
            minutes = m;
        }

        void puttime(void)
        {
            cout << hours << " hours and ";
            cout << minutes << " minutes " << endl;
        }

        void sum(time1, time1);
};

void time1::sum(time1 t1, time1 t2)
{
    minutes = t1.minutes + t2.minutes;
    hours = minutes/60;
    minutes = minutes%60;
    hours = hours + t1.hours+t2.hours;
}

int main()
{
    time1 T1, T2, T3; 

    T1.gettime(2,46);
    T2.gettime(3,40);

    T3.sum(T1, T2);

    cout << "T1 = " ; T1.puttime() ;
    cout << "T2 = " ; T2.puttime() ;
    cout << "T3 = " ; T3.puttime() ;
    return 0;
}