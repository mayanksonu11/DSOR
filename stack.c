#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
struct stack{
    int top;
    int item[MAXSIZE];
};
struct stack * ps;

void init(ps)
struct stack *ps;
{
    ps->top=-1;
}

int isempty(ps)
struct stack * ps;
{
    if(ps->top==-1){
        return 1;
    }else
        return 0;
}

void push(ps,x)
struct stack * ps;int x;
{
    if(ps->top==MAXSIZE-1){
        printf("Stack Overflow");
        exit(1);
    }
    ps->item[++ps->top] = x;
}

int pop(ps)
struct stack * ps;
{
    if(ps->top==-1){
        printf("Stack underflow!");
        exit(1);
    }
    return ps->item[ps->top--];
}

int gettop(ps)
struct stack * ps;
{
    if(isempty(ps)){
        printf("Stack empty");
        exit(1);
    }
    return ps->item[ps->top];
}

int main(){
    char uInput;
    struct stack ps;
    init(&ps);
    while(1){
        printf("Please choose one of the options:\na) Push a number into the stack:\nb) Pop a number from the stack:\nc) Display top of the stack:\n");
        scanf("%c",&uInput);
        if(uInput=='a'){
            int num;
            printf("Please enter the number:");
            scanf("%d",&num);
            push(&ps,num);
            printf("Push operation successful!\n");
        }else if(uInput=='b'){
            int num;
            num = pop(&ps);
            printf("Pop operation successful and %d has been removed",num);
        }else if(uInput=='c'){
            int num;
            num = gettop(&ps);
            printf("Top of stack contains:%d\n",num);
        }else if(uInput=='q'){
            break;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}