#ifndef DEMO_H
#define DEMO_H

#include <iostream>

using namespace std;

class demoSingleton
{
    private:
        // Member variables
        std::string name, loves;

        demoSingleton();

        // Deleting the copy constructor to prevent copies
        // Disable copy constructor and assignment operator
        demoSingleton(const demoSingleton&) = delete;
        demoSingleton& operator=(const demoSingleton&) = delete;

        // Static instance pointer
        static demoSingleton* instance;

    public:

        virtual ~demoSingleton();

        // Static method to access the singleton instance
        static demoSingleton* getInstance()
        {
            if (instance == nullptr)
            {
                instance = new demoSingleton();
            }
            return instance;
        }

        // Method to demonstrate singleton functionality
        void doSomething() {
            std::cout << "Singleton doing something...\n";
        }

        // Method to set values
        void setValues(const string& name, const string& loves) {
            this->name = name;
            this->loves = loves;
        }

        // Method to print values
        void print() const {
            cout << name << " Loves " << loves << "." << endl;
        }

};

#endif // DEMO_H
