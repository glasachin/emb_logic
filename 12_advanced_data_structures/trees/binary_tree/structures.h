enum flag{
    ready,
    visited,
    processed,

};

typedef struct node
{
    struct node *parent;
    int value;
    enum flag status;
    // struct node **children;
    struct node **leftChild;
    struct node **rightChild; 
}Node;