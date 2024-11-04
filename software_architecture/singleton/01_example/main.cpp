#include <iostream>
#include "demo.h"

using namespace std;

int main()
{
    // Access the singleton instance
    demoSingleton* s1 = demoSingleton::getInstance();
    s1->doSomething();

    // Get another reference to the singleton instance
    demoSingleton* s2 = demoSingleton::getInstance();
    s2->doSomething();

    // Both s1 and s2 point to the same instance
    if (s1 == s2)
    {
        std::cout << "Both s1 and s2 are the same instance.\n";
    }

    cout << "s1 Output: ";
    s1->print();
    cout << endl;
    cout << "s2 Output: " ;
    s2->print();



    return 0;
}
