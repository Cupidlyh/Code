#include <iostream>
#include<cstdio>
using namespace std;

int father[50005];//记录当前节点的父节点
int sum[50005];//记录当前节点到父节点的关系

int Find(int x)//查询x的根节点，路径压缩，更新关系
{
    if(father[x] != x)
    {
        int temp = father[x];
        father[x] = Find(father[x]);
        sum[x] = (sum[x] + sum[temp]) % 3;
    }
    return father[x];
}

int main()
{
    int N,K,d,x,y,i,num = 0;
    scanf("%d %d",&N,&K);
    for(i = 0; i <= N; i++)//数组初始化
    {
        father[i] = i;
        sum[i] = 0;
    }
    for(i = 0; i < K; i++)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x > N || y > N)//第二种情况的假话
        {
            num++;
            continue;
        }
        if(d == 2 && x == y)//第三种情况的假话
        {
            num++;
            continue;
        }
        int rx = Find(x);
        int ry = Find(y);
        if(rx != ry)//集合合并
        {
            father[rx] = ry;
            sum[rx] = (d - 1 +  sum[y] - sum[x] + 3) % 3;
        }
        else//第一种情况的假话
        {
            if(d == 1)
            {
                if(sum[x] != sum[y])//x和y是同类，根节点也一样，所以关系应该相同
                {
                    num++;
                    continue;
                }
            }
            if(d == 2)
            {
                if((sum[x] - sum[y] + 3) % 3 != d - 1)//x吃y，根节点一样，通过向量关系推出此式
                {
                    num++;
                    continue;
                }
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
