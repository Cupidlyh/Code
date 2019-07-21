//循环队列
#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100
typedef struct
{
    int m;
} intt;
typedef struct sqqueue
{
    intt *base;
    int front;
    int rear;
} queue;

int initqueue(queue *q)
{
    q->base=(intt*)malloc(MAXQSIZE*sizeof(intt));
    if(!q->base)
        return 0;
    q->front=q->rear=0;
    return 1;
}

int queuelength(queue q)
{
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}

int enqueue(queue *q,intt n)
{
    if((q->rear+1)%MAXQSIZE==q->front)
    return 0;
    q->base[q->rear]=n;
    q->rear=(q->rear+1)%MAXQSIZE;
    return 1;
}

intt dequeue(queue *q)
{
    intt z;
    if(q->rear==q->front)
    exit(0);
    z=q->base[q->front];
    q->front=(q->front+1)%MAXQSIZE;
    return z;
}

intt gethead(queue q)
{
    if(q.front!=q.rear)
        return q.base[q.front];
}

int main()
{
    queue q;
    intt r,z;
    int i;
    initqueue(&q);
    freopen("in.txt","r",stdin);
    printf("请输入想要入循环队列的元素\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&r.m);
        enqueue(&q,r);
    }
    z=gethead(q);
    printf("循环队列队头元素是：%d\n",z.m);
    for(i=0;i<5;i++)
    {
        z=dequeue(&q);
        printf("%d ",z.m);
    }
  return 0;
}
