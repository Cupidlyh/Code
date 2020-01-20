#include <iostream>
using namespace std;

#define M 1005

int father[M];//存储当前点的父节点
int sum[M];//存储当前点到根节点的权值

int Find(int x)//查询x的根节点,路径压缩,权值更新
{
    if(x != father[x])
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = sum[x] + sum[temp];
    }
    return father[x];
}

void Union()//合并
{
    //根据题意自己编写
}

bool Query(int a,int b)//查询a和b是否在同一集合
{
    return Find(a) == Find(b);//根节点相同即为在同一集合
}

int main()
{
    int i;
    for(i = 0; i < M; i++) //初始化
    {
        sum[i] = 0;
        father[i] = i;
    }
    return 0;
}
