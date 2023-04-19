#include<iostream>
using namespace std;

const int sz = 3;
class vector
{
        int v[sz];
    public:
        vector(); 
        vector(int *x);
        friend vector operator *(int a, vector b);
        friend vector operator *(vector b, int a);
        friend istream & operator >> (istream &, vector &);
        friend ostream & operator << (ostream &, vector &);
};

vector::vector()
{
    for(int i = 0; i < sz; i++)
    {
        v[i] = 0;
    }
}

vector :: vector(int *x)
{
    for(int i = 0; i < sz; i++)
    {
        v[i] = x[i];
    }
}

vector operator * (int a, vector b)
{
    vector c;
    for(int i = 0; i < sz; i++)
    {
        c.v[i] = a * b.v[i];
    }
    return c;
}

vector operator *(vector b, int a)
{
    vector c;
    for(int i = 0; i < sz; i++)
        c.v[i] = b.v[i] * a;
    return c;
}

istream & operator >> (istream &din, vector &b)
{
    for(int i = 0; i < sz; i++)
    {
        din >> b.v[i];
    }
    return(din);
}

ostream & operator << (ostream &dout, vector &b)
{
    dout << "(" << b.v[0];
    for(int i = 1; i < sz; i++)
        dout << ", " << b.v[i];
    dout << ")";
    return(dout);
}

int x[sz] = {2,4,6};

int main()
{
    vector m; // invoke constructor 1
    vector n = x; // invoke constructor 2
    cout << "Enter elements of vector m " << "\n";
    cin >> m;   //invoke operator >>() function
    cout << "\n";
    cout << "m = " << m << "\n"; // invoke operator <<()

    vector p, q;
    p = 2*m;
    q = n*2;

    cout << "\n";   
    cout << "p = " << p << "\n"; // invoke operator <<()
    cout << "q = " << q << "\n";
    return 0;
}