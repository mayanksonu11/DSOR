/*
The queue is empty if q.rear == q.front
Circular traversal of array has been imposed
We won't fill up the place where q.front is pointing


 __
|__|<-q.front=q.rear= MAXQUEUE-1 
|__|
|__|
|__|
|__|
    
(a) initially

 __
|__|<-q.front = MAXQUEUE-1
|__|
|__|
|__|
|A |<- q.rear=0
(b) After insertion of 1 element

 __
|__|<-q.front= MAXQUEUE-1
|__|
|C_|<-q.rear= 2
|B_|
|A_|
    
(c) Further insertion

 __
|__|
|__|
|C_|<-q.rear= 2
|B_|
|__|<-q.front= 0
  
(d) Removal
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 100

struct queue{
    int items[MAXQUEUE];
    int front,rear;
};
struct queue * pq;

void init(q)
struct queue * q;
{
    q->rear = MAXQUEUE-1;
    q->front = MAXQUEUE-1;
}

int isEmpty(pq)
struct queue * pq;
{
    return ((pq->front==pq->rear)?1:0);
}

//insert operation
void insert(q,x)
struct queue * q; int x;
{
    if(pq->rear==MAXQUEUE-1)
        pq->rear=0;
    else
        pq->rear++;
    if(pq->rear==pq->front){ //check for isFUll of queue 
        printf("queue overflow");
        exit(1);
    }
    pq->items[pq->rear] = x;
    return;
}

//remove operation
int remove(pq)
struct queue * pq;
{
    if(isEmpty(&pq)){
        printf("queue underflow");
        exit(1);
    }
    if(pq->front==MAXQUEUE-1){
        pq->front = 0;
    }
    else
        pq->front++;
    return pq->items[pq->front];
}

