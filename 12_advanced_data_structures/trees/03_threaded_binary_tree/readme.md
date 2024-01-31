# Threaded Binary Tree
Similar to binary tree but with a difference in storing the NULL Pointers.

In binary tree, lot of memory gets wasted to store the NULL pointers at leaf nodes.

These NULL pointers space can be used effectively to store some other information, e.g. inorder predecessor or post order predecessor information can be stored there. These special pointers are called `Threads`

There are several different ways of threading a tree.

## One-way threading
Node's right field NULL pointer will be replaced by:

* If left node contains a NULL pointer then it will contain the address of its' parent.

* if right node contains a null pointer then it will contain the address of its' parent's parent.

Where a NULL right pointers is made to point to the inorder successor 


## Two-Way Threading
Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively. The predecessor threads are useful for reverse inorder traversal and postorder traversal.

