/*
Created by: Mayank Sonu
Written on: 10th September 2021
Topic: In-Threaded binary tree
Discussion: In-threaded binaty tree helps us in traversing the tree in inorder without using external stack.
It is a special type of tree which contains a pointer to the next node in the inorder traversal.

*/

#include<stdio.h>

struct nodetype{
    int info;
    struct nodetype * left;
    struct nodetype * right;
    int rthread;
    //flag rthread is TRUE when right pointer is not pointing a right child
};
typedef struct nodetype * NODEPTR;

void intrav_with_rthread(tree)
NODEPTR * tree;
{
    NODEPTR p,q;
    p = tree;
    do{
        q =NULL;
        while (p!=NULL)
        {
            q = p;
            p = p ->left;
        }
        if(q!=NULL){
            printf(q->info);
            p = q->right;
            while (q->rthread && p!=NULL)
            {
                printf(p->info);
                q = p;
                p = p-> right;
            }
        }
    }while(q!=NULL);
}

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
    p ->left = NULL;
    p->right = NULL;
    p->rthread = 1;
    return p;
}

void setLeft(p,x)
NODEPTR p; int x;
{
    NODEPTR q;
    if(p==NULL){
        printf("Void Insertion");
        exit(1);
    }else if(p->left==NULL){
        printf("Invalid Insertion");
        exit(1);
    }else{
        q = getnode();
        q->info = x;
        p->left = q;
        q->left =NULL;
        q->right = p;
        q -> rthread = 1 ; //TRUE
    }
}

void setRight(p,x)
NODEPTR p;int x;
{
    NODEPTR q,r;
    if(p==NULL)
        error("void insertion");
    else if(!p->rthread){
        error("invalid insertion");
    }
    else{
        q = getnode();
        q->info = x;
        r = p->right;
        p->right = q;
        q->rthread = 0; //false
        q->left = NULL;
        q->right = r;
        q->rthread = 1; //true
    }
}

// Please try for pre-threaded binary tree