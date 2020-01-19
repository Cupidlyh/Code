#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct mp
{
    int x,y;
} node[1005];//存储计算机的坐标

int vis[1005];//将修好的点放进此数组中
int father[1005];//记录父节点

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

double length(int x,int y)
{
    return sqrt((node[x].x - node[y].x) * (node[x].x - node[y].x) + (node[x].y - node[y].y) * (node[x].y - node[y].y));
}


int main()//此题考查并查集的知识
{
    int N,d,i,m,n,bit = 0;
    cin>>N>>d;
    memset(vis,0,sizeof(vis));
    for(i = 1; i <= N; i++)
    {
        cin>>node[i].x>>node[i].y;
        father[i] = i;//并查集中记录父节点的数组初始化
    }
    char c;
    while(cin>>c)
    {
        if(c == 'O')
        {
            cin>>m;
            vis[bit++] = m;
            if(bit >= 2)
            {
                for(i = 0; i < bit - 1; i++)
                {
                    if(length(vis[i],m) <= d)//如果两个点之间的距离小于d
                        Union(vis[i],m);//进行连接

                }
            }
        }
        if(c == 'S')
        {
            cin>>m>>n;
            if(Find(m) == Find(n))//如何两点的父亲是同一个点
                cout<<"SUCCESS"<<endl;//就是成功
            else
                cout<<"FAIL"<<endl;
        }
    }
    return 0;
}
