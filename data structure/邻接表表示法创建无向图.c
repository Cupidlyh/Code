//�ڽӱ��ʾ����������ͼ
#include<stdio.h>
#include<stdlib.h>
#define MVNum 100

typedef struct arcnode
{
    int adjvex;//�ñ���ָ��Ķ����λ��
    struct arcnode *nextarc;//ָ����һ���ߵ�ָ��
} arcnode;

typedef struct vnode//������Ϣ
{
    char data;
    arcnode *firstarc;//ָ���һ�������ö���ıߵ�ָ��
} vnode, adjlist[MVNum];

typedef struct
{
    adjlist vertices;
    int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
} algraph;

int locate(algraph *g,char ch)//��λԪ�ص�λ��
{
    int i;
    for(i=0; i<g->vexnum; i++)
        if(g->vertices[i].data==ch)
            return i;
}

int creat(algraph *g)//��������ͼ
{
    int i,j;
    printf("�������ܶ��������ܱ���:");
    scanf("%d %d",&g->vexnum,&g->arcnum);
    getchar();
    printf("%d %d",g->vexnum,g->arcnum);
    printf("\n������������\n");
    for(j=0; j<g->vexnum; j++)
    {
        scanf("%c",&g->vertices[j].data);
        getchar();
        printf("%c\n",g->vertices[j].data);
        g->vertices[j].firstarc=NULL;
    }
    printf("������ÿ���ߵ���������\n");
    for(i=0; i<g->arcnum; i++)
    {
        char v1,v2;
        int m,n;
        scanf("%c %c",&v1,&v2);
        getchar();
        printf("%c %c\n",v1,v2);
        m=locate(g,v1);
        n=locate(g,v2);
        arcnode *p1=(arcnode *)malloc(sizeof(arcnode));
        p1->adjvex=n;
        p1->nextarc=g->vertices[m].firstarc;
        g->vertices[m].firstarc=p1;
        arcnode *p2=(arcnode *)malloc(sizeof(arcnode));
        p2->adjvex=m;
        p2->nextarc=g->vertices[n].firstarc;
        g->vertices[n].firstarc=p2;
    }
    return 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    algraph g;
    creat(&g);
    int i;
    printf("\n");
    for(i = 0 ; i < g.vexnum ; i++)
    {
        vnode temp = g.vertices[i];
        arcnode *p = temp.firstarc;
        if(p == NULL)
        {
            printf("%c\n",g.vertices[i].data);
        }
        else
        {
            printf("%c",temp.data);
            while(p)
            {
                printf("->");
                printf("%d",p->adjvex);
                p = p->nextarc;
            }
        }
        printf("\n");
    }
    return 0;
}
