#include <iostream>
#include <climits>
using namespace std;

#define N 1000//数组的大小，可随问题的规模而改变

//之所以数组开辟成long long int是因为防止下面有可能出现越界的情况
int path[N][N];//最短路径上顶点j的前一顶点的序号
long long int length[N][N];//记录顶点i和j之间的最短路径长度


//用弗洛伊德算法求有向网Graph中各对顶点i和j之间的最短路径
void floyd(int Graph[N][N],int n)//n为图的顶点的个数
{
    int i,j,k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            length[i][j] = Graph[i][j];//各对节点初始已知距离
            if(length[i][j] < INT_MAX && i != j)
                path[i][j] = i;//如果i和j之间有弧，j的前驱置为i
            else
                path[i][j] = -1;//如果i和j之间无弧，j的前驱置为-1
        }

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//从i经k到j的一条路径更短
                {
                    length[i][j] = length[i][k] + length[k][j];//更新length[i][j]
                    path[i][j] = path[k][j];//更改j的前驱为k
                }
}

int main()
{
    int Graph[N][N];//有向图Graph
    for(int i = 0; i < N; i++)//初始化Graph为整型最大值，用以表示无连接
        for(int j = 0; j < N; j++)
            Graph[i][j] = INT_MAX;
    //cin>>Graph[m][n];由题意来构建图
    floyd(Graph,n)//n为图的顶点的个数
    //cout<<length[m][n];由题意输出想要的最短路径
    return 0;
}
