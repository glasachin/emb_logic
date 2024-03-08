#ifndef __STRUCTURS_H__
#define __STRUCTURS_H__

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
    int BF;
}Node;

typedef enum funName
{
    MAIN_MENU,
    EXIT_PROG,
    CREATE_NODE,
    CREATE_TREE,
    INSERT_NODE,
}e_fptr_funName;

#endif