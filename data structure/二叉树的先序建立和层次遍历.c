#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 100

typedef struct bitree//���Ľṹ
{
    char data;
    struct bitree *left;
    struct bitree *right;
} bitree;

typedef struct queue//����
{
    bitree *base[100];
    int front;
    int rear;
} queue;

void creatbitree(bitree **t)//������������
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

void levelorder(bitree *t)//�������Ĳ�α���
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
    freopen("in.txt","r",stdin);//���ļ��ж���
    printf("���������˳��������Ҫ�����Ķ�����\n");
    creatbitree(&root);
    printf("\n�����������ɹ�\n");
    printf("��α����Ľ��\n");
    levelorder(root);
    return 0;
}
