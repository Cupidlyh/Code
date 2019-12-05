#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int map[1005][1005];//存正向的有向图
int map1[1005][1005];//存逆向的有向图（正向的倒过来存储）
int qusign[1005];//标记数组
int huisign[1005];
int qu_len[1005];//记录母牛去的过程中从起点到当前位置的距离
int hui_len[1005];//记录母牛回来的过程中从起点到当前位置的距离


void qu_dij(int x,int n)
{
    memset(qusign,0,sizeof(qusign));
    int i,v,w,min;
    for(v = 1; v <= n; v++)
    {
        qu_len[v] = INT_MAX;
        if(map1[x][v] != -1)
            qu_len[v] = map1[x][v];
    }
    qu_len[x] = 0;
    qusign[x] = 1;

    for(i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(qusign[w] == 0 && qu_len[w] < min)
            {
                v = w;
                min = qu_len[w];
            }
        }
        qusign[v] = 1;
        for(w = 1; w <= n; w++)
        {
            if(map1[v][w] != -1 && qusign[w] == 0 && (qu_len[v] + map1[v][w] < qu_len[w]))
            {
                qu_len[w] = qu_len[v] + map1[v][w];
            }
        }
    }
}

void hui_dij(int x,int n)
{
    memset(huisign,0,sizeof(huisign));//标记数组初始化
    int i,v,w,min;
    for(v = 1; v <= n; v++)//n个顶点依次初始化
    {
        hui_len[v] = INT_MAX;
        if(map[x][v] != -1)
            hui_len[v] = map[x][v];//将x到各个终点的最短路径长度初始化为弧上的权值
    }
    hui_len[x] = 0;//源点到源点的距离为0
    huisign[x] = 1;//将源点加入到标记数组中

    //初始化结束，开始循环，每次求得x到某个顶点v的最短路径，将v加入到标记数组中
    for(i = 2; i <= n; i++)
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(huisign[w] == 0 && hui_len[w] < min)//选择一条当前的最短路径，终点为v
            {
                v = w;
                min = hui_len[w];
            }
        }
        huisign[v] = 1;//将v加入标记数组中
        for(w = 1; w <= n; w++)//更新从x出发到集合v-s上所有顶点的最短路径长度
        {
            if(map[v][w] != -1 && huisign[w] == 0 && (hui_len[v] + map[v][w] < hui_len[w]))
            {
                hui_len[w] = hui_len[v] + map[v][w];//更新hui_len[w]
            }
        }
    }
}

int main()
{
    int N,M,X;
    while(cin>>N>>M>>X)
    {
        memset(map,-1,sizeof(map));//有向图的初始化
        memset(map1,-1,sizeof(map1));
        int i,a,b,c;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>c;
            map[a][b] = c;//存储初始的有向图
            map1[b][a] = c;//将有向图倒过来存储
        }
        hui_dij(X,N);//母牛回来所走的路程
        qu_dij(X,N);//母牛过去所走的路程
        int max = INT_MIN;
        for(i = 1; i <= N; i++)
        {
            if(i == X)
                continue;
            if(qu_len[i] + hui_len[i] > max)//计算所有母牛中的最大路程
                max = qu_len[i] + hui_len[i];
        }
        cout<<max<<endl;
    }
    return 0;
}
