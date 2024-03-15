#include<iostream>

using namespace std;

const int size1 = 3;

template <class T>
class vector
{
    T* v;   //type T vector
    public:
        vector()
        {
            cout << "hello";
            v = new T[size1];
            for(int i = 0; i < size1; i++)
                v[i] = 0;
        }

        vector(T* a)
        {
            for(int i = 0; i < size1; i++)
                v[i] = a[i];
        }

        T operator* (vector &y)
        {
            T sum = 0;
            for(int i = 0; i < size1; i++)
                sum += this -> v[i] * y.v[i];
            return sum;
        }
};


int main()
{
    cout << "1\n";
    int x[3] = {1,2,3};
    cout << "2\n";
    int y[3] = {4,5,6};
    cout << "3\n";
    vector <int> v1;
    cout << "4\n";
    vector <int> v2;
    cout << "5\n";
    v1 = x;
    cout << "6\n";
    v2 = y;
    cout << "7\n";
    v1 = x;
    v2 = y;
    int R = v1 * v2;
    cout << "R = " << R << endl;
    return 0;
}