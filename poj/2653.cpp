#include <iostream>
#include <stdio.h>
using namespace std;

struct segment//存储线段端点坐标
{
    double x1,y1,x2,y2;
} s[100005];

double cross(double a,double b,double c,double d,double e,double f)//用向量叉乘判断线段与线段是否相交
{
    return (a - c) * (b - f) - (a - e) * (b - d);
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        int i,j,res[1005] = {0},k = 0,flag;//res存储符合条件棍棒的编号
        for(i = 1; i <= n; i++)
            scanf("%lf %lf %lf %lf",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
        for(i = 1; i <= n; i++)
        {
            flag = 0;
            for(j = i + 1; j <= n; j++)
            {
                if(cross(s[i].x1,s[i].y1,s[i].x2,s[i].y2,s[j].x1,s[j].y1) * cross(s[i].x1,s[i].y1,s[i].x2,s[i].y2,s[j].x2,s[j].y2) < 0&&
                   cross(s[j].x1,s[j].y1,s[j].x2,s[j].y2,s[i].x1,s[i].y1) * cross(s[j].x1,s[j].y1,s[j].x2,s[j].y2,s[i].x2,s[i].y2) < 0)//满足此条件就是两个线段相交
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                res[k++] = i;
        }
        printf("Top sticks: ");
        for(i = 0; i < k - 1; i++)
            printf("%d, ",res[i]);
        printf("%d.\n",res[k - 1]);
    }
    return 0;
}
