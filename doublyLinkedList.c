
/*            List
             _<<|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<             
            |->[Left node][ Data ][Right node]<->[ ][ ][ ]<->[ ][ ][ ]<->[ ][ ][ ]<->[ ][ ][ ]<->[ ][ ][ ]->^
            >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|    
*/
#include<stdio.h>

struct node{
    int info;
    struct node *left,*right;
}
typedef struct node * NODEPTR;

delete(p,px)
NODEPTR p; int *px;
{
    NODEPTR q,r;
    if(p==NULL){
        printf("Void deletion");
        exit(1);
    }
    *px = p->info;
    
    
}

insertright(p,px)
NODEPTR p; int x;
{
    NODEPTR q;
    q = getnode();
    q->info = x;
    q->right = p->right;
    *(p->right)->left = q;
    p->right = q;
    q->left = p;
    
