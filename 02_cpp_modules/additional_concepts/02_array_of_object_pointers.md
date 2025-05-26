# Array of Object Pointers

```c++
// Online C++ compiler to run C++ program online

#include <iostream>
using namespace std;

class MyClass {
public:
    int value;

    MyClass(int v) : value(v) {}  // Constructor with parameter
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    int size = 3;
    MyClass* myArray[size];  // Array of pointers to MyClass objects

    // Allocate memory for each object in the array
    for (int i = 0; i < size; ++i) {
        myArray[i] = new MyClass(i + 1);  // Dynamically allocate with parameter
    }

    // Use the objects through the pointers
    for (int i = 0; i < size; ++i) {
        myArray[i]->display();  // Access members using arrow operator
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < size; ++i) {
        delete myArray[i];  // Free each allocated object
    }

    return 0;
}

```

## Another Approach

`classname **obj = new classname *[size of array];`

`obj[i] = new classname();` ==> constructor calling
or
`*obj = new classname ()`
