typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
}Node;

typedef struct node_info
{
    Node *node;
    Node *parent;
}nodeInfo;