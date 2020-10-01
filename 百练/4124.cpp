#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define INF 0X3f3f3f3f

int mapp[20][20];//存储岛与岛之间的时间
int book[20];//标记岛是否走过
int N;

int ans;//结果

//下面这三个变量其实都是利用的二进制
int cur;//当前的状态（二进制表示第i个岛走过第i位就是1否则是0）
int record[20][1<<15];//record[i][j]记录的是从j状态（i状态就是指哪些岛遍历过，二进制表示的）到i岛的最短时间
//每个岛的状态标记（第一个岛的二进制就是10，十进制值就是2，第一个岛的二进制就是100，十进制值就是4）
//如果2 + 4 = 6，二进制表示就是110，代表的就是第一个岛和第二个岛走过了（从后数，从0开始数）
int weight[20];

//pre是之前遍历过岛的数量，now是当前遍历岛的坐标，time就是遍历的时间
void dfs(int pre,int now,int time)
{
    //now是当前点坐标，pre代表之前遍历过岛的数量
    //岛的数量N包含了起点和终点，当前点now到终点就是两个点
    //所以判定条件是pre + 2 == N
    if (pre + 2 == N)
    {
        if (time + mapp[now][N] < ans)
            ans = time + mapp[now][N];
        return ;
    }
    //剪枝
    if (time > ans)
        return ;
    for (int i = 2; i < N; i++)
    {
        //剪枝
        if (book[i])
            continue;
        //判断状态是否之前出现过更小的，也是剪枝
        if (record[i][cur + weight[i]] <= time + mapp[now][i])
            continue;
        cur += weight[i];//状态更新
        book[i] = 1;//标记
        record[i][cur] = time + mapp[now][i];//更新record
        dfs(pre + 1,i,time + mapp[now][i]);
        cur -= weight[i];
        book[i] = 0;
    }
    return ;
}

int main()
{
    //初始化
    for (int i = 1; i <= 16; i++)
    {
        weight[i] = 1 << i;
    }
    while(scanf("%d",&N) != EOF)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d",&mapp[i][j]);
            }
        }
        //初始化
        ans = INF;
        cur = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 1<<15; j++)
                record[i][j] = INF;
        memset(book,0,sizeof(book));
        dfs(0,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
