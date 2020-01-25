#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tx[1005];//存储隔板上边界横纵坐标
int ty[1005];
int bx[1005];//存储隔板下边界横纵坐标
int by[1005];
int num[1005];//记录每个格子玩具数量
double k[1005];//算出隔板直线的斜率
double b[1005];//直线公式中的b(y = k * x + b)
int num1[1005];//统计有一样玩具数量的格子数

int main()
{
    int n,m,x1,x2,y1,y2;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d %d %d %d %d",&m,&x1,&y1,&x2,&y2);
        memset(num,0,sizeof(num));
        memset(num1,0,sizeof(num1));
        int i,j,U,L,x,y,flag;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&U,&L);
            tx[i] = U;
            ty[i] = y1;
            bx[i] = L;
            by[i] = y2;
        }
        for(i = 0; i < n; i++)//将隔板按照底部的横坐标从小到大重新排序
        {
            for(j = i + 1; j < n; j++)
            {
                if(bx[i] > bx[j])
                {
                    int k;
                    k = bx[i];
                    bx[i] = bx[j];
                    bx[j] = k;
                    k = tx[i];
                    tx[i] = tx[j];
                    tx[j] = k;
                }
            }
        }
        for(i = 0; i < n; i++)//算出隔板的直线表达式
        {
            if(tx[i] == bx[i])//隔板是竖直的情况是无斜率的（垂直于x轴）
            {
                k[i] = 0;
            }
            else//隔板非竖直情况
            {
                k[i] = ((double)ty[i] - (double)by[i]) / (tx[i] - bx[i]);
                b[i] = ty[i] - k[i] * tx[i];
            }
        }
        double temp;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d",&x,&y);
            flag = 0;
            for(j = 0; j < n; j++)
            {
                temp = k[j] * x + b[j];//求出当前点的x在直线上的y坐标
                if(k[j] == 0 && x < tx[j])//斜率为0时，横坐标又小于当前隔板的横坐标
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
                if(k[j] > 0 && y > temp)//斜率是正数，如果在当前格子那当前点的y坐标就要大于在直线上算出的y坐标（就是temp）
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
                if(k[j] < 0 && y < temp)//斜率是负数，如果在当前格子那当前点的y坐标就要小于在直线上算出的y坐标（就是temp）
                {
                    num[j]++;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)//格子数是隔板数多一个，不在前面的格子那就在最后一个格子
                num[j]++;
        }
        for(j = 0; j <= n; j++)
        {
            if(num[j] > 0)//统计含有相同玩具数的格子数量
                num1[num[j]]++;
        }
        printf("Box\n");
        for(j = 1; j <= m; j++)
        {
            if(num1[j] > 0)
                printf("%d: %d\n",j,num1[j]);
        }
    }
    return 0;
}
