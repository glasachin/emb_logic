# Binary Search Tree using Linked List

It is also known as an ordered binary tree. In BST all the nodes in the left sub-tree have a value less than that of the root node. Correspondingly, all the nodes in the right sub-tree have a value either equal to or greater than the root node. The same rule is applicable to every sub-tree in the tree. A BST may or may not contain dubplicate values depending upon its implementation.

## Insert Node Algorithm
Normally, insert the node without violating the property of BST.

## Node Deletion
While deletion we need to make sure that properties of BST are not violated.

### Case 1: Deleting node that has no Children0
This is the simplest case, just make the corresponding parent field NULL.

### Case 2: Deleting a Node with one child
The deleted Node's child is set as the child of the node's parent.

* if the node is the left child of its parent, the node's child becomes the left child of the node's parent.

* if the node is the right child of its parent, the node's child becomes the right child of the node's parent.

### Case 3: Deleting a Node with Two Children
In this case, replace the node's value with its `in-order predecessor (largest value in the left sub-tree)` or `in-order successor (smallest value in the right sub-tree)`. The `in-order predecessor` or the `successor` can then be deleted using any of the above cases.

## Inorder Traverse

## Height of BST
We calculate the height of the left sub-tree and the right sub-tree. whichever height is greater, 1 is added to it.


## Number of Nodes in BST

we can use recursion in these cases.

```Number of nodes = totalNodes(left sub-tree)+totalNodes(right sub-tree)+1```

### Number of Internal nodes
Internal nodes or non-leaf nodes.
```
Number of internal nodes = 
                totalinternalNodes(left sub-tree) + 
                totalinternalNodes(right sub-tree) + 
                1

```

### Number of External Nodes
```
Number of external nodes = 
                totalexternalNodes(left sub-tree) + 
                totalexternalNodes(right sub-tree)

```

## Largest and Smallest Node
Smallest node is the `leftmost` node of the left sub-tree. and `largest` node is the `rightmost` node of the right sub-tree.