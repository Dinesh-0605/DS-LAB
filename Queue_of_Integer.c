#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct queue
{
    int r;
    int f;
    int data[SIZE];
};
typedef struct queue QUEUE;
void Enqueue(QUEUE *q,int item)
{
    if (q->r==SIZE-1)
        printf("\nQueue is full");
    else
    {
        q->r++;
        q->data[q->r]=item;
        if(q->f==-1)
        {
            q->f=0;
        }
    }
}
void Dequeue(QUEUE *q)
{
    if (q->f==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nElement deleted is %d",q->data[q->f]);
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else
            q->f=q->f+1;
    }
}
void display(QUEUE q)
{
    int i;
    if(q.f==-1){
        printf("\nQueue is Empty");
    }else
    {
        printf("\nQueue contents are:\n");
        for(i=q.f;i<=q.r;i++)
            printf("%d\t",q.data[i]);
    }
}
int main()
{
    int ch,item;
    QUEUE q;
    q.f=-1;
    q.r=-1;
    for(;;)
    {
        printf("\nQueue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element:");
                   scanf("%d",&item);
                   Enqueue(&q,item);
                   break;
            case 2:Dequeue(&q);
                   break;
            case 3:display(q);
                   break;
            default:exit(0);
        }
    }
    return 0;
}

