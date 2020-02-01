#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,xs,ys,xe,ye,xl,yl,xr,yr,temp;
    double k,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d %d %d %d %d",&xs,&ys,&xe,&ye,&xl,&yl,&xr,&yr);
        if(xl > xr)//矩形的坐标给出的顺序不一定是先给左上再给右下，需要自己判断
        {
            temp = xl;
            xl = xr;
            xr = temp;
        }
        if(yl < yr)
        {
            temp = yl;
            yl = yr;
            yr = temp;
        }
        if(xs > xe)//个人规定线段起点是x坐标小的那个点
        {
            temp = xs;
            xs = xe;
            xe = temp;
            temp = ys;
            ys = ye;
            ye = temp;
        }
        if((xs >= xl && xs <= xr) && (xe >= xl && xe <= xr) && (ys <= yl && ys >= yr) && (ye <= yl && ye >= yr))//线段在矩形的内部
        {
            printf("T\n");
            continue;
        }
        if(xs == xe && (xs >= xl && xs <= xr))//线段垂直于x轴与矩形下边相交
        {
            if(ys > ye && (ye <= yr && ys >= yr))
            {
                printf("T\n");
                continue;
            }
            if(ys < ye && (ys <= yr && ye >= yr))
            {
                printf("T\n");
                continue;
            }
        }
        if(xs == xe && (xs >= xl && xs <= xr))//线段垂直于x轴与矩形上边相交
        {
            if(ys > ye  && (ys >= yl && ys <= yl))
            {
                printf("T\n");
                continue;
            }
            if(ys < ye && (ye >= yl && ye <= yl))
            {
                printf("T\n");
                continue;
            }
        }
        if(ys == ye && (ys >= yr && ys <= yl))//线段垂直于y轴与矩形左边相交
        {
            if(xs <= xl && xe >= xl)
            {
                printf("T\n");
                continue;
            }
        }
        if(ys == ye && (ys >= yr && ys <= yl))//线段垂直于y轴与矩形右边相交
        {
            if(xs <= xr && xe >= xl)
            {
                printf("T\n");
                continue;
            }
        }
        if(xs != xe && ys != ye)
        {
            k = ((double)ye - (double)ys) / (xe - xs);//所给线段的斜率
            b = ys - k * xs;//直线公式y = k * x + b中的b
            if(((k * xl + b) >= yr && (k * xl + b) <= yl) && (xs <= xl && xe >= xl))//线段与左边相交
            {
                printf("T\n");
                continue;
            }
            if(((k * xr + b) >= yr && (k * xr + b) <= yl) && (xs <= xr && xe >= xr))//线段与右边相交
            {
                printf("T\n");
                continue;
            }
            if((((yl - b) / k) >= xl && ((yl - b) / k) <= xr) && ((ys <= yl && ye >= yl) || (ye <= yl && ys >= yl)))//线段与上边相交
            {
                printf("T\n");
                continue;
            }
            if((((yr - b) / k) >= xl && ((yr - b) / k) <= xr) && ((ys <= yr && ye >= yr) || (ye <= yr && ys >= yr)))//线段与下边相交
            {
                printf("T\n");
                continue;
            }
        }
        printf("F\n");
    }
    return 0;
}
