//单链表
#include <stdio.h>
#include <stdlib.h>
typedef struct lnode
{
    int data;
    struct lnode * next;
} lnode;

int initlist(lnode **l)//单链表的初始化
{
    (*l)=(lnode*)malloc(sizeof(lnode));
    (*l)->next=NULL;
    return 1;
}

int getelem(lnode *l,int i,int *e)//单链表的取值
{
    lnode *p=l;
    int j=0;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    *e=p->data;
    return 1;
}

lnode *locateelem(lnode *l,int e)//单链表的按值查找
{
    lnode *p=l;
    while(p&&p->data!=e)
        p=p->next;
    return p;
}

int listinsert(lnode **l,int i,int e)//单链表的插入
{
    lnode *p=*l,*q;
    int j=1;
    while(p&&(j<i))
    {
        p=p->next;
        j++;
    }
    q=(lnode*)malloc(sizeof(lnode));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}

int listdelete(lnode **l,int i)//单链表的删除
{
    lnode *p=*l,*q;
    int j=1;
    while(p&&(j<i))
    {
        p=p->next;
        j++;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    return 1;
}

void creatlist_h(lnode **l)//前插法创建单链表
{
    int i;
    lnode *p=(*l)->next,*q;
    for(i=0; i<5; i++)
    {
        q=(lnode*)malloc(sizeof(lnode));
        scanf("%d",&q->data);
        (*l)->next=q;
        q->next=p;
        p=q;
    }
}

void creatlist_r(lnode **l)//后插法创建单链表
{
    int i;
    lnode *p=(*l)->next,*q;
    lnode *r=*l;
    for(i=0; i<5; i++)
    {
        q=(lnode*)malloc(sizeof(lnode));
        scanf("%d",&q->data);
        r->next=q;
        q->next=p;
        r=q;
    }
}

int main()
{
    lnode *list,*list1,*list2;
    int i,j,k;
    freopen("in.txt","r",stdin);
    initlist(&list);
    for(i=1; i<=5; i++)
    {
        scanf("%d",&j);
        listinsert(&list,i,j);
    }
    for(i=1;i<=5;i++)
    {
    getelem(list,i,&k);
    printf("%d ",k);
    }
    printf("\n");
    listdelete(&list,2);
    for(i=1;i<=4;i++)
    {
    getelem(list,i,&k);
    printf("%d ",k);
    }
    printf("\n");
    initlist(&list1);
    creatlist_r(&list1);
    for(i=1; i<=5; i++)
    {
        getelem(list1,i,&k);
        printf("%d ",k);
    }
    printf("\n");
    initlist(&list2);
    creatlist_h(&list2);
    for(i=1; i<=5; i++)
    {
        getelem(list2,i,&k);
        printf("%d ",k);
    }
    return 0;
}
