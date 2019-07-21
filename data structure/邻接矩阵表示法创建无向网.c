//邻接矩阵创建无向网
#include <stdio.h>
#include <stdlib.h>
#define MaxInt 32767
#define MVNum 100

typedef struct
{
    char vexs[MVNum];       //顶点表
    int arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum,arcnum;      //图的当前点数和边数
} amgraph;

int locate(amgraph *g,char ch)//确定元素的位置
{
    int i;
    for(i=0; i<g->vexnum; i++)
        if(g->vexs[i]==ch)
            return i;
}

int creat(amgraph *g)//创建无向网
{
    int i,j,k;
    printf("请输入总顶点数 总边数:");
    scanf("%d %d",&g->vexnum,&g->arcnum);
    getchar();
    printf("%d %d",g->vexnum,g->arcnum);
    printf("\n请输入顶点的名称\n");
    for(i=0; i<g->vexnum; i++)
    {
        scanf("%c",&g->vexs[i]);
        getchar();
        printf("%c",g->vexs[i]);
    }
    for(i=0; i<g->arcnum; i++)
        for(j=0; j<g->arcnum; j++)
            g->arcs[i][j]=MaxInt;
    printf("\n请输入每条边的两个端点及这两个端点之间的权值\n");
    for(k=0; k<g->arcnum; k++)
    {
        char u1,u2;
        int v,m,n;
        scanf("%c %c %d",&u1,&u2,&v);
        getchar();
        printf("%c %c %d\n",u1,u2,v);
        m=locate(g,u1);
        n=locate(g,u2);
        g->arcs[m][n]=v;
        g->arcs[n][m]=v;
    }
    return 1;
}

int main()
{
    amgraph g;
    int i,j;
    freopen("in.txt","r",stdin);
    creat(&g);
    printf("\n");
    for(i = 0 ; i < g.vexnum ; i++)
    {
        for(j = 0; j < g.vexnum; j++)
        {
            if(j != g.vexnum - 1)
            {
                if(g.arcs[i][j] != MaxInt)
                    printf("%d  ",g.arcs[i][j]);
                else
                    printf("∞ ");
            }
            else
            {
                if(g.arcs[i][j] != MaxInt)
                    printf("%d\n",g.arcs[i][j]);
                else
                    printf("∞\n");
            }
        }
    }
    return 0;
}
