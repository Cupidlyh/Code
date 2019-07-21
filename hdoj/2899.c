#include <stdio.h>
#include <stdlib.h>
double x,y;

double f(double x)
{
    return 6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-y*x;
}

double solve(double l,double r)
{
    double eps=1e-7;
    while(l+eps<r)
    {
        double lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        if(f(lmid)<f(rmid))
            r=rmid;
        else
            l=lmid;
    }
    return f(l);
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lf",&y);
        printf("%.4lf\n",solve(0,100.0));
    }
    return 0;
}
