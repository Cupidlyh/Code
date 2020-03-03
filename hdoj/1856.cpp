#include <iostream>
using namespace std;

int father[10000005];//记录父节点
int num[10000005];//用于计录有几个集合和每个集合中元素的数量

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
    int n,a,b,i;
    while(cin>>n)
    {
        if(n == 0)
        {
            cout<<1<<endl;
            continue;
        }
        for(i = 0; i < 10000005; i++)//初始化
        {
            father[i] = i;
            num[i] = 0;
        }
        int maxx = 0;//找出朋友的最大编号
        for(i = 0; i < n; i++)
        {
            cin>>a>>b;
            Union(a,b);
            if(a > b)
                maxx = maxx > a ? maxx : a;
            else
                maxx = maxx > b ? maxx : b;
        }
        for(i = 1; i <= maxx; i++)//父节点相同的视为在同一个集合之中
            num[Find(i)]++;
        int res = 0;
        for(i = 1; i <= maxx; i++)
            if(num[i] > res)//找出所有集合中元素最多的那个
                res = num[i];
        cout<<res<<endl;
    }
    return 0;
}
