//邻接表表示法创建无向图
#include<stdio.h>
#include<stdlib.h>
#define MVNum 100

typedef struct arcnode
{
    int adjvex;//该边所指向的顶点的位置
    struct arcnode *nextarc;//指向下一条边的指针
} arcnode;

typedef struct vnode//顶点信息
{
    char data;
    arcnode *firstarc;//指向第一条依附该顶点的边的指针
} vnode, adjlist[MVNum];

typedef struct
{
    adjlist vertices;
    int vexnum, arcnum;//图的当前顶点数和边数
} algraph;

int locate(algraph *g,char ch)//定位元素的位置
{
    int i;
    for(i=0; i<g->vexnum; i++)
        if(g->vertices[i].data==ch)
            return i;
}

int creat(algraph *g)//创建无向图
{
    int i,j;
    printf("请输入总顶点数和总边数:");
    scanf("%d %d",&g->vexnum,&g->arcnum);
    getchar();
    printf("%d %d",g->vexnum,g->arcnum);
    printf("\n请输入点的名称\n");
    for(j=0; j<g->vexnum; j++)
    {
        scanf("%c",&g->vertices[j].data);
        getchar();
        printf("%c\n",g->vertices[j].data);
        g->vertices[j].firstarc=NULL;
    }
    printf("请输入每条边的两个顶点\n");
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
