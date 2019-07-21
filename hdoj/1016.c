#include<stdio.h>
#include<stdlib.h>
int n;
int a[25];
int color[25];
int parent[25];

void print()
{
    for(int i=1; i<n; i++)
    {
        printf("%d ",parent[i]);
    }
    printf("%d\n",parent[n]);
}

int isPrime(int num)
{
    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int u, int count)
{
    count++;
    //递归鸿沟
    if(count==n && isPrime(a[u]+a[1]))
    {
        //找到一组题解
        parent[count] = a[u];
        print();//输出
        return;//返回
    }
    color[u]=1; //表示已经搜索,灰色
    //搜索u的所有邻居节点
    for(int v=1; v<=n; v++)
    {
        if( color[v]==-1 && isPrime(a[u]+a[v]) )
        {
            //找到一个满足条件的节点
            parent[count] = a[u];//记录上级节点
            dfs(v,count);
            color[v]=-1; //把v还原成未搜索状态，以让后续路径能够尝试访问
        }
    }
}

int main()
{
    int k=0;
    while( ~scanf("%d",&n))
    {
        printf("Case %d:\n",(++k) );
        //初始化图
        for(int i=1; i<=n; i++ )
        {
            a[i] = i;
            color[i] = -1; //白色--未搜索
            parent[i] = -1; //上级节点
        }
        int count=0; //time, 搜索到的节点个数
        dfs(1,count);
        printf("\n");
    }
    return 0;
}
