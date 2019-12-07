#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;

struct Edge//链式前向星
{
    int next;//与第i条边同一起点的上一条边的位置
    int to;//此边的终点
    int len;//边的权值
} edge[MAXN];
int head[MAXN];//以i为起点的第一条边存储的位置（实际是最后输入的那个编号）
int index = 0;


bool vis[MAXN];//用来标记点是否在队列中
int cnt[MAXN];//每个点的入队列次数
int length[MAXN];//记录从起点到点n的路径长


void add(int start,int end,int len)//链式前向星的加边函数
{
    edge[index].len = len;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}


bool SPFA(int start,int n)//最短路SPFA算法
{
    int i,j;
    memset(vis,false,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(i = 0; i <MAXN; i++)
    {
        length[i] = INT_MAX;
    }
    queue<int>que;
    que.push(start);//入队
    vis[start] = true;//标记此点入队列
    length[start] = 0;//源点到源点的长度为0
    cnt[start]++;//入队次数加1
    while(!que.empty())
    {
        int u = que.front();
        que.pop();//出队
        vis[u] = false;//标记此点已经不在队列中
        for(j = head[u]; j != -1; j = edge[j].next)//遍历与u联通的点
        {
            int v = edge[j].to;
            if(length[v] > length[u] + edge[j].len)
            {
                length[v] = length[u] + edge[j].len;//路径更新
                if(vis[v] == 0)//如果v点不在队列中
                {
                    que.push(v);//入队
                    vis[v] = 1;//标记
                    cnt[v]++;//入队次数加1
                    if(cnt[v] > n)//如果这个点加入超过n次，说明存在负环回路，直接返回
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int T,S,D;
    while(cin>>T>>S>>D)
    {
        int i,j,a,b,time,start[MAXN],end[MAXN],minn = INT_MAX;
        memset(head,-1,sizeof(head));
        for(i = 0; i < T; i++)
        {
            cin>>a>>b>>time;
            add(a,b,time);//构建链式前向星
            add(b,a,time);
        }
        for(i = 0; i < S; i++)
            cin>>start[i];//读入相邻城市
        for(i = 0; i < D; i++)
            cin>>end[i];//读入目标城市
        for(i = 0; i < S; i++)
        {
            SPFA(start[i],T);//SPFA算法
            for(j = 0; j < D; j++)
                minn = min(minn,length[end[j]]);//找到目标城市花费的最短时间
        }
        cout<<minn<<endl;
    }
    return 0;
}
