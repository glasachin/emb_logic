#include <iostream>
#include <vector>


void print_smallerNumber(std::vector<int> c)
{
    // This function prints number which are less than their adjacent numbers
    for(int i = 1; i < c.size()-1; i++)
    {
        if((c[i] < c[i+1]) & (c[i] < c[i-1]))
        {
            std::cout << c[i] << ' ';
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> a(3);
    std::cout << "Enter 5 numbers: " << std::endl;
    int b;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> b;
        a.push_back(b);
    }

    // print entered elements in vector
    std::vector<int>::iterator it;
    for (it = a.begin(); it < a.end(); it++)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    print_smallerNumber(a);

    return 0;
}