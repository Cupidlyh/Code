#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define INF 0x3f3f3f3f//防止后面溢出，这个不能太大
#define N 1000//数组的大小，可随问题的规模而改变

int sign[N];//记录从源点v0到终点是否已经被确定最短路径
int path[N];//记录从源点v0到终点的当前路径上的直接前驱顶点序号
int length[N];//记录从源点v0到终点的当前最短路径长度


//用迪杰斯特拉算法求有向图的v0点到其余各点的最短路径
void dijkstra(int Graph[N][N],int v0,int n)//n为有向图顶点个数
{
    memset(sign,0,sizeof(sign));//sign初始化为0
    int i,v,w,min;
    for(v = 0; v < n; v++)//n个顶点依次初始化
    {
        length[v] = Graph[v0][v];//将v0到各个终点的最短路径长度初始化为弧上的权值
        if(length[v] < INF)//如果v0和v之间有弧，则将v的前驱置为v0
            path[v] = v0;
    }
    length[v0] = 0;//源点到源点的距离为0
    sign[v0] = 1;//将v0加入到sign中

    //初始化结束，开始循环，每次求得v0到某个顶点v的最短路径，将v加入到sign中
    for(i = 1; i < n; i++)//对其余n-1个顶点依次进行计算
    {
        min = INF;
        for(w = 0; w < n; w++)
        {
            if(sign[w] == 0 && length[w] < min)//选择一条当前的最短路径，终点为v
            {
                v = w;
                min = length[w];
            }
        }
        sign[v] = 1;//将v加入sign中
        for(w = 0; w < n; w++)//更新从v0出发到集合v-s上所有顶点的最短路径长度
        {
            if(sign[w] == 0 && (length[v] + Graph[v][w] < length[w]))
            {
                length[w] = length[v] + Graph[v][w];//更新length[w]
                path[w] = v;//更改w的前驱为v
            }
        }
    }
}


int main()
{
    int Graph[N][N];//有向图Graph
    for(int i = 0; i < N; i++)//初始化Graph为INF，用以表示无连接
        for(int j = 0; j < N; j++)
            Graph[i][j] = INF;
    //scanf("%d",&Graph[m][n]); 从题中读入有向图
    dijkstra(Graph,0,n);//n为有向图顶点数，0为源点（由题意来输入源点,本代码点的编号是[0,n)）
    //printf();输出你想要的最短路径
    return 0;
}
