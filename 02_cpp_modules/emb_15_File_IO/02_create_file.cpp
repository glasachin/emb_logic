#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("eg_2.txt");
    file << "hello, Hi this is sachin\n";
    file.close();
    return 0;

}