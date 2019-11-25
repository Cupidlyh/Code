#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int sign[205];//标记点是否被走过
double length[205];//记录源点到当前点所有路径中的最大边中的最小边
double Graph[205][2];//存地图
int n;

double max(double a,double b)//比较大小
{
    if(a > b)
        return a;
    return b;
}

double distance(double a,double b,double c,double d)//计算两点间的距离
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}


void dijkstra()
{
    int i,v,w,min;
    for(v = 0; v < n; v++)//初始化
    {
        sign[v] = 0;
        length[v] = INT_MAX;
    }
    length[0] = 0;//源点到源点最大边为0

    for(i = 1; i < n; i++)
    {
        min = INT_MAX;
        for(w = 0; w < n; w++)
        {
            if(sign[w] == 0 && length[w] < min)//选择一条当前的最短路径，终点为v
            {
                v = w;
                min = length[w];
            }
        }
        sign[v] = 1;//将v加入sign中
        for(w = 0; w < n; w++)
        {
            if(sign[w] == 0 && max(length[v],distance(Graph[v][0],Graph[v][1],Graph[w][0],Graph[w][1])) < length[w])//因为题意找所有路径中最大边中的最小边，所以条件是这个
            {
                length[w]=max(length[v],distance(Graph[v][0],Graph[v][1],Graph[w][0],Graph[w][1]));

            }
        }
    }
}

int main()
{
    int m = 0;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        m++;
        int i = 0;
        for(i = 0; i < n; i++)
            scanf("%lf %lf",&Graph[i][0],&Graph[i][1]);
        dijkstra();
        printf("Scenario #%d\n",m);
        printf("Frog Distance = %.3lf\n\n",length[1]);
        getchar();
    }
    return 0;
}
