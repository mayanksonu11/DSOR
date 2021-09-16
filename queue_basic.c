#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 100

struct queue{
    int items[MAXQUEUE];
    int front,rear;
};
struct queue * q;

void init(q)
struct queue * q;
{
    q->rear = -1;
    q->front = 0;
}

//insert
void insert(q,x)
struct queue * q; int x;
{
    q->items[++q->rear]=x;
}

//remove
int remove(q)
struct queue * q;
{
    int x = q->items[q->front++];
    return x;
}

//The queue is empty if q.rear < q.front

/*
 __
|__|
|__|
|__|
|__|
|__|<-q.front= 0
    <-q.rear= -1
(a) initially

 __
|__|
|__|
|__|
|__|
|A |<-q.front= q.rear
(b) After insertion of 1 element

 __
|__|
|__|
|C_|<-q.rear= 2
|B_|
|A_|<-q.front= 0
    
(c) Further insertion

 __
|__|
|__|
|C_|<-q.rear= 2
|B_|<-q.front= 1
|__|
  
(d) Removal
*/