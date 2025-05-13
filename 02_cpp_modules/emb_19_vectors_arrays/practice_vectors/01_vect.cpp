#include <vector>
#include <iostream>

using namespace std;

enum class colors
{
hello,
hi,
};

int main()
{
    int a;
    colors abc = colors::hi;
    cout << "enum value: " << int(abc) << endl;
    
    cout << "hello" << endl;
    cout << "enter any number: ";
    cin >> a;
    cout << a << endl;

    vector<int> b;
    b.push_back(10);
    b.push_back(30);
    cout << "vector size: " << b.size() << "; value: " << b[0] << endl;
    cout << "vector capacity: " << b.capacity() << endl;

    return 0;
}
