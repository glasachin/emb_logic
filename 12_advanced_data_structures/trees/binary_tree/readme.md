# Tree in Array (array of pointers)

We put tree at 0th location to start as a tree variable of Node type.

Intially root node will be created at 0th locaiton and then we will move it to 1st location.
e.g. root node will go to 1st location


New node will go to 0th location


## algo
we will check for the NULL for all elements at specific level only. If all are filled then we will create new level elements using realloc and repeat the process