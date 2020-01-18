#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int map[105][105];

//之所以数组开辟成long long int是因为防止下面有可能出现越界的情况
int sign[105];//记录从源点v0到终点是否已经被确定最短路径
long long int length[105];//记录从源点v0到终点的当前最短路径长度

//用迪杰斯特拉算法求有向图的v0点到其余各点的最短路径
void dijkstra(int Graph[105][105],int v0,int n)//n为有向图顶点个数
{
    memset(sign,0,sizeof(sign));//sign初始化为0
    int i,v,w,min;
    for(v = 1; v <= n; v++)//n个顶点依次初始化
    {
        length[v] = Graph[v0][v];//将v0到各个终点的最短路径长度初始化为弧上的权值
    }
    length[v0] = 0;//源点到源点的距离为0
    sign[v0] = 1;//将v0加入到sign中

    //初始化结束，开始循环，每次求得v0到某个顶点v的最短路径，将v加入到sign中
    for(i = 2; i <= n; i++)//对其余n-1个顶点依次进行计算
    {
        min = INT_MAX;
        for(w = 1; w <= n; w++)
        {
            if(sign[w] == 0 && length[w] < min)//选择一条当前的最短路径，终点为v
            {
                v = w;
                min = length[w];
            }
        }
        sign[v] = 1;//将v加入sign中
        for(w = 1; w <= n; w++)//更新从v0出发到集合v-s上所有顶点的最短路径长度
        {
            if(sign[w] == 0 && (length[v] + Graph[v][w] < length[w]))
            {
                length[w] = length[v] + Graph[v][w];//更新length[w]
            }
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        int i,j;
        char s[10];
        int max = INT_MIN;
        for(i = 1; i <= n; i++)//地图初始化
            for(j = 1; j <= n; j++)
                if(i != j)
                    map[i][j] = INT_MAX;
                else
                    map[i][j] = 0;

        for(i = 2; i <= n; i++)
            for(j = 1; j < i; j++)
            {
                cin>>s;
                if(s[0] != 'x')
                    map[i][j] = map[j][i] = atoi(s);//将字符串转换为数字
            }

        dijkstra(map,1,n);//n为有向图顶点数，1为源点
        for(i = 1; i <= n; i++)
            if(length[i] > max)//在所有的最短路径中找出一个最大的
                max = length[i];
        cout<<max<<endl;
    }
    return 0;
}
