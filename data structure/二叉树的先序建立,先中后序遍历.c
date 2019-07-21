//�������������������к������
#include <stdio.h>
#include <stdlib.h>
#define MAXTSIZE 100

typedef struct bitree
{
    char data;
    struct bitree *lchild;
    struct bitree *rchild;
} bitree;

void createbitree(bitree **t)//������������
{
    char ch;
    scanf("%c",&ch);
    printf("%c",ch);
    if(ch=='#')
        *t=NULL;
    else
    {
        *t=(bitree*)malloc(MAXTSIZE*sizeof(bitree));
        (*t)->data=ch;
        createbitree(&(*t)->lchild);
        createbitree(&(*t)->rchild);
    }
}

void preorder(bitree *t)//�������
{
    if(t)
    {
        printf("%c ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bitree *t)//�������
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c ",t->data);
        inorder(t->rchild);
    }
}

void postorder(bitree *t)//�������
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c ",t->data);
    }
}

int main()
{
    printf("������ȷ��˳��������Ҫ������������������\n");
    bitree *root;
    freopen("in.txt","r",stdin);
    createbitree(&root);
    printf("\n");
    printf("��������������Ľ����");
    preorder(root);
    printf("\n");
    printf("��������������Ľ����");
    inorder(root);
    printf("\n");
    printf("��������������Ľ����");
    postorder(root);
    printf("\n");
    return 0;
}
