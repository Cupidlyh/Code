//哈夫曼树的构造和编码
#include <stdio.h>
#include <stdlib.h>
#define N 30
#define M 2*N-1
typedef struct
{
    int weight;
    int parent,lchild,rchild;
} htnode,huffmantree[M+1];

void select(huffmantree ht,int n,int *s1,int *s2)//选择权值最小的点
{
    int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f,temp;
    for(i=0; i<n; i++)
    {
        if(ht[i].weight<min1&&ht[i].parent==0)
        {
            min1=ht[i].weight;
            *s1=i;
        }
    }
    temp=ht[*s1].weight;
    ht[*s1].weight=0x3f3f3f3f;
    for(i=0; i<n; i++)
    {
        if(ht[i].weight<min2&&ht[i].parent==0)
        {
            min2=ht[i].weight;
            *s2=i;
        }
    }
    ht[*s1].weight=temp;
}

void creathuffmantree(huffmantree ht,int n)//构造哈夫曼树
{
    int i,s1,s2,m=2*n-1;
    printf("请输入节点的权值\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&ht[i].weight);
        printf("%d ",ht[i].weight);
    }
    for(i=0; i<m; i++)
    {
        ht[i].lchild=0;
        ht[i].parent=0;
        ht[i].rchild=0;
    }
    for(i=n; i<m; i++)
    {
        select(ht,i,&s1,&s2);
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
    }
}

void printhuff(huffmantree ht,int n)//构造并输出哈夫曼编码
{
    int i,j,p,q;
    char c[M+1];
    for(i=0; i<n; i++)
    {
        p=i;
        for(j=0; ht[p].parent!=0; j++)
        {
            q=ht[p].parent;
            if(p==ht[q].lchild)
                c[j]='0';
            else
                c[j]='1';
            p=ht[p].parent;
        }
        printf("%d:",ht[i].weight);
        for(j=j-1; j>=0; j--)
            printf("%c",c[j]);
        printf("\n");
    }
}

int main()
{
    htnode ht[M+1];
    freopen("in.txt","r",stdin);
    int q;
    printf("请输入节点的个数\n");
    scanf("%d",&q);
    printf("%d\n",q);
    creathuffmantree(ht,q);
    printf("\n哈夫曼树构造成功\n");
    printhuff(ht,q);
    return 0;
}
