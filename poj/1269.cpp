#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N,i,x1,x2,x3,x4,y1,y2,y3,y4;
    double k1,k2,b1,b2,x,y;
    scanf("%d",&N);
    printf("INTERSECTING LINES OUTPUT\n");
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(x1 != x2)//直线一不是无斜率的情况
        {
            k1 = ((double)y2 - (double)y1) / (x2 - x1);//直线公式是y = k * x + b，求解直线的k和b
            b1 = y1 - k1 * x1;
        }
        if(x3 != x4)//直线二不是无斜率的情况
        {
            k2 = ((double)y4 - (double)y3) / (x4 - x3);
            b2 = y3 - k2 * x3;
        }
        //直线重合的两种情况，一是两条直线k和b都一样，二是两条直线都无斜率并且两条直线的x一样（x1等于x3）
        if((k1 == k2 && b1 == b2) || (x1 == x2 && x3 == x4 && x1 == x3))
        {
            printf("LINE\n");
            continue;
        }
        //直线不相交也不重合就是平行，平行的两种情况，一是斜率相同，二是直线都无斜率但是两条直线的x不一样（x1不等于x3）
        if(k1 == k2 || (x1 == x2 && x3 == x4))
        {
            printf("NONE\n");
            continue;
        }
        printf("POINT ");
        //两条直线有交点的情况之一就是一条是垂直于x轴，一条垂直于y轴
        if((x1 == x2 && y3 == y4))
        {
            printf("%d.00 %d.00\n",x1,y3);
            continue;
        }
        if((y1 == y2 && x3 == x4))
        {
            printf("%d.00 %d.00\n",x3,y1);
            continue;
        }
        //另一种情况是既不重合也不想交也不满足两条直线分别垂直于x，y轴或y，x轴（就是上一种的直线相交的条件）
        y = (b1 * k2 - b2 * k1) / (k2 - k1);
        x = (k2 * y - b1 * k2) / (k1 * k2);
        printf("%0.2f %0.2f\n",x,y);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
