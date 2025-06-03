# array of constructor

## array of class A into class B

**C++ program for creating array of objects of another class in different class**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Class whose objects will be in the array
class Student {
private:
    string name;
    int age;

public:
    Student() : name("Unknown"), age(0) {}  // Default constructor

    void setDetails(const string& n, int a) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Class that contains an array of Student objects
class School {
private:
    Student students[3];  // Array of Student objects

public:
    void inputStudents() {
        string name;
        int age;

        for (int i = 0; i < 3; ++i) {
            cout << "Enter name and age of student " << (i + 1) << ": ";
            cin >> name >> age;
            students[i].setDetails(name, age);
        }
    }

    void displayStudents() const {
        cout << "\nList of Students:\n";
        for (int i = 0; i < 3; ++i) {
            students[i].display();
        }
    }
};

// Main function
int main() {
    School mySchool;
    mySchool.inputStudents();
    mySchool.displayStudents();

    return 0;
}

```

**C++ program for creating array of objects of another class in different class having constructor**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Student class
class Student {
private:
    string name;
    int age;

public:
    // Parameterized constructor
    Student(string n = "Unknown", int a = 0) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// School class containing an array of Student objects
class School {
private:
    Student students[3];  // Array of Student objects

public:
    // Constructor of School that initializes the Student objects
    School() {
        students[0] = Student("Alice", 20);
        students[1] = Student("Bob", 21);
        students[2] = Student("Charlie", 22);
    }

    void displayStudents() const {
        cout << "Student List:\n";
        for (int i = 0; i < 3; ++i) {
            students[i].display();
        }
    }
};

// Main function
int main() {
    School mySchool;
    mySchool.displayStudents();

    return 0;
}

```

**Good Example**

1. class A has a parametrized constructor only
2. class B has array of Class A objects as its member variable
3. Class B has only default constructor.**

```cpp
#include <iostream>
using namespace std;

// Class A with only a parameterized constructor
class A {
private:
    int value;

public:
    A(int v) : value(v) {
        cout << "A(" << value << ") constructed.\n";
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

// Class B with an array of A objects and only a default constructor
class B {
private:
    A arr[3];  // Array of 3 A objects

public:
    // Default constructor using initializer list to initialize A objects
    B() : arr{ A(10), A(20), A(30) } {
        cout << "Class B constructed.\n";
    }

    void show() const {
        cout << "Displaying array of A in B:\n";
        for (int i = 0; i < 3; ++i) {
            arr[i].display();
        }
    }
};

// Main function
int main() {
    B obj;
    obj.show();

    return 0;
}

```

