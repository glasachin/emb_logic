#include <iostream>

void swapVariables(int & c, int & d)
{
    int temp;
    temp = d;
    d = c;
    c = temp;
}


int main()
{
    int a , b;
    a = 10;
    b = 20;
    swapVariables( a,  b);
    std::cout << "Values after swapping: " << "a: " << a << ", b: " << b << std::endl;
    return 0;
}
