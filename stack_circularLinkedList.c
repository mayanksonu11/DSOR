#include<stdio.h>

void push(pstack,x)
NODEPTR *pstack;int x;
{
  NODEPTR p;
  p = getnode(); 
  p->info=x;
  if(empty(pstack)==TRUE)
    *pstack = p;
  else
    p->next = (*pstack)->next;
  (*pstack)->next = p;
}

int pop(pstack)
NODEPTR *pstack;
{
  int x; NODEPTR p;
  if(empty(pstack)==TRUE){
    printf("stack underflow");
    exit(1);
  }
  p = (*pstack)->next;
  x = p->info;
  if(p==*pstack)
    *pstack=NULL;
  else
    (*pstack)->next = p->next;
  freenode(p);
  return x;
}
  
