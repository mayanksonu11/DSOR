/*
Created by: Mayank Sonu
Written on: 9th September 2021
Topic: Binary Tree and Traversal
Discussion: In this we have discussed the methods of traversal for a tree
1. Inorder 2. Preorder 3. Postorder
This code contains discussion of all the three traversals using recursion as well as non-recursion (using stack) 
*/

#include<stdio.h>

struct nodetype{
    int info;
    struct nodetype * leftchild;
    struct nodetype * rightchild;
};
typedef struct nodetype * NODEPTR;

NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct nodetype));
    return p;
}

NODEPTR maketree(x)
int x;
{
    NODEPTR p;
    p = getnode();
    p->info = x;
    p->leftchild =NULL;
    p->rightchild = NULL;
    return p;
}

void setleft(p,x)
NODEPTR p; int x;
{
    if(p==NULL)
        printf("Void Insertion");
    else if(p->leftchild!=NULL)
        printf("invalid insertion");
    else 
        p->leftchild = maketree(x);
}

void setright(p,x)
NODEPTR p; int x;
{
    if(p==NULL)
        printf("Void Insertion");
    else if(p->rightchild!=NULL)
        printf("invalid insertion");
    else 
        p->rightchild = maketree(x);
}

//Inorder traversal (non-rec) using stack
#define MAXSTACK 100

void intrav_non_recursive(tree)
NODEPTR tree;
{
    struct stack{
        int top;
        NODEPTR item[MAXSTACK];
    }s;
    NODEPTR p = tree;
    s.top = -1;

    do{
        while (p != NULL)
        {
            push(s, p);
            p = p->leftchild;
        }
        if (!empty(s))
        {
            p = pop(s);
            printf("%d", p->info);
            p = p->rightchild;
        }
    } while (!empty(s) || p != NULL);
}

void pretrav_non_recursive(tree)
NODEPTR tree;
{
    struct stack{
        int top;
        NODEPTR item[MAXSTACK];
    }s;
    NODEPTR p = tree;
    s.top = -1;
    do{
        while (p != NULL)
        {
            push(s, p);
            printf("%d", p->info);
            p = p->leftchild;
        }
        if (!empty(s))
        {
            p = pop(s);
            p = p->rightchild;
        }
    } while (!empty(s) || p != NULL);

}
// Complete Post order traversal ** Currently incomplete
void posttrav_non_recursive(tree)
NODEPTR tree;
{
    struct stack{
        int top;
        NODEPTR item[MAXSTACK];
    }s;
    NODEPTR p = tree;
    s.top = -1;
    do{
        while (p != NULL)
        {
            push(s, p);
            p = p->leftchild;
        }
        if (!empty(s))
        {
            p = pop(s);
            p = p->rightchild;
        }
    } while (!empty(s) || p != NULL);

}

// Recursive definitions
void pretrav(tree)
NODEPTR tree;
{
    if(tree!=NULL){
        printf(tree->info);
        pretrav(tree->leftchild);
        pretrav(tree->rightchild);
    }
}