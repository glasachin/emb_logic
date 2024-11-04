#include "demo.h"

using namespace std;

demoSingleton::demoSingleton()
{
    //ctor
    cout << "Singleton instance created.\n";
    name = "Sachin";
    loves = "Alka";
}

demoSingleton::~demoSingleton()
{
    //dtor
}



// Initialize the static member
demoSingleton* demoSingleton::instance = nullptr;
