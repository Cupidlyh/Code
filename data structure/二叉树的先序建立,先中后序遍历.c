//二叉树的先序建立，先中后序遍历
#include <stdio.h>
#include <stdlib.h>

typedef struct bitree
{
    char data;
    struct bitree *lchild;
    struct bitree *rchild;
} bitree;

void createbitree(bitree **t)//先序建立二叉树
{
    char ch;
    scanf("%c",&ch);
    printf("%c",ch);
    if(ch=='#')
        *t=NULL;
    else
    {
        *t=(bitree*)malloc(sizeof(bitree));
        (*t)->data=ch;
        createbitree(&(*t)->lchild);
        createbitree(&(*t)->rchild);
    }
}

void preorder(bitree *t)//先序遍历
{
    if(t)
    {
        printf("%c ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(bitree *t)//中序遍历
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c ",t->data);
        inorder(t->rchild);
    }
}

void postorder(bitree *t)//后序遍历
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
    printf("请以正确的顺序输入想要先序建立二叉树的数据\n");
    bitree *root;
    freopen("in.txt","r",stdin);
    createbitree(&root);
    printf("\n");
    printf("先序遍历二叉树的结果：");
    preorder(root);
    printf("\n");
    printf("中序遍历二叉树的结果：");
    inorder(root);
    printf("\n");
    printf("后序遍历二叉树的结果：");
    postorder(root);
    printf("\n");
    return 0;
}
