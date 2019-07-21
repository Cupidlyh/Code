//顺序表
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
    char no[20];
    char name[50];
    float price;
} BOOK;
typedef struct
{
    BOOK *elem;
    int length;
} sqlist;

int initlist(sqlist *l)//顺序表的初始化
{
    l->elem=(BOOK*)malloc(MAXSIZE*sizeof(BOOK));
    if(l->elem==NULL)
        return 0;
    l->length=0;
    return 1;
}

int getelem(sqlist l,int i,BOOK *e)//顺序表的取值
{
    if(i<1||i>l.length)
        return 0;
    *e=l.elem[i-1];
    return 1;
}

int locateelem(sqlist l,BOOK e)//顺序表的查找
{
    int i;
    for(i=0; i<l.length; i++)
        if(l.elem[i].no==e.no)
            return i+1;
            return 0;
}

int listinsert(sqlist *l,int i,BOOK e)//顺序表的插入
{
    int j;
    if(i<1||i>l->length+1)
        return 0;
    if(l->length==MAXSIZE)
        return 0;
    for(j=l->length;j>=i;j--)
        l->elem[j]=l->elem[j-1];
        l->elem[i-1]=e;
        l->length++;
        return 1;
}

int listdelete(sqlist *l,int i)//顺序表的删除
{
    int j;
    if(i<1||i>l->length)
        return 0;
        for(j=i-1;j<l->length-1;j++)
            l->elem[j]=l->elem[j+1];
        l->length--;
        return 1;
}

int main()
{
    sqlist list;
    freopen("in.txt","r",stdin);
    initlist(&list);
    BOOK book,q;
    int k;
    for(k=1;k<4;k++)
    {
        scanf("%s %s %f",book.no,book.name,&book.price);
        listinsert(&list,k,book);
    }
    getelem(list,2,&q);
    printf("%s  %s  %.2f\n",q.no,q.name,q.price);
    listdelete(&list,2);
    getelem(list,2,&q);
    printf("%s  %s  %.2f\n",q.no,q.name,q.price);
    return 0;
}

