#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100

typedef struct bitree//树的结构
{
    char data;
    struct bitree *left;
    struct bitree *right;
} bitree;

typedef struct queue//队列
{
    bitree *base[100];
    int front;
    int rear;
} queue;

void creatbitree(bitree **t)//先序建立二叉树
{
    char ch;
    scanf("%c",&ch);
    printf("%c",ch);
    if(ch=='#')
        *t=NULL;
    else
    {
        *t=(bitree *)malloc(sizeof(bitree));
        (*t)->data=ch;
        creatbitree(&(*t)->left);
        creatbitree(&(*t)->right);
    }
}

void levelorder(bitree *t)//二叉树的层次遍历
{
    bitree *p;
    queue Q;
    Q.front=Q.rear=0;
    if(t)
    {
        Q.base[Q.rear]=t;
        Q.rear=(Q.rear+1)%MAXQSIZE;
        while(Q.front!=Q.rear)
        {
            p=Q.base[Q.front];
            printf("%c ",p->data);
            Q.front=(Q.front+1)%MAXQSIZE;
            if(p->left)
            {
                Q.base[Q.rear]=p->left;
                Q.rear=(Q.rear+1)%MAXQSIZE;
            }
            if(p->right)
            {
                Q.base[Q.rear]=p->right;
                Q.rear=(Q.rear+1)%MAXQSIZE;
            }
        }
    }
}

int main()
{
    bitree *root;
    freopen("in.txt","r",stdin);//从文件中读入
    printf("请以先序的顺序输入想要构建的二叉树\n");
    creatbitree(&root);
    printf("\n二叉树构建成功\n");
    printf("层次遍历的结果\n");
    levelorder(root);
    return 0;
}
