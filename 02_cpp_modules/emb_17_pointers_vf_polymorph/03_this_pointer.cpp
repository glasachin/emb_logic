#include<iostream>
#include<cstring>
using namespace std;

class person
{
    private:
        char name[20];
        float age;
    public:
        person(char *s, float a)
        {
            strcpy(name, s);
            age = a;
        }
        person & person :: greater(person & x)
        {
            if(x.age >= age)
            {
                return x;
            }
            else
                return *this;
        }

        void display(void)
        {
            cout << "Name: " << name << "\n"
                << "Age: " << age << "\n";
        }
};

int main()
{
    person p1("sachin ", 37), p2("Nidhi", 32);

    person P = p2.greater(p1);
    cout << "Elder person is: \n";
    P.display();

    return 0;
}