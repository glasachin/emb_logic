# AVL Tree
AVL Tree is self-balancing binary search tree where the difference between heights of left and right subtrees for any node cannot be more than one.

Every node has a `balance factor (BF)` associated with it. The BF of a node is calculated by subtracting the height of its right sub-tree from the height of its left sub-tree. A binary search tree in which every node has a balance factor of -1, 0 or 1 is said to be `height balanced`. A node node with any other balance factor is considered to be unbalanced and required rebalancing of the tree.

`Balance Factor = Height (left sub-tree) - Height (right Sub-tree)`

* if `BF = 1` then tree is `left-heavy tree`.
* if `BF = 0` then hights of both sides are equal.
* if `BF = -1` then tree is `right-heavy tree`.

During insertion or deletion operation tree can get disturbed and rebalancing of the tree may have to be done. Rebalancing is achieved by performing rotation at the critical node. 

There are four types of rotations:
* LL Rotation
* RR Rotation
* LR Rotation
* RL Rotation


## Searching
Similar to that of BST.

## Insert
* The new node is always inserted as the leaf node.
* Insertion is usually followed by an rotation step to restore the balance.
* However, if insertion of the new node doesn't disturb the BF (i.e. BF for each node is still -1, 0 or 1) then rotations are not needed.
* As new node, is added as a leaf node with BF = 0, the BF of inbetween node whill change. The possible changes which may take place in any node on the path are as follows:
    * Initially, the node was either `left-` or `right-heavy` and after insertion, it becomes balanced.
    * Initially, the node was balanced and after insertion, it becomes either `left` or `right-heavy`.
    * Initially, the node was heavy (either left or right) and the new node has been inserted in the heavy sub-tree, thereby creating an unbalanced sub-tree. Such a node is said to be a `critical-node`.

### Balancing
Once tree gets unbalanced (i.e. any node with BF greater than 1), we need to balance it again. 

1. First task is to find the `critical node`. Critical node is the `nearest ancestor` node on the path from the inserted node to the root whose balance factor is neither -1, 0 nor 1. 

2. Second task is to determine which type of rotation has to be done. There are 4 possible rotations based on the conditiongs given below:
    1. `LL Rotation`: The new node is inserted in the left `sub-tree` of the `left sub-tree` of the critical node.
    2. `RR Rotation`: The new node is inserted in the `right sub-tree` of the `right sub-tree` of the critical node.
    3. `LR Rotation`: The new node is inserted in the `right sub-tree` of the `left sub-tree` of the critical node.
    4. `RL Rotation`: The new node is inserted in the `left sub-tree` of the `right sub-tree` of the critical node.
    
     