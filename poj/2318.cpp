#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tx[5005];//存储隔板上边界横纵坐标
int ty[5005];
int bx[5005];//存储隔板下边界横纵坐标
int by[5005];
int num[5005];//记录每个格子玩具数量
double k[5005];//算出隔板直线的斜率
double b[5005];//直线公式中的b(y = k * x + b)

int main()
{
    int n,m,x1,x2,y1,y2;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        scanf("%d %d %d %d %d",&m,&x1,&y1,&x2,&y2);
        memset(num,0,sizeof(num));
        int i,j,U,L,x,y,flag;
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&U,&L);
            tx[i] = U;
            ty[i] = y1;
            bx[i] = L;
            by[i] = y2;
            if(U == L)//隔板是竖直的情况是无斜率的（垂直于x轴）
            {
                k[i] = 0;
            }
            else//隔板非竖直情况
            {
                k[i] = ((double)y1 - (double)y2) / (U - L);
                b[i] = y1 - k[i] * U;
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
            printf("%d: %d\n",j,num[j]);
        printf("\n");
    }
    return 0;
}
