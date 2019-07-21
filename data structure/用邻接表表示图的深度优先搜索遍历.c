//用邻接表表示图的深度优先搜索遍历
#include<stdio.h>
#include<stdlib.h>
#define MVNum 100

typedef struct arcnode
{
    int adjvex;
    struct arcnode *nextarc;
} arcnode;

typedef struct vnode
{
    char data;
    arcnode *firstarc;
} vnode, adjlist[MVNum];

typedef struct
{
    adjlist vertices;
    int vexnum, arcnum;
} algraph;

int locate(algraph *g,char ch)
{
    int i;
    for(i=0;i<g->vexnum;i++)
        if(g->vertices[i].data==ch)
        return i;
    return -1;
}

int a[MVNum];

void creat(algraph *g)
{
      int i,j;
      printf("请输入总的顶点数和边数:");
      scanf("%d %d",&g->vexnum,&g->arcnum);
      getchar();
      printf("%d %d",g->vexnum,g->arcnum);
      printf("\n请输入顶点的名称\n");
      for(i=0;i<g->vexnum;i++)
      {
          scanf("%c",&g->vertices[i].data);
          getchar();
          printf("%c ",g->vertices[i].data);
          a[i]=0;
          g->vertices[i].firstarc=NULL;
      }
      printf("\n请输入每条边的两个顶点的名称\n");
      for(j=0;j<g->arcnum;j++)
      {
          char v1,v2;
          int m,n;
          scanf("%c %c",&v1,&v2);
          getchar();
          printf("%c %c\n",v1,v2);
          m=locate(g,v1);
          n=locate(g,v2);
          arcnode *p1=(arcnode *)malloc(sizeof(arcnode));
          p1->adjvex=m;
          p1->nextarc=g->vertices[n].firstarc;
          g->vertices[n].firstarc=p1;
          arcnode *p2=(arcnode *)malloc(sizeof(arcnode));
          p2->adjvex=n;
          p2->nextarc=g->vertices[m].firstarc;
          g->vertices[m].firstarc=p2;
      }
}

void DFS_AL(algraph g,int i)
{
      int w;
      printf("%c ",g.vertices[i].data);
      a[i]=1;
      arcnode *p=g.vertices[i].firstarc;
      while(p!=NULL)
      {
          w=p->adjvex;
          if(a[w]!=1)
            DFS_AL(g,w);
          p=p->nextarc;
      }
}

int main()
{
    freopen("in.txt","r",stdin);
    algraph G;
    creat(&G);
    int i;
    for(i = 0 ; i < G.vexnum ; i++)
    {
        vnode temp = G.vertices[i];
        arcnode *p = temp.firstarc;
        if(p == NULL)
        {
            printf("%c\n",G.vertices[i].data);
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
    printf("无向图创建完毕\n");
    printf("请输入遍历连通图的起始点：");
    char c;
    scanf("%c",&c);
    printf("%c\n",c);
    getchar();
    i=locate(&G,c);
    printf("\n");
    while(i==-1)
    {
        printf("该点不存在，请重新输入！\n");
        printf("请输入遍历连通图的起始点：");
        scanf("%c",&c);
        printf("%c\n",c);
        i=locate(&G,c);
    }

    printf("深度优先搜索遍历图结果：\n");
    DFS_AL(G, i);
    printf("\n");
    return 0;
}
