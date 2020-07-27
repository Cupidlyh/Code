#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;//防止后面溢出，这个不能太大
const int MAXN=1000010;//数组的大小，可随问题的规模而改变

struct qnode//根据c值的大小，c值小的先出队列
{
    //此v，c对应的就是Edge中的v，cost
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};

struct Edge
{
    int v;//终点
    int cost;//起点到终点v的距离
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};

vector<Edge>E[MAXN];//存储图的信息
bool vis[MAXN];//记录从源点v0到终点是否已经被确定最短路径
int dist[MAXN];//记录从源点v0到终点的当前最短路径长度

void Dijkstra(int n,int start)//点的编号从0开始
{
    memset(vis,false,sizeof(vis));//vis初始化为false
    for(int i=0; i<n; i++)//n个顶点依次初始化
        dist[i]=INF;
    priority_queue<qnode> que;
    while(!que.empty())
        que.pop();
    dist[start]=0;//源点到源点的距离为0
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        //优先队列的性质，弹出来的就是最短路径
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])
            continue;
        vis[u]=true;
        //更新从v0出发到集合v-s上所有顶点的最短路径长度
        for(int i=0; i<E[u].size(); i++)
        {
            int v=E[u][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;//长度更新
                que.push(qnode(v,dist[v]));
            }
        }
    }
}

//加边函数（建图）
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}

int main()
{
    Dijkstra(n,start);//n是点的个数，start是起点
    return 0;
}
