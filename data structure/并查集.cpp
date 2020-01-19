#include <iostream>
using namespace std;

#define M 1005

int father[M];//记录父节点

int Find(int x)//查询x的根节点并路径压缩
{
    if(father[x] != x)
        father[x] = Find(father[x]);
    return father[x];
}

void Union(int x,int y)//合并x和y的集合
{
    int rx,ry;
    rx=Find(x);
    ry=Find(y);
    if(rx!=ry)
        father[rx]=ry;
}

int main()
{
    int i;
    for(i = 0; i < M; i++)//初始化
        father[i] = i;

    return 0;
}
