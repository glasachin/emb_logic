#include<iostream>

using namespace std;

class Fixed_deposit
{
    long int p_amount;
    int years;
    float rate;
    float r_value;
    public:
        Fixed_deposit(){};
        Fixed_deposit(long int p, int y, float r = 0.12);
        Fixed_deposit(long int p, int y, int r);
        void display(void);
};

Fixed_deposit :: Fixed_deposit(long int p, int y, float r)
{
    p_amount = p;
    years = y;
    rate = r;
    r_value = p_amount;
    for(int i = 1; i <= y; i++)
        r_value = r_value *(1.0+r);
}

Fixed_deposit :: Fixed_deposit(long int p, int y, int r)
{
    p_amount = p;
    years = y;
    rate = r;
    r_value = p_amount;
    for(int i = 1; i <= y; i++)
        r_value = r_value*(1.0+float(r)/100);
}

void Fixed_deposit::display(void)
{
    cout << "Principle Amount = " << p_amount << endl;
    cout << "Return Value = " << r_value << endl;
}

int main()
{
    Fixed_deposit FD1, FD2, FD3;
    long int p;
    int y;
    float r;
    int R;
    
    cout << "Enter amount, period, interest rate (in percent)" << endl;
    cin >> p >> y >> R;
    FD1 = Fixed_deposit(p,y,R);

    cout << "Enter amount, period, interest rate (in decimal)" << endl;
    cin >> p >> y >> r;
    FD2 = Fixed_deposit(p,y,r);
    
    cout << "Enter amount, period" << endl;
    cin >> p >> y;
    FD3 = Fixed_deposit(p,y);
    
    cout << "Deposit 1: ";
    FD1.display();
     
    cout << "Deposit 2: ";
    FD2.display();

    cout << "Deposit 3: ";
    FD3.display();

    return 0;
}
