#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *base;
    int *top;
    int stacksize;
};
int a[3];

int initstack(struct stack *s)
{
    s->base=(int *)malloc (sizeof(int));
    if(!s->base)
        exit(-2);
    s->top=s->base;
    s->stacksize=(int *)malloc (sizeof(int));
    return 1;
}

int push(struct stack *s,int n)
{

    if(s->top-s->base>=s->stacksize)
        return 0;
    while(n)
    {
        *(s->top)=n%12;
        s->top++;
        n=n/12;
    }
    return 0;
}

int pop(struct stack *s)
{
    int q;
    a[1]=0;
    if(s->top==s->base)
        return 0;
    while(s->top!=s->base)
    {
        s->top--;
        q=*(s->top);
        a[1]=a[1]+q;
    }
    return a[1];
}

int push1(struct stack *s,int n)
{

    if(s->top-s->base>=s->stacksize)
        return 0;
    while(n)
    {
        *(s->top)=n%16;
        s->top++;
        n=n/16;
    }
    return 0;
}

int pop1(struct stack *s)
{
    int q;
    a[2]=0;
    if(s->top==s->base)
        return 0;
    while(s->top!=s->base)
    {
        s->top--;
        q=*(s->top);
        a[2]=a[2]+q;
    }
    return a[2];
}
int main()
{
    int m,x,y;
    struct stack s,q;
    while(scanf("%d",&m))
    {
        if(m==0)
            break;
        a[0]=m%10+(m%100)/10+m/1000+(m%1000)/100;
        initstack(&s);
        push(&s,m);
        x=pop(&s);
        initstack(&q);
        push1(&q,m);
        y=pop1(&q);
        if(x==y&&y==a[0])
            printf("%d is a Sky Number.\n",m);
        else
            printf("%d is not a Sky Number.\n",m);
    }
    return 0;
}
