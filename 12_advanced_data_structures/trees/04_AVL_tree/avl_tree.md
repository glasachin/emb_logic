# AVL Tree
AVL Tree is self-balancing binary search tree where the difference between heights of left and right subtrees for any node cannot be more than one.

Every node has a `balance factor` associated with it. The BF of a node is calculated by subtracting the height of its right sub-tree from the height of its left sub-tree.


## Searching
Similar to that of BST.

## Insert
* The new node is always inserted as the leaf node.
* Insertion is usually followed by an rotation step to restore the balance.
* 

### possible changes
* Initially, the node was either left-or-right 