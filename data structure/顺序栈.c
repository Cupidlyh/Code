//˳��ջ
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    int a;
} intt;

typedef struct
{
    intt *base;
    intt *top;
    int stacksize;
} student;

int initstack(student *s)
{
    s->base=(intt *)malloc(MAXSIZE*sizeof(intt));
    if(!s->base)
        return 0;
    s->top=s->base;
    s->stacksize=MAXSIZE;
    return 1;
}

int push(student *s,intt m)
{
    if(s->top-s->base==s->stacksize)
        return 0;
    *s->top=m;
    s->top++;
    return 1;
}

int pop(student *s)
{
    if(s->base==s->top)
        return 0;
        s->top--;
        printf("%d ",(*s->top).a);
        return 1;
}

intt gettop(student s)
{
    if(s.base==s.top)
        exit(0);
    else
        return *--s.top;
}

int main()
{
    int i;
    intt k,b;
    student z;
    freopen("in.txt","r",stdin);
    initstack(&z);
    printf("��������Ҫ��ջ��Ԫ��\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&b.a);
        push(&z,b);
    }
    k=gettop(z);
    printf("ջ��Ԫ��Ϊ��%d\n",k.a);
    for(i=0;i<5;i++)
        pop(&z);
        return 0;
}
