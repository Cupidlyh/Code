//�������������������ͱ���
#include <stdio.h>
#include <stdlib.h>
typedef struct bitree
{
    struct bitree *lchild,*rchild;
    char data;
    int LTag,RTag;
} bitree;

void creat(bitree **t)
{
    char ch;
    ch=getchar();
    printf("%c",ch);
    if(ch=='#')
        *t=NULL;
    else
    {
        *t=(bitree *)malloc(sizeof(bitree));
        (*t)->data=ch;
        (*t)->LTag=0;
        (*t)->RTag=0;
        creat(&(*t)->lchild);
        creat(&(*t)->rchild);
    }
}

int countnode(bitree *t)//����ڵ���
{
    if(!t)
        return 0;
    else
        return (1+countnode(t->lchild)+countnode(t->rchild));
}

bitree *inling(bitree *t,bitree *pre)//�ݹ���������������
{
    if(t)
    {
        pre=inling(t->lchild,pre);
        if(!t->lchild)
        {
            t->LTag=1;
            t->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->RTag=1;
            pre->rchild=t;
        }
        pre=t;
        pre=inling(t->rchild,pre);
    }
    return pre;
}

bitree *inorderling(bitree *t)//����ͷ��������������
{
    bitree *thrt=(bitree *)malloc(sizeof(bitree)),*pre;
    if(!thrt)
        printf("error\n");
    thrt->LTag=0;
    thrt->RTag=1;
    thrt->rchild=thrt;
    if(!t)
        thrt->lchild=thrt;
    else
    {
        thrt->lchild=t;
        pre=t;
        pre=inling(t,pre);
        pre->RTag=1;
        thrt->rchild=pre;
        pre->rchild=thrt;
    }
    return thrt;
}

void traverse(bitree *t)//�ǵݹ������������������
{
    bitree *p=t->lchild;
    while(p!=t)
    {
        while(p->LTag==0)
            p=p->lchild;
        printf("%d<%c>%d\n",p->LTag,p->data,p->RTag);
        while(p->RTag==1&&p->rchild!=t)
        {
            p=p->rchild;
            printf("%d<%c>%d\n",p->LTag,p->data,p->RTag);
        }
        p=p->rchild;
    }
}

bitree *search(bitree *t,char ch)//�ҵ��ַ��ڶ������е�λ��
{
    bitree *p=t->lchild;
    if(p!=t)
    {
        while(p->LTag==0)
            p=p->lchild;
        if(p->data==ch)
            return p;
        while(p->RTag==1&&p->rchild!=t)
        {
            p=p->rchild;
            if(p->data==ch)
                return p;
        }
        p=p->rchild;
    }
}

void search_post(bitree *t)//�������ַ��ĺ��
{
    bitree *p,*temp;
    if(t->RTag==1)
        temp=t->rchild;
    else
    {
        p=t->rchild;
        while(p->LTag==0)
            p=p->lchild;
        temp=p;
    }
    printf("%c�ĺ��Ϊ%c\n",t->data,temp->data);
}

void search_pre(bitree *t)//�������ַ���ǰ��
{
    bitree *p,*temp;
    if(t->LTag==1)
        temp=t->lchild;
    else
    {
        p=t->lchild;
        while(p->RTag==0)
            p=p->rchild;
        temp=p;
    }
    printf("%c��ǰ��Ϊ%c\n",t->data,temp->data);
}

int main()
{
    freopen("in.txt","r",stdin);
    int m;
    char c;
    bitree *T,*p;
    printf("��������Ҫ�������Ķ�������Ԫ��\n");
    creat(&T);
    m=countnode(T);
    printf("\n�ܽ����Ϊ��%d\n",m);
    T=inorderling(T);
    printf("�������������ɹ�\n");
    printf("�������������������\n");
    traverse(T);
    printf("��������Ҫ����ǰ�̺ͺ�̵Ľ�㣺");
    getchar();
    c=getchar();
    printf("%c\n",c);
    p=search(T,c);
    search_pre(p);
    search_post(p);
    return 0;
}
