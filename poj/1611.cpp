#include <iostream>
using namespace std;

int father[30005];//记录父节点

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
int main()//考察并查集的知识
{
    int n,m,i,j,k,d,p;
    while(cin>>n>>m)
    {
        if(n == 0 && m == 0)
            break;
        if(m == 0)
            cout<<1<<endl;
        else
        {
            for(i = 0; i < n; i++)//数组初始化
                father[i] = i;
            for(i = 0; i < m; i++)
            {
                cin>>k>>d;
                for(j = 0; j < k - 1; j++)
                {
                    cin>>p;
                    Union(d,p);
                }
            }
            int num = 0;
            for(i = 1; i < n; i++)
                if(Find(i) == Find(0))//查询是否在同一个集合中
                    num++;
            cout<<++num<<endl;
        }
    }
    return 0;
}
