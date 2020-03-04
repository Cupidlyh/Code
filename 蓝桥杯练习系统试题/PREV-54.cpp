#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int father[1000000];//记录父节点
int num[1000000];//用于计录有几个集合和每个集合中元素的数量 

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
    for(i = 0; i < 1000000; i++) {//初始化
        father[i] = i;
        num[i] = 0;
    }
	int m,n,k,a,b;
	cin>>m>>n;
	cin>>k;
	for(i = 0; i < k; i++) {
		cin>>a>>b;
		Union(a,b);
	}
	for(i = 1; i <= m * n; i++)//父节点相同的视为在同一个集合之中 
		num[Find(i)]++;
	int res = 0;
	for(i = 1; i <= m * n; i++)
		if(num[i] > 0)//找出集合的个数 
			res++;
	cout<<res<<endl;
    return 0;
}
