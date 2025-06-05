# Memory allocation type

* Stack Memory
* Heap Memory

1. Dynamically created variables or objects are allocated on `heaps`.
    * new, malloc, calloc
2. Normal created variables or objects are allocated on stack.
3. Default linux stack size is `8MB`, hence normally created large size variables (1million array size), gives segmentation fault error.
  