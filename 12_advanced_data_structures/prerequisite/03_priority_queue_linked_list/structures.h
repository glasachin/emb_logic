typedef struct data // data or info
{
    int priority;
    int value;
}DataSet;

typedef struct item // linklist node
{
    struct item *pnx; // pointer to next item
    DataSet *pds;
}Item;

typedef struct pqueue // like start node
{
    struct pqueue *next;
    // DataSet *ds;
    Item *pfi; // pointer to first item
    int count;
}PQueue;

