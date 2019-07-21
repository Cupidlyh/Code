//邻接矩阵广度优先搜索
#include <stdio.h>
#include <stdlib.h>
#define MVNum 100
#define MAXQSIZE 100
int visited[MVNum];
typedef struct
{
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum;
} amgraph;

typedef struct
{
    int *base;
    int front;
    int rear;
} squeue;

void initqueue(squeue *q)
{
    q->base=(int *)malloc(MAXQSIZE*sizeof(int));
    if(!q->base)
        exit(0);
    q->front=q->rear=0;
}

void enqueue(squeue *q,int a)
{
    if((q->rear+1)%MAXQSIZE==q->front)
        return;
    q->base[q->rear]=a;
    q->rear=(q->rear+1)%MAXQSIZE;
}

void dequeue(squeue *q,int *u)
{
    *u=q->base[q->front];
    q->front=(q->front+1)%MAXQSIZE;
}

int eempty(squeue *q)
{
    if(q->front==q->rear)
        return 0;
    return 1;
}

int locate(amgraph *g,char a)
{
    int i;
    for(i=0; i<g->vexnum; i++)
        if(g->vexs[i]==a)
            return i;
    return -1;
}

int creat(amgraph *g)
{
    int i,j,k;
    printf("请输入总顶点数，总边数:");
    scanf("%d %d",&g->vexnum,&g->arcnum);
    getchar();
    printf("%d %d\n",g->vexnum,g->arcnum);
    printf("请输入顶点的名称\n");
    for(i=0; i<g->vexnum; i++)
    {
        scanf("%c",&g->vexs[i]);
        getchar();
        printf("%c\n",g->vexs[i]);
        visited[i]=0;
    }
    for(i=0; i<g->vexnum; i++)
        for(j=0; j<g->vexnum; j++)
            g->arcs[i][j]=0;
    printf("请输入每条边的两个顶点\n");
    for(k=0; k<g->arcnum; k++)
    {
        char u,v;
        scanf("%c %c",&u,&v);
        getchar();
        printf("%c %c\n",u,v);
        i=locate(g,u);
        j=locate(g,v);
        g->arcs[i][j]=1;
        g->arcs[j][i]=g->arcs[i][j];
    }
    return 1;
}
int first(amgraph *g,int v)
{
    int i;
    for(i=0; i<g->vexnum; i++)
        if(g->arcs[v][i]==1&&visited[i]!=1)
            return i;
    return -1;
}

int next(amgraph *g,int u,int w)
{
    int i;
    for(i=w; i<g->vexnum; i++)
        if(g->arcs[u][i]==1&&visited[i]!=1)
            return i;
    return -1;
}

void bfs(amgraph g,int v)
{
    squeue q;
    int u,w;
    printf("%c ",g.vexs[v]);
    visited[v]=1;
    initqueue(&q);
    enqueue(&q,v);
    while(eempty(&q)==1)
    {
        dequeue(&q,&u);
        for(w=first(&g,u); w>=0; w=next(&g,u,w))
        {
            if(visited[w]!=1)
            {
                printf("%c ",g.vexs[w]);
                visited[w]=1;
                enqueue(&q,w);
            }
        }
    }
}

int main()
{
    amgraph G;
    freopen("in.txt","r",stdin);
    creat(&G);
    printf("\n");
    printf("*****创建成功*****\n");
    printf("\n");
    printf("请输入遍历连通图的起始点：");
    char c;
    scanf("%c",&c);
    getchar();
    printf("%c\n",c);
    int i;
    for(i = 0 ; i < G.vexnum ; ++i)
    {
        if(c == G.vexs[i])
            break;
    }
    printf("\n");
    while(i >= G.vexnum)
    {
        printf("该点不存在，请重新输入！\n");
        printf("请输入遍历连通图的起始点：");
        scanf("%c",&c);
        printf("%c\n",c);
        for(i = 0 ; i < G.vexnum ; ++i)
        {
            if(c == G.vexs[i])
                break;
        }
    }
    printf("广度优先搜索遍历连通图结果：\n");
    bfs(G, i);
    printf("\n");
    return 0;
}
