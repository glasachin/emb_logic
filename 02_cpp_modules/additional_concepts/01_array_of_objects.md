# Array of objects

* The main disadvantage with arrays of objects is that the constructor runs for each object. If the default constructor doesn’t do the right thing for multiple objects in the array, we have to specify the constructor arguments for each element at the time the array is declared, which we wouldn’t have to do if we allocated an array of object pointers, and allocated objects as needed.
* constructor runs for each object automatically.

* `Important`: no matching function for call to 'MyClass::MyClass()' typically occurs when you try to create an array of objects (either statically or dynamically) for a class that does not have a default (parameterless) constructor. In C++, when you create an array of objects, each element is initialized using the default constructor. If your class does not have a default constructor, the compiler will not know how to create each object in the array without the required parameters, resulting in this error.

item t[size];

## normal operation

```
#include<iostream>

using namespace std;

class MyClass {

private:

int data;

public:

void initialize(int i){

data = i;

}

void method(int i){

cout<<"object "<<i+1<<endl;}

};

int main(){

MyClass array_of_objects[5];

for(int i=0; i<5; i++){

array_of_objects[i].initialize(i+1);

}

for(int i=0; i<5; i++){

array_of_objects[i].method(i);}

}
```

**In a single Line**

`MyClass array_of_objects[5] = {1, 2, 3, 4, 5};`


## Dynamic Allocation (new keyword)

In this, we have to call default constructor separately for each object.

```
#include<iostream>

using namespace std;

class MyClass{

public:

void method(int i){

cout<<"object "<<i+1<<endl;}

};

int main(){

MyClass *array_of_objects= new MyClass[5]; // Creating an array of MyClass objects using 'new'

for(int i=0; i<5; i++){

array_of_objects[i].method(i);}

delete[] array_of_objects;

}
```

If there is a constructor defined in the class then `default constructor` is must to create an array of objects.

```
class MyClass {
public:
    int value;

    // Default constructor
    MyClass() : value(0) {}

    // Parameterized constructor
    MyClass(int v) : value(v) {}

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};


int main() {
    int size = 3;
    MyClass* myArray = new MyClass[size];  // Still requires a default constructor

    // Initialize each element with the parameterized constructor
    for (int i = 0; i < size; i++) {
        myArray[i] = MyClass(i + 1);  // Calls the parameterized constructor
    }

    for (int i = 0; i < size; i++) {
        myArray[i].display();
    }

    delete[] myArray;  // Clean up memory
    return 0;
}
```


## Using Vectors 

```
#include<iostream>

#include<vector>

using namespace std;

class MyClass{

public:

MyClass(int value){}

void method(int i){

cout<<"object "<<i+1<<endl;}

};

int main(){

vector<MyClass>array_of_objects{};

for(int i=0; i<5; i++){

array_of_objects.push_back(i+1);

array_of_objects[i].method(i);}

}
```

