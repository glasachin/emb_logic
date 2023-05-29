#include<iostream>
#include<fstream>
#include<sys/stat.h>
using namespace std;

bool FileExists(const string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int main()
{
    string filename = "eg_2.txt";
    cout << "Does file exists ? " << FileExists(filename) << endl;
    return 0;
}