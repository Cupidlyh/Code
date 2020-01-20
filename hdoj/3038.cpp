#include <iostream>
#include <cstring>
using namespace std;

int father[200005];//存储当前点的父节点
int sum[200005];//存储当前点到根节点的数字之和

int Find(int x)
{
    if(x != father[x])
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = sum[x] + sum[temp];
    }
    return father[x];
}

int main()
{
    int N,M,a,b,s,i;
    while(cin>>N>>M)
    {
        for(i = 0; i <= N ; i++)//数组初始化
        {
            father[i] = i;
            sum[i] = 0;
        }
        int ra,rb,num = 0;
        for(i = 0; i < M; i++)
        {
            cin>>a>>b>>s;
            a--;//因为判断时是靠区间相加（题目的区间要求是左闭右闭），所以左区间减一（通俗点说你知道了区间1-5，和6-10的和，如果你不把6减1,你如何经行下面的更新呢？）
            ra = Find(a);
            rb = Find(b);
            if(ra == rb)//如果两点根节点相同
            {
                if(sum[a] != sum[b] + s)//满足这个条件就说明是错误的
                    num++;
            }
            else
            {
                father[ra] = rb;//根节点进行更新
                sum[ra] = s + sum[b] - sum[a];//距离进行更新
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
