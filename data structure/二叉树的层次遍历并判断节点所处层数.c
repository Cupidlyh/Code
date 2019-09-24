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

void levelorder(bitree *t,int *depth)//二叉树的层次遍历
{
    bitree *p;
    queue Q;
    for(int i=0; i<MAXQSIZE; i++)
        Q.base[i]=NULL;
    Q.front=Q.rear=0;
    if(t)
    {
        Q.base[Q.rear]=t;
        Q.rear=(Q.rear+1)%MAXQSIZE;
        Q.base[Q.rear]=NULL;//放入NULL来达到将每层分开的目的，方便记录层数
        Q.rear=(Q.rear+1)%MAXQSIZE;
        while(Q.front!=Q.rear)
        {
            p=Q.base[Q.front];
            if(p==NULL)  //当此时为NULL时
            {
                if(Q.base[(Q.front+1)%MAXQSIZE]!=NULL) //当不是最后一层时
                {
                    Q.base[Q.rear]=NULL;//加入NULL代表新的一层要开始了
                    Q.rear=(Q.rear+1)%MAXQSIZE;

                }
                (*depth)++;//层数加1
                printf("  *第%d层的元素如上*\n",*depth);
            }
            if(p!=NULL)
                printf("%c ",p->data);
            Q.front=(Q.front+1)%MAXQSIZE;
            if(p!=NULL)
            {
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
}

int main()
{
    bitree *root;
    int depth=0;
    freopen("in.txt","r",stdin);//从文件中读入
    printf("请以先序的顺序输入想要构建的二叉树\n");
    creatbitree(&root);
    printf("\n二叉树构建成功\n");
    printf("层次遍历的结果\n");
    levelorder(root,&depth);
    printf("\n*  树的深度为：%d  *\n",depth);
    return 0;
}
