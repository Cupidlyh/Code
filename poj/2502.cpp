#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include<cstdio>
using namespace std;

long double length[220][220];//记录点到点之间的分钟数
int x[220];//存所有的x坐标
int y[220];//存所有的y坐标
int ind = 1;//x，y数组的下标

long double len(int ax,int ay,int bx,int by)//算出两点之间的直线距离
{
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

void floyd(int n)//n为图的顶点的个数
{
    int i,j,k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(length[i][j] > length[i][k] + length[k][j])//从i经k到j的时间更短
                {
                    length[i][j] = length[i][k] + length[k][j];//更新length[i][j]
                }
}

int main()
{
    int i,j,flag = 0;//flag标记是否输入的地铁站换到下一线路
    double v1 = 10000.0 / 60;//步行的速度（m/min）
    double v2 = 40000.0 / 60;//地铁的速度（m/min）
    for(i = 0; i < 220; i++)//初始化
        for(j = 0; j < 220; j++)
            if(i == j)
                length[i][j] = 0;
            else
                length[i][j] = INT_MAX;
    cin>>x[ind]>>y[ind];//输入起点
    ind++;
    cin>>x[ind]>>y[ind];//输入终点
    ind++;
    while(cin>>x[ind]>>y[ind])//读入所有站点坐标
    {
        if(x[ind] == -1 && y[ind] == -1)//代表换到下一线路
        {
            flag = 1;//标记
            continue;
        }
        if(flag == 1)//前一线路的终点到此线路的起点需要步行
        {
            length[ind - 1][ind] = len(x[ind - 1],y[ind - 1],x[ind],y[ind]) / v1;//计算时间
            length[ind][ind - 1] = length[ind - 1][ind];//无向图
            flag = 0;//取消标记
            ind++;
            continue;
        }
        if(ind == 3)//起点到第一条线路的第一个站点也要步行
        {
            length[1][3] = len(x[1],y[1],x[3],y[3]) / v1;//计算时间
            length[3][1] = length[1][3];
        }
        if(ind > 3)
        {
            length[ind - 1][ind] = len(x[ind - 1],y[ind - 1],x[ind],y[ind]) / v2;//计算地铁在两站点之间运行的时间（坐地铁）
            length[ind][ind - 1] = length[ind - 1][ind];
        }
        ind++;
    }
    length[ind - 1][2] = len(x[ind - 1],y[ind - 1],x[2],y[2]) / v1;//计算时间（最后一条线路到终点需要步行）
    length[2][ind - 1] = length[ind - 1][2];
    for(i = 1; i < ind; i++)
        for(j = 1; j < ind; j++)
            if(length[i][j] == INT_MAX)//地铁未连通的点都可以通过步行到达
            {
                length[i][j] = len(x[i],y[i],x[j],y[j]) / v1;//计算时间
                length[j][i] = length[i][j];//无向图
            }
    floyd(ind - 1);//弗洛伊德算法
    cout<<(int)(length[1][2] + 0.5)<<endl;//结果要四舍五入
    return 0;
}
