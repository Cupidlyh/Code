#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *base;
    int *top;
    int stacksize;
};

int initstack(struct stack *s)
{
    s->base=(int *)malloc (1000*sizeof(int));
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
        *(s->top)=n%2;
        s->top++;
        n=n/2;
    }

    return 0;
}

int pop(struct stack *s)
{
    int q;
    if(s->top==s->base)
        return 0;
    while(s->top!=s->base)
    {
        s->top--;
        q=*(s->top);
        printf("%d",q);
    }
    printf("\n");
    return 0;
}

int main()
{
    int m;
    struct stack s;
    while(scanf("%d",&m)!=EOF)
    {
        initstack(&s);
        push(&s,m);
        pop(&s);
    }
    return 0;
}
