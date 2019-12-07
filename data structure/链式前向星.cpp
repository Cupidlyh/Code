#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10010;//可根据要求来改变大小

struct Edge//边结构体
{
    int next;//与第i条边同一起点的上一条边的位置
    int to;//此边的终点
    int len;//边的权值
} edge[MAXN];
int head[MAXN];//以i为起点的第一条边存储的位置（实际是最后输入的那个编号）
int index = 0;


void add(int start,int end,int len)//链式前向星的加边函数
{
    edge[index].len = len;
    edge[index].to = end;
    edge[index].next = head[start];
    head[start] = index++;
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)//从题中读入边的关系
    {
        add(a,b,c);//构建链式前向星
    }
    return 0;
}
