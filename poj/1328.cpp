#include <iostream>
#include<algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int cmp(const void *a,const void *b)
{
    const double p1 = *(const double*)a;
    const double p2 = *(const double*)b;
    if (p1 < p2)
        return -1;
    else if (p1 > p2)
        return 1;
    return 0;
}

int main()
{
    int n,d,x,y;
    int num = 0;
    while(scanf("%d %d",&n,&d) != EOF)
    {
        if(n == 0 && d == 0)
            break;
        int flag = 0;
        num++;
        int i,res = -1;
        double coor[1005][2],xx;
        //以岛屿为圆心，d为半径做圆，求得与x轴的两个交点
        for(i = 0; i < n; i++)
        {
            scanf("%d %d",&x,&y);
            if(y > d)
                flag = 1;
            xx = sqrt(d * d - y * y);
            coor[i][0] = x - xx;
            coor[i][1] = x + xx;
        }
        if(!flag)
        {
            qsort(coor,n,sizeof(coor[0]),cmp);//将二维数组按照头元素的大小来进行从小到大排序
            res = 1;
            i = 1;
            double right = coor[0][1];
            //去掉重读区间并计算所需雷达数目
            while(i < n)
            {
                if(coor[i][1] < right)
                {
                    right = coor[i][1];
                }
                if(coor[i][0] > right)
                {
                    res++;
                    right = coor[i][1];
                }
                i++;
            }
        }
        printf("Case %d: %d\n",num,res);
        getchar();
    }
    return 0;
}
