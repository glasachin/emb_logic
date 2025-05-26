# Vectors and Arrays
These are collection of elements having the same data type where elements are stored in neighboring allocations in the memory.

Simplest type of arrays or vectors is linear ones. However, 2-D containers and higher dimensional structures can be created and used according to the application.

**Vectore are used over arrays mainly because arrays are statically allocated in the memory while vectors can be dynamically allocated at runtime.**

`#include <vector>`

## Vector Declaration
Vectors are created to have dynamic size (as it is their biggest advantage over arrays).
```vector<int> vector_1;```

Vector of integers declaration with a fixed size of 10:

```vector<int> vector_2(10)```

## Functions for iteration
1. `begin()`: to return an iterator pointing to the first element in the vector.
2. `end()`: to return an iterator pointing to the element after the last element in the vector.
3. `rbegin()`: to get a reverse iterator pointing to the last element in the vector but in this case moves from the last to the first element.
4. `rend()`: to get a reverse iterator pointing to the element before the first element in the vector.

## Accessing Vector Elements

`int element = myVect[index]`

or

`int element = myVect.at(index)`

## Modifying the vector

1. `push_back()`: allows to add a number to the end of the vector.
    * `vector_1.push_back(value)`
2. `pop_back()`: helps to remove the last element in the vector.
3. `insert()`: insert an element at a given index or position.
4. `erase()`: remove elements from vector from specified indices or range.
5. `clear()`: removes all elements from vector container.
6. `emplace_back()`

## Functions for Size Manipulation
* `size()`: returns the size of vector or the number of elements
* `capacity()`: tells the memory allocated to the vector
* `shring_to_fit()`: reduces the memory allocated to vector to only match the number of elements.
* `resize()`: reshapes the container to contain only a specific amount of elements.
* `empty()`: returns a boolean whether vector is empty or not.


## Some good concepts

### Printing vectors

**Normal for loop**


**Iterator**


### vector of class objects

```c++
#include <iostream>
#include <vector>

class MyClass {
public:
    int value;
    MyClass(int val) : value(val) {}
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Create a vector of MyClass objects
    std::vector<MyClass> myVector;

    // Add objects to the vector
    myVector.push_back(MyClass(10));
    myVector.push_back(MyClass(20));
    myVector.emplace_back(30); // Efficiently construct in place

    // Access and use objects in the vector
    for (const auto& obj : myVector) {
        obj.display();
    }

    // Modify an object in the vector
    myVector[0].value = 15;
    myVector[0].display();

    return 0;
}
```


