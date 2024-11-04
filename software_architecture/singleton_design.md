# Singleton Design Pattern in OOPS

https://www.enjoyalgorithms.com/blog/singleton-design-pattern

https://refactoring.guru/design-patterns/singleton


A singleton object is a design pattern in object-oriented programming where a class is designed to ensure that only one instance of the class can be created throughout the lifetime of the program. The singleton pattern is used when exactly one instance of a class is needed to coordinate actions across a system.

Key Characteristics of a Singleton:
Single Instance: Only one object (instance) of the class exists.
Global Access: The single instance is globally accessible within the application.
Lazy Initialization (optional): The instance is created only when it is needed for the first time.
How the Singleton Pattern Works in C++:
To implement a singleton in C++, the following steps are typically followed:

Private Constructor: The constructor is made private or protected to prevent direct creation of objects.
Static Method for Access: A static method (usually named getInstance()) is provided to return the single instance of the class.
Static Instance: The class holds a static pointer or reference to the single instance.
Example of a Singleton in C++:
cpp
Copy code
#include <iostream>

class Singleton {
private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton instance created.\n";
    }

    // Disable copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Static instance pointer
    static Singleton* instance;

public:
    // Static method to access the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Method to demonstrate singleton functionality
    void doSomething() {
        std::cout << "Singleton doing something...\n";
    }
};

// Initialize the static member
Singleton* Singleton::instance = nullptr;

int main() {
    // Access the singleton instance
    Singleton* s1 = Singleton::getInstance();
    s1->doSomething();

    // Get another reference to the singleton instance
    Singleton* s2 = Singleton::getInstance();
    s2->doSomething();

    // Both s1 and s2 point to the same instance
    if (s1 == s2) {
        std::cout << "Both s1 and s2 are the same instance.\n";
    }

    return 0;
}
Output:
sql
Copy code
Singleton instance created.
Singleton doing something...
Singleton doing something...
Both s1 and s2 are the same instance.
Explanation:
Singleton Constructor: The constructor of Singleton is private to prevent creating objects directly.
Static Instance: The class has a static pointer (instance) that holds the single instance of the class.
getInstance() Method: This method checks if an instance of the class already exists. If not, it creates one. Otherwise, it returns the existing instance.
s1 and s2: Even though we call getInstance() twice, both s1 and s2 refer to the same instance.
Why Use the Singleton Pattern?
Resource Management: When a single resource (like a file, a logger, or a database connection) is needed across different parts of the application.
Global Access: If you need to ensure that a particular service or resource is globally accessible but still controlled.
Control Over Initialization: Lazy initialization ensures that the object is only created when it's first needed, saving resources in some scenarios.
Common Use Cases:
Logging: Only one logger instance is needed to handle all logging operations.
Configuration Management: A configuration class that holds settings and needs to be globally accessible throughout the application.
Database Connection: Ensure that only one database connection is established and used across the system.
Considerations:
Thread Safety: In multithreaded environments, extra care is needed to ensure that the singleton instance is created safely (e.g., using a mutex or double-checked locking).
Testing: Singleton can make unit testing more difficult, as it introduces global state, which can lead to side effects between tests.
Global State: While singletons provide global access, excessive use can lead to tight coupling between components, making the system harder to maintain.