//链栈
#include <stdio.h>
#include <stdlib.h>
typedef struct stacknode
{
    int data;
    struct stacknode *next;
} stacknode;

int initstack(stacknode *s)
{
    s->next=NULL;
    return 1;
}

int push(stacknode *s,int m)
{
    stacknode *p;
    p=(stacknode*)malloc(sizeof(stacknode));
    p->data=m;
    p->next=s->next;
    s->next=p;
    return 1;
}

int pop(stacknode *s,int *x)
{
    stacknode *p;
    if(s->next==NULL)
        return 0;
    p=s->next;
    *x=p->data;
    s->next=p->next;
    free(p);
    return 1;
}

int gettop(stacknode *s)
{
    if(s==NULL)
        return 0;
    else
        return s->next->data;
    return 1;
}

int main()
{
    stacknode *l;
    int i,m,x;
    l=(stacknode*)malloc(sizeof(stacknode));
    initstack(l);
    freopen("in.txt","r",stdin);
    printf("请输入想要入链栈的元素\n");
    for(i=0; i<5; i++)
    {
        scanf("%d",&m);
        push(l,m);
    }
    i=gettop(l);
    printf("链栈栈顶元素为：%d\n",i);
    for(i=0; i<5; i++)
    {
        pop(l,&x);
        printf("%d ",x);
    }
    return 0;
}
