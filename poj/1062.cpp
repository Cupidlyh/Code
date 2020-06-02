#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

#define N 109
#define MIN(a,b) a>b?b:a

struct node//存储主人宝物的价格和主人的等级
{
    int money;
    int level;
} no[N];

int m,n;
int Graph[N][N];//存储点到点的信息
long long int length[N];//记录从源点到终点的当前最少金币数
int sign[N];//标记点是否访问过
int limit[N];//标记点是否被限制（不能参与交换）

int dijkastra()//迪杰斯特拉算法
{
    memset(sign,0,sizeof(sign));
    int i,v,w,minn;
    for(v = 1; v <= n; v++)
        length[v] = INT_MAX;
    length[1] = 0;

    for(i = 2; i <= n; i++)
    {
        minn = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(sign[w] == 0 && length[w] <= minn && limit[w])//选择一条当前的花费最少的路径，终点为v
            {
                v = w;
                minn = length[w];
            }
        }
        sign[v] = 1;
        for(w = 1; w <= n; w++)//更新从起点出发到集合v-s上所有顶点的最少金币数
        {
            if((length[v] + Graph[v][w] < length[w]) && limit[w] && sign[w] == 0)
            {
                length[w] = length[v] + Graph[v][w];//更新length[w]
            }
        }
    }
    int ans = INT_MAX;
    for(i = 1; i <= n; i++)//加上自身所花的金币
    {
        length[i] = length[i] + no[i].money;
        ans = MIN(ans,length[i]);
    }
    return ans;
}

int main()
{
    scanf("%d %d",&m,&n);
    int i,j;
    for(i = 0; i < N; i++)//初始化Graph为整型最大值，用以表示无连接
        for(j = 0; j < N; j++)
            Graph[i][j] = INT_MAX;
    for(i = 1; i <= n; i++)
    {
        int p,l,x;
        scanf("%d %d %d",&p,&l,&x);
        no[i].money = p;
        no[i].level = l;
        for(j = 0; j < x; j++)
        {
            int t,v;
            scanf("%d %d",&t,&v);
            Graph[i][t] = v;
        }
    }
    int ans = INT_MAX,kinglevel = no[1].level;
    //枚举等级区间
    for(i = 0; i <= m; i++)
    {
        memset(limit,0,sizeof(limit));
        for(j = 1; j <= n; j++)
        {
            if((no[j].level >= kinglevel - m + i) && (no[j].level <= kinglevel + i))
                limit[j] = 1;
        }
        ans = MIN(ans,dijkastra());
    }
    printf("%d",ans);
    return 0;
}
