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
2. `pop_back()`: helps to remove the last element in the vector.
3. `insert()`: insert an element at a given index or position.
4. `erase()`: remove elements from vector from specified indices or range.
5. `clear()`: removes all elements from vector container.

## Functions for Size Manipulation
* `size()`: returns the size of vector or the number of elements
* `capacity()`: tells the memory allocated to the vector
* `shring_to_fit()`: reduces the memory allocated to vector to only match the number of elements.
* `resize()`: reshapes the container to contain only a specific amount of elements.
* `empty()`: returns a boolean whether vector is empty or not.

