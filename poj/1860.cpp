#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 1100;

struct Edge//边结构体
{
    int next;//与第i条边同一起点的上一条边的位置
    int to;//此边的终点
    double yongjin;//佣金
    double huilv;//汇率
} edge[MAXN];
int head[MAXN];//以i为起点的第一条边存储的位置（实际是最后输入的那个编号）
int index = 0;


bool vis[MAXN];//用来标记点是否在队列中
int num[MAXN];//每个点的入队列次数
double length[MAXN];//记录从起点到点n的钱数

void add(int start,int end,double huilv,double yongjin)//链式前向星的加边函数
{
    edge[index].huilv = huilv;
    edge[index].yongjin = yongjin;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}


bool SPFA(int start,int n,double temp)//start是起始节点，n是节点总数，temp是初始钱数
{
    int j;
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    memset(length,0,sizeof(length));
    length[start] = temp;
    queue<int>que;
    while(!que.empty())
        que.pop();
    que.push(start);//入队
    vis[start] = true;//标记此点入队列
    num[start]++;//入队次数加1
    while(!que.empty())
    {
        int u = que.front();
        que.pop();//出队
        vis[u] = false;//标记此点已经不在队列中
        for(j = head[u]; j >= 0; j = edge[j].next)//遍历与u联通的点
        {
            int v = edge[j].to;
            if(length[v] < (length[u] - edge[j].yongjin) * edge[j].huilv)
            {
                length[v] = (length[u] - edge[j].yongjin) * edge[j].huilv;//钱数更新
                if(vis[v] == 0)//如果v点不在队列中
                {
                    que.push(v);//入队
                    vis[v] = 1;//标记
                    num[v]++;//入队次数加1
                    if(num[v] > n)//如果这个点加入超过n次，说明存在正环回路，直接返回
                        return true;
                }
            }
            if(length[start] > temp)//如果钱数大于初始值（同一种钱）
                return true;
        }
    }
    return false;
}


int main()
{
    int n,m,s;
    double v;
    while(cin>>n>>m>>s>>v)
    {
        memset(head,-1,sizeof(head));
        int i,a,b;
        double c,d,e,f;
        for(i = 0; i < m; i++)
        {
            cin>>a>>b>>c>>d>>e>>f;
            add(a,b,c,d);//构建前向星
            add(b,a,e,f);
        }
        if(SPFA(s,n,v))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
